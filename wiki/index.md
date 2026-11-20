# C++ 入門 Wiki — Index

> 主題：C++ 入門——變數、if-else、迴圈。給從沒寫過程式的大學生。規則見 [CLAUDE.md](../CLAUDE.md)，紀錄見 [log.md](log.md)。
> 狀態欄：⬜ 未建立 ｜ 🟨 草稿（來源不足）｜ ✅ 完成

## 概念頁（建議閱讀順序）
| # | 頁面 | 一句話摘要 | 主要來源 | 狀態 |
|---|---|---|---|---|
| 1 | [程式骨架](concepts/program-structure.md) | 程式由敘述組成、從 main 開始執行；編譯→連結→執行；std::cout 與換行；註解；語法錯誤 vs 語意錯誤 | 01 | ✅ |
| 2 | [變數與型別](concepts/variables-and-types.md) | 變數＝有名字的記憶體；`int`／`double`／`bool`／`char`；初始化 vs 賦值；一律初始化；`=` vs `{}`；命名規則；`std::cin` | 01, 02, 03 | ✅ |
| 3 | [運算子](concepts/operators.md) | 運算式；算術與整數除法；優先順序；`+=`／`++`；`%`；比較；邏輯 | 02, 03, 04 | ✅ |
| 4 | [if-else](concepts/if-else.md) | if／if-else／else if；區塊與大括號；用邏輯運算子組合條件；巢狀 if | 04, 05 | ✅ |
| 5 | [while 迴圈](concepts/while-loop.md) | 條件成立就重複；更新迴圈變數；條件一開始就不成立；無窮迴圈 | 05, 06 | ✅ |
| 6 | [for 迴圈](concepts/for-loop.md) | 初始化;條件;更新 的執行順序；和 while 的對應；倒數／跳號；1 加到 100；九九乘法表；差一錯誤 | 03, 04, 06 | ✅ |
| 7 | [break 與 continue](concepts/break-continue.md) | break 結束迴圈、continue 跳過這一輪；`while (true)` + break；while 裡的 continue 陷阱 | 01, 06 | ✅ |
| 8 | [新手常見錯誤](concepts/common-mistakes.md) | 17 條：錯誤寫法 + g++ 真實訊息／實際輸出 + 修正（標出哪幾條編譯器不會警告） | 01–06 | ✅ |

## 來源頁
| # | 頁面 | 收錄 learncpp lesson | 擷取日期 | 狀態 |
|---|---|---|---|---|
| 01 | [程式骨架](sources/01-learncpp-program-structure.md) | 0.4、0.5、0.7、0.8、1.1、1.2、1.5、3.1 | 2026-11-20（摘錄筆記） | ✅ |
| 02 | [變數](sources/02-learncpp-variables.md) | 1.3、1.4、1.6、1.7 | 2026-11-20（摘錄筆記） | ✅ |
| 03 | [基本型別](sources/03-learncpp-fundamental-types.md) | 4.1、4.4、4.8、4.9、4.11、4.12 | 2026-11-20（摘錄筆記） | ✅ |
| 04 | [運算子](sources/04-learncpp-operators.md) | 1.9、1.10、6.1、6.2、6.3、6.4、6.7、6.8 | 2026-11-20（摘錄筆記） | ✅ |
| 05 | [if-else](sources/05-learncpp-if-else.md) | 4.10、7.1、8.1、8.2、8.3 | 2026-11-20（摘錄筆記） | ✅ |
| 06 | [迴圈](sources/06-learncpp-loops.md) | 8.8、8.10、8.11（8.9 延伸閱讀） | 2026-11-20（摘錄筆記） | ✅ |

## 範例程式
> 標記：❌ 編譯失敗示範（附 .err）｜⚠️ warning 示範（附 .err）｜🔁 無窮迴圈示範｜🔇 有問題但 g++ **不會警告**
> 檢查：`bash check-examples.sh`（編譯、執行、比對輸出）、`bash check-wiki-code.sh`（頁面內容和檔案是否一字不差）

| 檔案 | 示範什麼 | 被哪些頁面引用 |
|---|---|---|
| [10-hello-world.cpp](../examples/10-hello-world.cpp) | 最小的程式 | program-structure |
| [11-cout-chain.cpp](../examples/11-cout-chain.cpp) | 串接 `<<`、用 `'\n'` 換行 | program-structure、common-mistakes |
| [12-comments.cpp](../examples/12-comments.cpp) | 單行／多行註解、註解掉程式碼 | program-structure |
| [13-semantic-error.cpp](../examples/13-semantic-error.cpp) | 語意錯誤：能編譯，但少了換行 | program-structure |
| [20-init-and-assign.cpp](../examples/20-init-and-assign.cpp) | 初始化 vs 賦值 | variables-and-types |
| [21-cin-input.cpp](../examples/21-cin-input.cpp) | `std::cin` 讀一個整數（附 .in） | variables-and-types |
| [22-cin-two-numbers.cpp](../examples/22-cin-two-numbers.cpp) | 一次讀兩個值（附 .in） | variables-and-types |
| [23-copy-init-truncate.cpp](../examples/23-copy-init-truncate.cpp) | 🔇 `int w = 4.5;` 默默變成 4 | variables-and-types |
| [24-brace-narrowing.cpp](../examples/24-brace-narrowing.cpp) | ❌ 大括號擋下縮窄轉換 | variables-and-types |
| [25-double.cpp](../examples/25-double.cpp) | `double` 的輸出：`5.0` 印成 `5`、科學記號 | variables-and-types |
| [26-bool.cpp](../examples/26-bool.cpp) | `bool` 印成 1/0，加 `std::boolalpha` 印成 true/false | variables-and-types |
| [27-char.cpp](../examples/27-char.cpp) | `char` 用單引號；`'5'` 不是整數 5 | variables-and-types |
| [30-arithmetic.cpp](../examples/30-arithmetic.cpp) | 五個算術運算子 | operators |
| [31-integer-division.cpp](../examples/31-integer-division.cpp) | 整數除法 vs `static_cast<double>` | operators |
| [32-precedence.cpp](../examples/32-precedence.cpp) | 先乘除後加減、括號、由左到右 | operators |
| [33-compound-increment.cpp](../examples/33-compound-increment.cpp) | `+=`、`-=`、`++x`、`--x` | operators |
| [34-remainder.cpp](../examples/34-remainder.cpp) | `%`：整除判斷、負數 | operators |
| [35-relational.cpp](../examples/35-relational.cpp) | 比較運算子的結果是 bool | operators |
| [36-logical.cpp](../examples/36-logical.cpp) | `&&`、`\|\|`、`!` | operators |
| [37-quiz-average.cpp](../examples/37-quiz-average.cpp) | 小測驗：`7 / 2` 存進 double（沒有註解，避免洩漏答案） | operators（簡報第 16 張） |
| [40-if.cpp](../examples/40-if.cpp) | if（附 .in） | if-else |
| [41-if-else.cpp](../examples/41-if-else.cpp) | if-else 二選一（附 .in） | if-else |
| [42-else-if.cpp](../examples/42-else-if.cpp) | else if 多選一（附 .in） | if-else |
| [43-block.cpp](../examples/43-block.cpp) | 區塊：一次控制多個敘述（附 .in） | if-else |
| [44-logical-condition.cpp](../examples/44-logical-condition.cpp) | 用 `&&` 組合條件（附 .in） | if-else |
| [45-nested-if.cpp](../examples/45-nested-if.cpp) | 巢狀 if，else 屬於哪個 if | if-else |
| [50-while-count.cpp](../examples/50-while-count.cpp) | while 印 1 到 10 | while-loop、for-loop |
| [51-while-false-start.cpp](../examples/51-while-false-start.cpp) | 條件一開始就不成立 → 一次都不執行 | while-loop |
| [52-while-user-count.cpp](../examples/52-while-user-count.cpp) | 次數由使用者決定（附 .in） | while-loop |
| [53-quiz-while.cpp](../examples/53-quiz-while.cpp) | 小測驗：條件一開始就不成立（沒有註解，避免洩漏答案） | while-loop（簡報第 15 張） |
| [60-for-count.cpp](../examples/60-for-count.cpp) | for 印 1 到 10 | for-loop |
| [61-for-step.cpp](../examples/61-for-step.cpp) | 倒數、一次加 2 | for-loop |
| [62-nested-for.cpp](../examples/62-nested-for.cpp) | 巢狀 for：九九乘法表 | for-loop |
| [63-sum-1-to-100.cpp](../examples/63-sum-1-to-100.cpp) | 1 加到 100 = 5050 | for-loop |
| [70-break-sum.cpp](../examples/70-break-sum.cpp) | `while (true)` + break：輸入 0 就停（附 .in） | break-continue |
| [71-continue.cpp](../examples/71-continue.cpp) | continue 跳過 4 的倍數 | break-continue |
| [80-missing-semicolon.cpp](../examples/80-missing-semicolon.cpp) | ❌ 漏分號 | common-mistakes |
| [81-missing-std.cpp](../examples/81-missing-std.cpp) | ❌ 漏 `std::` | common-mistakes |
| [82-slash-n.cpp](../examples/82-slash-n.cpp) | ⚠️ `'/n'` 印出 12142 | common-mistakes |
| [83-uninitialized.cpp](../examples/83-uninitialized.cpp) | ⚠️ 未初始化（未定義行為） | common-mistakes |
| [84-digit-identifier.cpp](../examples/84-digit-identifier.cpp) | ❌ 識別字用數字開頭 | common-mistakes |
| [85-char-double-quotes.cpp](../examples/85-char-double-quotes.cpp) | ❌ 字元用了雙引號 | common-mistakes |
| [86-int-division-to-double.cpp](../examples/86-int-division-to-double.cpp) | 🔇 `double average = 7 / 2;` 得到 3 | common-mistakes |
| [87-float-equality.cpp](../examples/87-float-equality.cpp) | 🔇 `0.3 == 0.2 + 0.1` 是 false | common-mistakes |
| [88-caret-power.cpp](../examples/88-caret-power.cpp) | ⚠️ `2 ^ 3` 不是次方 | common-mistakes |
| [89-assign-in-if.cpp](../examples/89-assign-in-if.cpp) | ⚠️ `if (x = 0)`（附 .in） | common-mistakes |
| [90-if-semicolon.cpp](../examples/90-if-semicolon.cpp) | ⚠️ if 後面多分號 | common-mistakes |
| [91-missing-braces.cpp](../examples/91-missing-braces.cpp) | ⚠️ 沒加大括號，"Too bad!" 一定印出 | common-mistakes |
| [92-or-shortcut.cpp](../examples/92-or-shortcut.cpp) | 🔇 `value == 0 \|\| 1` 永遠成立 | common-mistakes |
| [93-infinite-loop.cpp](../examples/93-infinite-loop.cpp) | 🔁🔇 忘了 `++count` | common-mistakes |
| [94-while-semicolon.cpp](../examples/94-while-semicolon.cpp) | 🔁⚠️ while 後面多分號 | common-mistakes |
| [95-off-by-one.cpp](../examples/95-off-by-one.cpp) | 🔇 `i < 5` 少一輪 | common-mistakes |
| [96-continue-skips-update.cpp](../examples/96-continue-skips-update.cpp) | 🔁🔇 while 裡的 continue 跳過 `++count` | common-mistakes |
