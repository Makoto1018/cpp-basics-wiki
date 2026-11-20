#!/usr/bin/env bash
# 編譯並執行 examples/ 下所有 .cpp，比對輸出與 .out 檔。
#   bash check-examples.sh            檢查模式：任何一項不符 → ❌，結束碼非 0
#   bash check-examples.sh --update   產生/覆寫 .out（只在你確認程式正確後使用）
#   bash check-examples.sh 03-xxx.cpp 只檢查指定檔案（可多個，可加 --update）
#
# 規則（詳見 CLAUDE.md「程式碼規則」）：
#   - 第 1 行必須是出處註解：// 出處：…
#   - 不含出處與示範標記，最多 15 行
#   - 前 5 行可放「示範標記」：
#       // 示範：warning        必須有 warning（仍需能編譯、輸出相符）；--update 時把警告存成 .err
#       // 示範：編譯失敗        必須「編譯失敗」才算通過；--update 時把錯誤訊息存成 .err
#       // 示範：未定義行為      只檢查能編譯，不比對輸出（每次結果可能不同）
#       // 示範：無窮迴圈        必須停不下來（2 秒後強制結束才算通過）；.out 只存前 200 bytes
#   - 若有 <同名>.in，會當作標準輸入餵給程式。
#   - 每個程式最多跑 5 秒（防止無窮迴圈範例卡住）。

cd "$(dirname "$0")/examples" || exit 1
CXX="${CXX:-g++}"
CXXFLAGS=(-std=c++17 -Wall -Wextra -pedantic-errors)

UPDATE=0; files=()
for arg in "$@"; do
    if [ "$arg" = "--update" ]; then UPDATE=1; else files+=("${arg##*/}"); fi
done
shopt -s nullglob
[ ${#files[@]} -eq 0 ] && files=(*.cpp)

pass=0; fail=0
tmpbin="$(mktemp -u)_ex"

ok()  { echo "✅ $1"; pass=$((pass+1)); }
bad() { echo "❌ $1"; fail=$((fail+1)); }

for src in "${files[@]}"; do
    name="${src%.cpp}"
    [ -f "$src" ] || { bad "$src 不存在"; continue; }
    header="$(head -5 "$src")"

    # 1. 出處註解
    if ! head -1 "$src" | grep -q '^// 出處：'; then
        bad "$src 第 1 行缺少「// 出處：…」"; continue
    fi
    lines=$(grep -v -c '^// 出處：\|^// 示範：' "$src")
    if [ "$lines" -gt 15 ]; then
        bad "$src 有 $lines 行（不含出處與示範標記），超過 15 行上限"; continue
    fi

    # 2. 編譯
    "$CXX" "${CXXFLAGS[@]}" "$src" -o "$tmpbin" 2>"$name.compile.log"
    compiled=$?
    log="$(tr -d '\r' < "$name.compile.log")"

    if grep -q '// 示範：編譯失敗' <<<"$header"; then
        if [ $compiled -eq 0 ]; then
            bad "$src 標記為「示範：編譯失敗」，但編譯成功了"
        else
            [ $UPDATE -eq 1 ] && printf '%s\n' "$log" | sed "s#^[^ ]*$src#$src#" > "$name.err"
            ok "$src（如預期編譯失敗）"
        fi
        rm -f "$name.compile.log"; continue
    fi
    if [ $compiled -ne 0 ]; then
        bad "$src 編譯失敗（見 examples/$name.compile.log）"; continue
    fi
    if [ -n "$log" ] && ! grep -q '// 示範：warning' <<<"$header"; then
        bad "$src 有 warning（見 examples/$name.compile.log）"; continue
    fi
    if [ -z "$log" ] && grep -q '// 示範：warning' <<<"$header"; then
        bad "$src 標記為「示範：warning」，但編譯時沒有任何 warning"; rm -f "$name.compile.log"; continue
    fi
    if [ $UPDATE -eq 1 ] && [ -n "$log" ]; then    # 示範：warning → 存下真實的警告訊息
        printf '%s\n' "$log" | sed "s#^[^ ]*$src#$src#" > "$name.err"
    fi
    rm -f "$name.compile.log"

    # 3. 執行（去掉 Windows 的 \r，讓 .out 在各平台一致）
    input=/dev/null; [ -f "$name.in" ] && input="$name.in"
    if grep -q '// 示範：無窮迴圈' <<<"$header"; then
        # 必須停不下來：跑 2 秒後強制結束，只保留前 200 bytes 的輸出
        # （124 = 被 timeout 中止；141 = 輸出管線關閉時被 SIGPIPE 中止，Linux 上可能發生）
        timeout 2 "$tmpbin" < "$input" 2>/dev/null | head -c 200 > "$tmpbin.stdout"; rc=${PIPESTATUS[0]}
        if [ "$rc" -ne 124 ] && [ "$rc" -ne 141 ]; then
            bad "$src 標記為「示範：無窮迴圈」，但程式自己結束了"; continue
        fi
    else
        timeout 5 "$tmpbin" < "$input" > "$tmpbin.stdout"; rc=$?
        if [ "$rc" -eq 124 ]; then bad "$src 執行超過 5 秒（無窮迴圈？）"; continue; fi
    fi
    actual="$(tr -d '\r' < "$tmpbin.stdout")"

    if grep -q '// 示範：未定義行為' <<<"$header"; then
        ok "$src（未定義行為示範：只檢查編譯）"; continue
    fi

    # 4. 比對輸出
    if [ $UPDATE -eq 1 ]; then
        printf '%s\n' "$actual" > "$name.out"; echo "📝 $src → $name.out"; pass=$((pass+1))
    elif [ ! -f "$name.out" ]; then
        bad "$src 沒有 $name.out（先確認程式正確，再跑 --update）"
    elif [ "$actual" = "$(tr -d '\r' < "$name.out")" ]; then
        ok "$src"
    else
        bad "$src 輸出與 $name.out 不符"
        diff <(tr -d '\r' < "$name.out") <(printf '%s\n' "$actual") | sed 's/^/     /'
    fi
done
rm -f "$tmpbin" "$tmpbin.exe" "$tmpbin.stdout"
echo "---- 通過 $pass，失敗 $fail"
[ $fail -eq 0 ]
