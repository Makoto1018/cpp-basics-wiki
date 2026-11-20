# LLM Wiki Schema：C++ 入門（變數、if-else、迴圈）

這份檔案是 Wiki 的規則。任何 LLM 在讀寫本 Wiki 前都必須先讀完並遵守。

## 目標讀者
從沒寫過程式的大學生。先講直覺（生活比喻）再講語法，先給能跑的小程式再講細節。

## 範圍
| 包含 | 不包含（遇到就標「範圍外」，不要展開） |
|---|---|
| 程式骨架：`#include`、`main()`、`std::cout`、`std::cin`、`std::boolalpha`（把 bool 印成 true/false）、註解、編譯→執行 | 自訂函式、多檔案、header、namespace、陣列、`std::vector`、`std::string` 操作 |
| 變數與基本型別：`int`、`double`、`char`、`bool`、初始化、賦值、未初始化的危險 | 指標、參考、類別、`const`/`constexpr`/`auto`、unsigned、fixed-width 整數 |
| 運算子：算術（含 `/`、`%`）、比較、邏輯、`++`/`--`、`+=`；`static_cast<double>` 只用於修正整數除法 | 位元運算、完整優先順序表、逗號運算子、副作用的深入解釋 |
| `if` / `else if` / `else`、巢狀 if、區塊 `{}` | `switch`、`goto`、`constexpr if`、三元運算子（只放延伸閱讀） |
| `while`、`for`、`break`、`continue` | `do-while`、range-for、亂數（只放延伸閱讀） |
| 新手常見錯誤、語法錯誤 vs 語意錯誤 | 未定義行為的深入解釋、偵錯器操作 |

## 來源
唯一來源網站是 learncpp.com。依概念把 lesson 分組，**每組一個 raw 檔**（檔名＝來源頁檔名）。

| # | raw / sources 檔名 | 收錄 lesson | 主要對應概念頁 |
|---|---|---|---|
| 01 | `01-learncpp-program-structure.md` | 0.4、0.5、0.7、0.8、1.1、1.2、1.5、3.1 | program-structure |
| 02 | `02-learncpp-variables.md` | 1.3、1.4、1.6、1.7 | variables-and-types |
| 03 | `03-learncpp-fundamental-types.md` | 4.1、4.4、4.8、4.9、4.11、4.12 | variables-and-types、operators |
| 04 | `04-learncpp-operators.md` | 1.9、1.10、6.1、6.2、6.3、6.4、6.7、6.8 | operators |
| 05 | `05-learncpp-if-else.md` | 4.10、7.1、8.1、8.2、8.3 | if-else |
| 06 | `06-learncpp-loops.md` | 8.8、8.10、8.11（8.9 do-while 只當延伸閱讀） | while-loop、for-loop、break-continue |

- raw 檔開頭的 frontmatter 要列出：每個 lesson 的編號、標題、網址，以及擷取日期。
- 正文用 `## 1.4 Variable assignment and initialization` 這種格式分段，lesson 編號必須和原站一致。
- 要新增 lesson 或新來源時，先在 `log.md` 記錄理由，再更新上表。
- **已知缺口**（learncpp 幾乎沒講，wiki 不得自行補寫，只能標 `⚠️ 待查證`，或之後找新來源 ingest）：手動追蹤表（trace table）、迴圈慣用寫法（計數器／累加器／哨兵值）、編譯錯誤訊息導讀。

## 目錄
- `raw/`：原始資料，**唯讀，不可修改**。
- `wiki/sources/`：每篇 raw 一頁摘要，檔名與 raw 相同。重點要依 lesson 分段，標出 lesson 編號。
- `wiki/concepts/`：概念頁，整合多篇來源。
- `wiki/index.md`：所有頁面清單 + 一句話摘要 + 建議閱讀順序 + 範例程式清單。
- `wiki/log.md`：時間序紀錄，**只能往後追加**。
- `examples/`：所有程式碼範例（見「程式碼規則」）。
- `check-examples.sh`：編譯驗證腳本。

## 概念頁清單（依建議閱讀順序）
| # | 檔名 | 主題 | 範例編號區段 | 先備概念 |
|---|---|---|---|---|
| 1 | `program-structure.md` | `#include`、`main()`、`std::cout`、分號、註解、編譯→執行、語法錯誤 vs 語意錯誤 | 10–19 | — |
| 2 | `variables-and-types.md` | 宣告、初始化、賦值、`std::cin` 讀入變數、四種基本型別、未初始化 | 20–29 | 1 |
| 3 | `operators.md` | 算術、整數除法、`%`、比較、邏輯、`++`、`+=` | 30–39 | 2 |
| 4 | `if-else.md` | `if` / `else if` / `else`、條件、區塊與大括號、巢狀 | 40–49 | 3 |
| 5 | `while-loop.md` | 條件迴圈、更新變數、無窮迴圈 | 50–59 | 4 |
| 6 | `for-loop.md` | 初始化;條件;更新、計數迴圈、與 while 的對應、差一錯誤 | 60–69 | 5 |
| 7 | `break-continue.md` | 提早離開、跳過一輪 | 70–79 | 5、6 |
| 8 | `common-mistakes.md` | 新手常見錯誤彙整（每條連回所屬概念頁） | 80–99 | 全部 |

- 新增或刪除概念頁前，要先在 `log.md` 記錄理由。
- **先教後用**：範例和說明只能使用「先備概念」已經教過的語法。例如 `while-loop.md` 的範例不能用 `++`，除非 `operators.md` 已經教過。

## 概念頁格式
```
# <概念名>
**一句話定義**：…
**先備概念**：[xxx](xxx.md)
## 白話解釋          ← 先比喻，再講語法
## 語法
## 範例              ← 範例檔：examples/xx-name.cpp ＋ 程式碼 ＋ 實際輸出（複製自 .out）
## 常見誤解          ← ❌ 錯誤寫法（可附 .err 的真實錯誤訊息）→ ✅ 正確寫法
## 相關概念          ← [其他概念頁](xxx.md)
## 出處              ← [02 §1.4] 格式：來源編號 + lesson 編號，連到 sources/ 頁
```
- 內文引用寫成 `[02 §1.4]`，代表 `sources/02-learncpp-variables.md` 裡的 lesson 1.4。
- 例外：`common-mistakes.md` 是彙整頁，每一條的格式為：所屬概念 → 說明（附出處）→ ❌ 範例檔 → 實際輸出／g++ 訊息 → 怎麼讀 → ✅ 修正。不套用上面的概念頁格式。

## 程式碼規則
1. **單一事實來源**：wiki 與簡報出現的每一段完整程式，都必須存成 `examples/<兩位數編號>-<英文名稱>.cpp`。編號依照概念頁的區段，例如 `32-integer-division.cpp`。概念頁要註明 `範例檔：examples/xx-name.cpp`，貼上的程式碼必須和檔案**一字不差**，不可在頁面上另外手打或修改。
2. **出處註解**：每個 `.cpp` 第 1 行必須是出處，三擇一：
   - `// 出處：learncpp 1.4（原文）→ sources/02-learncpp-variables.md`：照抄原站程式碼，**限 10 行以內**（尊重版權）。
   - `// 出處：learncpp 1.4（改寫）→ sources/02-learncpp-variables.md`：改寫自原站範例。
   - `// 出處：自編示意例（語法依據 sources/02-learncpp-variables.md §1.4）`：自己寫的程式，但用到的語法規則本身仍要有出處。
3. **示範標記**（放在前 5 行，腳本會讀）：
   - `// 示範：編譯失敗`：故意寫錯的程式，**必須**編譯失敗才算通過。`--update` 時會把 g++ 的錯誤訊息存成 `.err`，概念頁引用錯誤訊息時只能貼 `.err` 的內容。
   - `// 示範：warning`：允許編譯時有 warning。
   - `// 示範：未定義行為`：只檢查能不能編譯，不比對輸出。
   - `// 示範：無窮迴圈`：程式**必須停不下來**，2 秒後被強制中止才算通過；`.out` 只保留前 200 bytes。
   - 標了 `示範：warning` 卻沒有 warning，也算失敗。
4. **實際輸出**：每個 `.cpp` 旁放 `<同名>.out`，由 `bash check-examples.sh --update` **實際執行後產生**，LLM 不可推測或手寫。程式需要輸入時，另放 `<同名>.in`，概念頁要同時列出輸入和輸出。
5. **編譯驗證**：
   - 編譯指令固定為 `g++ -std=c++17 -Wall -Wextra -pedantic-errors`（MinGW g++ 15.2）。
   - 除了有示範標記的範例，不可有任何 warning。
   - 每個程式最多執行 5 秒。
   - 新增或修改任何 `.cpp` 後都要執行 `bash check-examples.sh <檔名>`；lint 和簡報產生前要執行一次完整的 `bash check-examples.sh`。全部 ✅ 才算通過，結果記進 `log.md`。
   - 頁面寫完後執行 `bash check-wiki-code.sh <頁面>`，確認頁面上的程式碼、輸出、錯誤訊息和 `examples/` 一字不差。為了讓工具能比對，頁面要照這個格式寫：
     - `範例檔：examples/X.cpp`，下一個區塊是 ` ```cpp `
     - `實際輸出：`，下一個區塊是 ` ```text `
     - 有 `.err` 時寫 `` g++ 的錯誤訊息（`examples/X.err`）： ``，下一個區塊是 ` ```text `
6. **程式風格**（全站統一）：
   - 使用 `std::cout`，**不用** `using namespace std;`
   - 初始化寫 `int x = 5;`。learncpp 推薦大括號初始化 `int x{5};`，這點依引用規則 3 在 `variables-and-types.md` 標 ⚔️ 說明，其餘頁面不使用。
   - 換行用 `'\n'`；縮排 4 個空白；`if`／迴圈主體**一律加大括號**；`main` 結尾寫 `return 0;`
   - 大括號位置：`main` 的 `{` 換到下一行；`if`、`else`、迴圈的 `{` 和關鍵字寫在同一行（`} else {`），以符合 15 行的限制。
   - 唯一的例外：if 的主體只有一個 `break` 或 `continue`，而且不寫成一行就會超過 15 行時，可以寫成 `if (…) { break; }`（大括號仍然要加）。
   - 「示範：warning／編譯失敗」的範例，為了重現錯誤，可以違反上面的風格（例如故意不加大括號）。
   - 每個範例 ≤ 15 行（不含出處與示範標記），因為簡報要放得下。`check-examples.sh` 會檢查。
   - 只能有 `main` 一個函式。
   - 程式**印出的文字用英文（ASCII）**，中文只放在註解裡。這是預防措施：Windows 主控台可能把 UTF-8 中文顯示成亂碼，學生照著跑會以為程式錯了（尚未實測）。

## 引用規則
1. 每個事實句子必須能追溯到 `wiki/sources/` 的某一頁，並標出 lesson 編號（`[02 §1.4]`）。
2. 找不到出處的內容寫成 `> ⚠️ 待查證：…`，不可當成事實。**LLM 不可用自己的 C++ 知識補內容**，即使它確定是對的。
3. learncpp 的建議和本 wiki 的選擇不同時（例如初始化寫法），或 learncpp 不同 lesson 的說法有落差時，兩種都寫，並標註 `> ⚔️ 衝突：…`，再說明本 wiki 採用哪一個、為什麼。
4. 程式的輸出結果以 `.out` 為準、錯誤訊息以 `.err` 為準，這兩者不需要文字出處；但「為什麼是這個結果」的解釋需要出處。
5. 解說 g++ 訊息（「怎麼讀」）時：**逐字翻譯**訊息內容，或描述訊息上看得到的標記（行號、`^~` 指的位置），不需要出處，依據就是 `.err`；**超出翻譯的解釋**（某個術語的意思、為什麼會這樣、照建議做會怎樣）需要出處，否則標 `⚠️ 待查證`。（lint 2026-11-20 新增）

## 術語表（全站統一）
第一次出現時寫成「中文（English）」，之後只寫中文。

| 統一用語 | 不要用 | 備註 |
|---|---|---|
| 敘述（statement） | 語句、陳述式 | |
| 運算式（expression） | 表達式 | `x = 5;` 稱為「運算式敘述」 |
| 定義（definition）／宣告（declaration） | 聲明 | `int x;` 照 learncpp 的用語叫「定義」，正文一律用「定義」；「宣告」只用在翻譯 g++ 訊息裡的 `declared`（lint 2026-11-20 修訂） |
| 初始化（initialization） | 初始值設定 | 和「賦值」嚴格區分 |
| 賦值（assignment） | 指定、指派 | |
| 變數（variable） | 變量 | 概念頁中，learncpp 的 object 一律譯為「變數」，不用「物件」（避免和類別混淆）。例外：在 sources 頁說明 learncpp 對 object 和 variable 的區分時，可以用「物件」 |
| 型別（type） | 類型、數據類型、資料型態 | |
| 字面值（literal） | 字面常數、常量 | |
| 運算子／運算元（operator / operand） | 操作符、算子、操作數 | |
| 識別字／關鍵字（identifier / keyword） | 標識符 | |
| 區塊（block） | 塊、程式塊 | |
| 條件（condition） | 判斷式 | |
| 布林（bool / Boolean） | 布爾 | |
| 整數／浮點數（integer / floating point） | 整型、浮點型 | |
| 字元（char / character） | 字符 | |
| 迴圈（loop）；一輪（iteration） | 循環、迭代 | |
| 巢狀（nested） | 嵌套 | |
| 遞增／遞減（increment / decrement） | 自增、自減 | |
| 優先順序（precedence） | 優先級 | |
| 無窮迴圈（infinite loop） | 死循環 | |
| 差一錯誤（off-by-one error） | | |
| 編譯／編譯器（compile / compiler） | 編譯程式 | |
| 語法錯誤／語意錯誤（syntax / semantic error） | | |
| 未定義行為（undefined behavior） | | |
| 輸出／輸入（`std::cout` / `std::cin`） | 打印、列印 | |
| 函式（function） | 函數 | 只在介紹 `main` 時用 |
| 標準函式庫（standard library） | 標準庫 | |

## 操作流程
### Ingest（一次一篇）
1. 讀 raw 檔，列出 3–5 個重點（標 lesson 編號）、預計更新的頁面、預計新增的 `examples/*.cpp`，**等使用者確認**。
2. 寫 `sources/<同名>.md`。
3. 更新或新增相關 `concepts/` 頁；與既有內容衝突時依引用規則 3 標註。
4. 寫 `examples/*.cpp`（含出處註解），**不要寫 `.out` / `.err`**。
5. 執行 `bash check-examples.sh <新檔案>` 確認能編譯，向使用者說明程式的用意。使用者確認後，再執行 `bash check-examples.sh --update <新檔案>` 產生 `.out` / `.err`，然後把**檔案內容**貼進概念頁。
6. 更新 `index.md`；在 `log.md` 追加一筆 `## [日期 時間] ingest | <標題>`，內容包含編譯檢查結果（通過幾個、失敗幾個、怎麼修）。

### Query
1. 先讀 `index.md` 找相關頁面，再讀頁面。
2. 只用 wiki 內容回答，每個重點附頁面路徑；程式碼只能引用 `examples/` 裡的檔案。wiki 沒有的標 `[MISSING]`。

### Lint
先執行完整的 `bash check-examples.sh` 和 `bash check-wiki-code.sh`，再檢查以下項目，輸出問題清單，等確認後再修，並記到 `log.md`：
- 無出處的句子、出處缺少 lesson 編號、頁面間矛盾
- 孤兒頁（無人連入）、index 漏列
- 違反術語表、違反程式風格（例如出現 `using namespace std;`、`if` 沒加大括號）
- 違反「先教後用」（範例用到先備概念以外的語法）
- 概念頁引用的 `examples/` 檔案不存在、`.cpp` 沒有任何頁面引用、範例編號不在所屬概念的區段
- 概念頁貼的程式碼、輸出、錯誤訊息和 `.cpp` / `.out` / `.err` 不一致
- 超出「範圍」的內容
