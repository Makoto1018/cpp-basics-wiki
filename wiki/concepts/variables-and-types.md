# 變數與型別

**一句話定義**：變數（variable）是一塊**有名字**、可以存值的記憶體；型別（type）決定它能存哪一種值 [02 §1.3]。
**先備概念**：[程式骨架](program-structure.md)

## 白話解釋
程式常常需要「記住」資料，例如使用者輸入的數字、算出來的結果。直接寫在程式碼裡的值，例如 `5` 或 `"Hello"`，叫做字面值（literal）。字面值是唯讀的，不能修改，所以需要另一種東西來存會改變的資料 [02 §1.3]。

C++ 用一塊可以存值的記憶體來存資料；這塊記憶體有了名字，就是**變數** [02 §1.3]。（learncpp 把「一塊能存值的記憶體」稱為 object，本 wiki 一律稱「變數」。）

可以把變數想成一個**貼了名字標籤的盒子**（本 wiki 的比喻）：
- 盒子上的標籤是變數名稱。
- 盒子裡的東西是變數的值，同一時間只能放一個 [02 §1.4]。
- 盒子的形狀是型別：`int` 形狀的盒子只能放整數 [02 §1.3]。

型別必須在編譯時就確定，之後不能改 [02 §1.3]。

所有資料在記憶體裡都只是一串 0 和 1，**型別就是告訴編譯器要怎麼解讀它們**。你的工作是依照用途挑選適合的型別 [03 §4.1]。

## 語法

### 定義變數
`int x;` 是一個定義敘述：告訴編譯器「我要一個叫 `x`、型別是 `int` 的變數」[02 §1.3]。目前先把變數都定義在 `main()` 裡面 [02 §1.3]。

### 四種基本型別
| 型別 | 存什麼 | 例子 | 出處 |
|---|---|---|---|
| `int` | 整數（正、負、0） | `int count = 10;` | [03 §4.4] |
| `double` | 有小數的數字 | `double price = 5.0;` | [03 §4.8] |
| `bool` | 真假：只有 `true` 和 `false` | `bool isRaining = true;` | [03 §4.9] |
| `char` | 一個字元，用**單引號** | `char grade = 'A';` | [03 §4.11] |

**`int`**
- 在現代電腦上通常是 32 位元，範圍大約是 ±21 億（-2,147,483,648 到 2,147,483,647）[03 §4.4]。
- 整數相除的結果還是整數，小數會被丟掉，見[運算子](operators.md) [03 §4.4]。

**`double`** [03 §4.8]
- 寫成 `5.0` 這樣有小數點的值就是浮點數，即使小數部分是 0。
- 原站建議用 `double`，不要用 `float`，因為 `float` 不夠精確。
- `std::cout` 有兩個要注意的行為：
  - 小數部分是 0 時不會印出 `.0`。
  - 預設只顯示 6 位有效數字，很大的數可能用科學記號印出，例如下面的 `9.87654e+06`。
  
  > ⚠️ 待查證：`e+06` 的讀法。科學記號在 learncpp 4.7，本 wiki 沒有收錄。

範例檔：examples/25-double.cpp
```cpp
// 出處：learncpp 4.8（改寫）→ sources/03-learncpp-fundamental-types.md
#include <iostream>

int main()
{
    double price = 5.0;
    double height = 6.7;
    double big = 9876543.21;
    std::cout << price << '\n';     // 小數部分是 0 時，不會印出 .0
    std::cout << height << '\n';
    std::cout << big << '\n';       // 預設只顯示 6 位有效數字
    return 0;
}
```
實際輸出：
```text
5
6.7
9.87654e+06
```
> 浮點數不一定精確：例如 0.1 沒辦法被精確地存起來，誤差還會在計算中累積。原站提醒「永遠不要假設浮點數是精確的」[03 §4.8]。比較浮點數時會出問題，見[運算子](operators.md)。

**`bool`** [03 §4.9]
- 只有 `true` 和 `false` 兩個值。它其實存成整數：`true` 是 1、`false` 是 0。
- 所以 `std::cout` 預設會印出 `1` / `0`；先輸出 `std::boolalpha`，之後就會印出 `true` / `false`。
- 後面的 if 和迴圈都靠它：原站說布林值是你會用得最多的型別。

範例檔：examples/26-bool.cpp
```cpp
// 出處：learncpp 4.9（改寫）→ sources/03-learncpp-fundamental-types.md
#include <iostream>

int main()
{
    bool isRaining = true;
    bool isSunny = false;
    std::cout << isRaining << ' ' << isSunny << '\n';   // 預設印出 1 和 0
    std::cout << std::boolalpha;                         // 之後改印 true / false
    std::cout << isRaining << ' ' << isSunny << '\n';
    return 0;
}
```
實際輸出：
```text
1 0
true false
```

**`char`** [03 §4.11]
- 存**一個**字元：字母、數字、符號或空白。字元要放在**單引號**裡；雙引號是文字。
- `'5'` 是「字元 5」，和整數 `5` 不一樣：它其實存成 ASCII 碼 53。
- 字元和整數的對應叫 ASCII 碼，例如 `'a'` 是 97；但 `std::cout` 印 `char` 時印的是字元本身。

範例檔：examples/27-char.cpp
```cpp
// 出處：learncpp 4.11（改寫）→ sources/03-learncpp-fundamental-types.md
#include <iostream>

int main()
{
    char grade = 'A';           // 字元用單引號
    char digit = '5';           // 這是「字元 5」，不是整數 5
    std::cout << "Grade: " << grade << '\n';
    std::cout << "Digit: " << digit << '\n';
    return 0;
}
```
實際輸出：
```text
Grade: A
Digit: 5
```
寫成雙引號會編譯失敗，見[新手常見錯誤 #6](common-mistakes.md#6-字元用了雙引號)。

> 範圍外：`float`、`long long`、unsigned 整數、`std::string`（文字變數）等型別，本 wiki 不展開 [03 §4.1]。

### 初始化 vs 賦值
| | 初始化（initialization） | 賦值（assignment） |
|---|---|---|
| 什麼時候 | **定義的同時**給值 | 定義**之後**再給值 |
| 寫法 | `int width = 5;` | `width = 7;` |
| 出處 | [02 §1.4、§1.6] | [02 §1.4、§1.6] |

- 賦值會把 `=` 右邊的值複製到左邊的變數裡；新的值會**覆蓋**舊的值 [02 §1.4]。
- 賦值用的 `=` **不是**「等於」。判斷兩個值是否相等要用 `==`，把兩者搞混是新手最常見的錯誤之一 [02 §1.4]。

範例檔：examples/20-init-and-assign.cpp
```cpp
// 出處：learncpp 1.4（改寫）→ sources/02-learncpp-variables.md
#include <iostream>

int main()
{
    int width = 5;              // 初始化：定義的同時給值
    std::cout << width << '\n';

    width = 7;                  // 賦值：存進新的值，舊的 5 被覆蓋
    std::cout << width << '\n';
    return 0;
}
```
實際輸出：
```text
5
7
```

### 一律要初始化
- 原站建議：定義變數時就初始化 [02 §1.4]。
- 沒有初始化的變數，裡面是記憶體原本的「垃圾值」；C++ **不會**自動幫你設成 0 [02 §1.6]。
- 使用這種變數是**未定義行為**：語言沒有規定會發生什麼事 [02 §1.6]。

詳見[新手常見錯誤 #4](common-mistakes.md#4-使用沒有初始化的變數)。

- 一個敘述只定義一個變數，每個變數各寫一行 [02 §1.3]。
- 小心 `int a, b = 5;` 這種寫法：只有 `b` 被初始化成 5，`a` 沒有被初始化 [02 §1.4]。

### 初始化的寫法：本 wiki 用 `=`
C++ 有好幾種初始化寫法 [02 §1.4]：

| 寫法 | 名稱 | 說明 |
|---|---|---|
| `int a;` | 預設初始化 | 沒有給值，通常是垃圾值 |
| `int b = 5;` | 複製初始化 | 從 C 語言繼承來的寫法 |
| `int c ( 6 );` | 直接初始化 | 用小括號 |
| `int d { 7 };` | 直接列表初始化 | 用大括號，learncpp 推薦 |
| `int e {};` | 值初始化 | 空的大括號，通常會變成 0 |

> ⚔️ 衝突：learncpp 推薦大括號 `int d { 7 };`，理由是大括號會擋下「縮窄轉換」[02 §1.4]。**本 wiki 採用 `int x = 5;`**（見 CLAUDE.md），理由如下：
> - 對零基礎的讀者，先熟悉一種寫法就好。
> - `=` 和數學的寫法接近。
>
> 代價是：用 `=` 時，型別不對編譯器也不會擋下來。下面兩個範例實際示範了差別。

用 `=`：4.5 被默默砍成 4。原站說 .5 會被丟掉 [02 §1.4]；本機 g++ 開了 `-Wall -Wextra` 也**沒有任何警告**。

範例檔：examples/23-copy-init-truncate.cpp
```cpp
// 出處：learncpp 1.4（改寫）→ sources/02-learncpp-variables.md
#include <iostream>

int main()
{
    int w = 4.5;                // 用 = 初始化：4.5 不是整數，但編譯器照樣接受
    std::cout << w << '\n';
    return 0;
}
```
實際輸出：
```text
4
```

用大括號：編譯器直接擋下來 [02 §1.4]。

範例檔：examples/24-brace-narrowing.cpp
```cpp
// 出處：learncpp 1.4（改寫）→ sources/02-learncpp-variables.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    int w{4.5};                 // 用大括號初始化：編譯器會擋下來
    std::cout << w << '\n';
    return 0;
}
```
g++ 的錯誤訊息（`examples/24-brace-narrowing.err`）：
```text
24-brace-narrowing.cpp: In function 'int main()':
24-brace-narrowing.cpp:7:11: error: narrowing conversion of '4.5e+0' from 'double' to 'int' [-Wnarrowing]
    7 |     int w{4.5};                 // 用大括號初始化：編譯器會擋下來
      |           ^~~
```
（`narrowing conversion` 就是縮窄轉換 [02 §1.4]。）

所以用 `=` 初始化時，**你自己要確認右邊的值放得進這個型別**。

### 命名規則
硬性規則，違反就會編譯失敗 [02 §1.7]：
- 不能是關鍵字，例如 `int`、`return`、`if`、`for`、`while`。
- 只能用英文字母、數字和底線 `_`，不能有空白或其他符號。
- 必須以字母或底線開頭，**不能用數字開頭**，見[新手常見錯誤 #5](common-mistakes.md#5-識別字用數字開頭)。
- 大小寫有別：`nvalue`、`nValue`、`NVALUE` 是三個不同的名字。

慣例，不遵守也能編譯 [02 §1.7]：
- 變數名稱以小寫字母開頭。
- 多個字可以用底線分開（`my_variable_name`，snake_case），或從第二個字起首字母大寫（`myVariableName`，camelCase）。
- 避免以底線開頭。
- 名字要表達用途。除非是常見又不會混淆的縮寫（如 `num`、`idx`），否則避免縮寫。

### 讀取輸入：`std::cin`
- `std::cin` 用 `>>`（擷取運算子）從鍵盤讀取輸入，存進變數；程式執行到這一句會**停下來等使用者輸入** [01 §1.5]。
- `>>` 的箭頭方向就是資料流動的方向：從 `std::cin` 流進變數 [01 §1.5]。
- 原站建議讀取前先把變數初始化 [01 §1.5]。
- 提示文字（例如 `"Enter a number: "`）後面不用加 `'\n'`，因為使用者輸入完按 Enter，游標就會自動換到下一行 [01 §1.5]。

範例檔：examples/21-cin-input.cpp
```cpp
// 出處：learncpp 1.5（改寫）→ sources/01-learncpp-program-structure.md
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x = 0;                  // 先初始化，再讀入
    std::cin >> x;              // 程式停在這裡，等使用者輸入
    std::cout << "You entered " << x << '\n';
    return 0;
}
```
輸入（`examples/21-cin-input.in`）：
```text
4
```
實際輸出：
```text
Enter a number: You entered 4
```
> 為什麼輸出沒有換行？`.out` 只記錄**程式印出的內容**，輸入是從 `.in` 餵進去的。你自己執行時，螢幕上會在 `Enter a number: ` 後面看到你打的 `4`，按下 Enter 後才換行，變成：
> ```
> Enter a number: 4
> You entered 4
> ```
> 這和原站顯示的結果相同 [01 §1.5]。

一次可以讀好幾個值，只要用空白分開 [01 §1.5]：

範例檔：examples/22-cin-two-numbers.cpp
```cpp
// 出處：learncpp 1.5（改寫）→ sources/01-learncpp-program-structure.md
#include <iostream>

int main()
{
    std::cout << "Enter two numbers separated by a space: ";
    int x = 0;
    int y = 0;
    std::cin >> x >> y;         // 一次讀兩個值，用空白分開
    std::cout << "You entered " << x << " and " << y << '\n';
    return 0;
}
```
輸入（`examples/22-cin-two-numbers.in`）：
```text
5 6
```
實際輸出：
```text
Enter two numbers separated by a space: You entered 5 and 6
```

使用者輸入的不是整數時，原站的測試結果是 [01 §1.5]：

| 輸入 | `x` 得到的值 |
|---|---|
| 字母（例如 `b`） | 0（讀取失敗） |
| `3.2` | 3：小數被丟掉，不是四捨五入 |
| `5a` | 5 |

## 常見誤解
- ❌「`=` 是等於」→ `=` 是賦值，判斷相等要用 `==` [02 §1.4]。
- ❌「沒有初始化的變數是 0」→ 是記憶體原本的垃圾值，使用它是未定義行為 [02 §1.6]。
- ❌「`int a, b = 5;` 兩個都是 5」→ 只有 `b` 是 5 [02 §1.4]。
- ❌「`int w = 4.5;` 會四捨五入成 5，或者編譯器會警告我」→ 直接變成 4 [02 §1.4]，而且本機 g++ 沒有發出任何警告（見 `23-copy-init-truncate.cpp`）。

## 相關概念
[程式骨架](program-structure.md)、[新手常見錯誤](common-mistakes.md)

## 出處
[01] [../sources/01-learncpp-program-structure.md](../sources/01-learncpp-program-structure.md)：§1.5
[02] [../sources/02-learncpp-variables.md](../sources/02-learncpp-variables.md)：§1.3、§1.4、§1.6、§1.7
[03] [../sources/03-learncpp-fundamental-types.md](../sources/03-learncpp-fundamental-types.md)：§4.1、§4.4、§4.8、§4.9、§4.11
