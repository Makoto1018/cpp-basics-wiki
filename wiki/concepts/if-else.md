# if-else

**一句話定義**：if 敘述讓一段程式**只在條件（condition）成立時**才執行；條件是一個會算出 `true` / `false` 的運算式 [05 §4.10]。
**先備概念**：[運算子](operators.md)（比較和邏輯運算子會產生條件）

## 白話解釋
到目前為止的程式都是「直線程式」：從 `main` 的第一行一路執行到最後一行，每次都做一樣的事 [05 §8.1]。

但真實的程式需要**做選擇**，例如分數及格就印「Pass」，不及格就印「Failed」。能改變執行路徑的敘述叫做控制流程敘述；程式跳到不是下一行的地方執行，叫做**分支（branching）** [05 §8.1]。if 就是最基本的分支。

可以把 if 想成路上的**岔路**（本 wiki 的比喻）：
- 走到岔路時，先看條件。
- 條件成立就走這條路，不成立就走另一條路，或直接跳過。

## 語法

### if：條件成立才執行
```text
if (條件) {
    條件成立時要做的事
}
```
- 條件是 `true` 就執行大括號裡的敘述，`false` 就跳過 [05 §4.10]。
- 條件通常是比較運算式，例如 `x == 0`、`x > 10`；比較的結果就是 `bool` [04 §6.7]。

範例檔：examples/40-if.cpp
```cpp
// 出處：learncpp 4.10（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x = 0;
    std::cin >> x;
    if (x == 0) {
        std::cout << "The value is zero\n";
    }
    std::cout << "Done\n";
    return 0;
}
```
輸入（`examples/40-if.in`）：
```text
0
```
實際輸出：
```text
Enter an integer: The value is zero
Done
```
（輸入不是 0 時，就只會印出 `Done`。為什麼輸入沒有出現在輸出裡，見[變數與型別](variables-and-types.md)的 `std::cin` 一節。）

### if-else：二選一
- 加上 `else`，條件不成立時就改做另一件事；兩邊**剛好執行其中一個** [05 §4.10]。

範例檔：examples/41-if-else.cpp
```cpp
// 出處：learncpp 8.2（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x = 0;
    std::cin >> x;
    if (x > 10) {
        std::cout << x << " is greater than 10\n";
    } else {
        std::cout << x << " is not greater than 10\n";
    }
    return 0;
}
```
輸入（`examples/41-if-else.in`）：
```text
4
```
實際輸出：
```text
Enter a number: 4 is not greater than 10
```

### else if：多選一
- 用 `else if` 可以串接任意多個條件 [05 §4.10]。
- 程式由上往下檢查，**只執行第一個成立的分支**，後面的就不檢查了 [05 §8.2]。
- 所以條件的**順序很重要**：下面的例子先檢查 `>= 90`，再檢查 `>= 60`。

範例檔：examples/42-else-if.cpp
```cpp
// 出處：自編示意例（語法依據 sources/05-learncpp-if-else.md §4.10）
#include <iostream>

int main()
{
    int score = 0;
    std::cin >> score;
    if (score >= 90) {
        std::cout << "Grade A\n";
    } else if (score >= 60) {
        std::cout << "Pass\n";
    } else {
        std::cout << "Failed\n";
    }
    return 0;
}
```
輸入（`examples/42-else-if.in`）：
```text
85
```
實際輸出：
```text
Pass
```
（85 不符合 `>= 90`，接著檢查 `>= 60` 成立，就印出 `Pass`，最後的 `else` 不會執行。）

### 區塊 `{ }`：一次控制好幾行
- 用 `{` `}` 包起來的一組敘述叫做**區塊（block）**，編譯器會把它當成「一個敘述」；`}` 後面不用加分號 [05 §7.1]。
- **沒有大括號時，if 和 else 都只控制緊接在後面的「一個」敘述，不管縮排怎麼排** [05 §8.2]，見[常見錯誤 #12](common-mistakes.md#12-if--else-沒加大括號)。
- 在區塊裡定義的變數，離開區塊就不存在了 [05 §8.2]。

> ⚔️ 衝突：原站的範例常常省略大括號，例如 `if (x == 0) std::cout << …;`。但原站自己也建議「學習期間，單一敘述也放進區塊」[05 §8.2]，還提到社群似乎比較傾向一律加大括號 [05 §8.2]。**本 wiki 規定 if、else、迴圈的主體一律加大括號**（見 CLAUDE.md）。

範例檔：examples/43-block.cpp
```cpp
// 出處：learncpp 7.1（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    int value = 0;
    std::cin >> value;
    if (value >= 0) {
        std::cout << value << " is a positive integer (or zero)\n";
        std::cout << "Double this number is " << value * 2 << '\n';
    } else {
        std::cout << value << " is a negative integer\n";
        std::cout << "The positive of this number is " << -value << '\n';
    }
    return 0;
}
```
輸入（`examples/43-block.in`）：
```text
-4
```
實際輸出：
```text
-4 is a negative integer
The positive of this number is 4
```

### 用邏輯運算子組合條件
- 想同時檢查好幾個條件，用 `&&`（而且）或 `||`（或者）組合 [04 §6.8]、[05 §8.3]。
- 運算子的意思見[運算子](operators.md)。

範例檔：examples/44-logical-condition.cpp
```cpp
// 出處：learncpp 6.8（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int value = 0;
    std::cin >> value;
    if (value > 10 && value < 20) {
        std::cout << "Your value is between 10 and 20\n";
    } else {
        std::cout << "Your value is not between 10 and 20\n";
    }
    return 0;
}
```
輸入（`examples/44-logical-condition.in`）：
```text
15
```
實際輸出：
```text
Enter a number: Your value is between 10 and 20
```

### 巢狀 if
- if 的區塊裡面可以再放 if [05 §8.3]。
- **else 會配對同一個區塊裡、最近一個還沒配對的 if**；把內層的 if 用大括號包起來，就不會搞混 [05 §8.3]。
- 原站建議：巢狀不要超過 3 層 [05 §7.1]；很多巢狀的 if 都可以用邏輯運算子攤平，比較不容易出錯 [05 §8.3]。

範例檔：examples/45-nested-if.cpp
```cpp
// 出處：learncpp 8.3（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    int x = 25;
    if (x >= 0) {                   // 外層的 if
        if (x <= 20) {              // 內層的 if：外層成立才會檢查
            std::cout << x << " is between 0 and 20\n";
        } else {                    // 這個 else 屬於內層的 if
            std::cout << x << " is greater than 20\n";
        }
    }
    return 0;
}
```
實際輸出：
```text
25 is greater than 20
```

### 條件不是 bool 時
條件會被轉換成 `bool`：**非 0 是 `true`，0 是 `false`** [05 §4.10]。所以 `if (x)` 的意思是「如果 x 不是 0」。這個規則正是[常見錯誤 #10](common-mistakes.md#10-在條件裡用--而不是-) 和 [#13](common-mistakes.md#13-寫成-value--0--1) 的原因。

## 常見誤解
- ❌「`if (x = 0)` 是在檢查 x 是不是 0」→ `=` 是賦值，見[常見錯誤 #10](common-mistakes.md#10-在條件裡用--而不是-) [05 §8.3]。
- ❌「if 後面加分號比較整齊」→ 多一個分號，if 就結束了，見[常見錯誤 #11](common-mistakes.md#11-if-條件後面多了分號) [05 §8.3]。
- ❌「縮排對齊了就屬於 else」→ 沒有大括號時只控制一個敘述，見[常見錯誤 #12](common-mistakes.md#12-if--else-沒加大括號) [05 §8.2]。
- ❌「`value == 0 || 1` 是在檢查 0 或 1」→ 條件永遠成立，見[常見錯誤 #13](common-mistakes.md#13-寫成-value--0--1) [04 §6.8]。
- ❌「else if 的每個分支都會檢查」→ 只會執行第一個成立的分支 [05 §8.2]。

## 相關概念
[運算子](operators.md)、[while 迴圈](while-loop.md)（下一頁：把 if 變成「一直重複」）、[新手常見錯誤](common-mistakes.md)

## 出處
[04] [../sources/04-learncpp-operators.md](../sources/04-learncpp-operators.md)：§6.7、§6.8
[05] [../sources/05-learncpp-if-else.md](../sources/05-learncpp-if-else.md)：§4.10、§7.1、§8.1、§8.2、§8.3
