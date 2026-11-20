#!/usr/bin/env bash
# 檢查 wiki/ 頁面上貼的程式碼、輸出、錯誤訊息，是否和 examples/ 的檔案一字不差。
#   bash check-wiki-code.sh            檢查 wiki/ 下所有 .md
#   bash check-wiki-code.sh <檔案.md>  只檢查指定頁面
#
# 對應規則（寫頁面時要照這個格式）：
#   範例檔：examples/X.cpp     → 下一個 ```cpp 區塊  必須等於 examples/X.cpp
#   含「實際輸出」的那一行      → 下一個 ```text 區塊 必須等於上一個範例的 .out
#                                （若該行寫了 examples/Y.out，就改比 Y.out）
#   含 examples/Y.err 或 examples/Y.in 的那一行 → 下一個 ```text 區塊 必須等於該檔

root="$(cd "$(dirname "$0")" && pwd)"
cd "$root" || exit 1
[ $# -gt 0 ] && pages=("$@") || mapfile -t pages < <(find wiki -name '*.md' | sort)

tmp="$(mktemp -d)"; pass=0; fail=0
for page in "${pages[@]}"; do
    rm -f "$tmp"/*
    # 用 awk 把每個「需要比對的區塊」寫成 $tmp/N.block，並在 $tmp/list 記下「N|要比對的檔案|行號」
    tr -d '\r' < "$page" | awk -v dir="$tmp" '
        function want(f) { pending = f; pline = NR }
        /範例檔：examples\/[^ ]+\.cpp/ { match($0, /examples\/[^ ]+\.cpp/); cur = substr($0, RSTART, RLENGTH); want(cur); next }
        /examples\/[^ `]+\.(err|in)/ && !inblock { match($0, /examples\/[^ `]+\.(err|in)/); want(substr($0, RSTART, RLENGTH)); next }
        /實際輸出/ && !inblock {
            if (match($0, /examples\/[^ `]+\.out/)) want(substr($0, RSTART, RLENGTH))
            else if (cur != "") { o = cur; sub(/\.cpp$/, ".out", o); want(o) }
            next }
        /^```/ {
            if (!inblock) { inblock = 1; if (pending != "") { n++; out = dir "/" n ".block"; printf "" > out; print n "|" pending "|" pline >> (dir "/list"); pending = "" } else out = "" }
            else { inblock = 0; if (out != "") close(out); out = "" }
            next }
        inblock && out != "" { print >> out }
    '
    [ -f "$tmp/list" ] || continue
    while IFS='|' read -r n ref line; do
        if [ ! -f "$ref" ]; then echo "❌ $page:$line 引用的 $ref 不存在"; fail=$((fail+1)); continue; fi
        if diff -q <(tr -d '\r' < "$ref") "$tmp/$n.block" > /dev/null; then
            pass=$((pass+1))
        else
            echo "❌ $page:$line 和 $ref 不一致"; diff <(tr -d '\r' < "$ref") "$tmp/$n.block" | sed 's/^/     /'; fail=$((fail+1))
        fi
    done < "$tmp/list"
done
rm -rf "$tmp"
echo "---- 一致 $pass，不一致 $fail"
[ $fail -eq 0 ]
