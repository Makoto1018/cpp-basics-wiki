# 運算子

**一句話定義**：運算子（operator）是代表一種運算的符號，例如 `+`、`>`、`&&`。它拿運算元（operand）來計算，產生一個新的值 [04 §1.9]。
**先備概念**：[變數與型別](variables-and-types.md)

## 白話解釋
`7 + 4` 裡，`+` 是運算子，`7` 和 `4` 是運算元，算出來的新值是 `11` [04 §1.9]。

由字面值、變數、運算子組成、會算出一個值的東西，叫**運算式（expression）**；算的過程叫求值 [04 §1.10]。運算式本身沒有分號，一定要放在敘述裡 [04 §1.10]。

| | 敘述（statement） | 運算式（expression） |
|---|---|---|
| 用途 | 讓程式**做**一件事 | **算出**一個值 |
| 例子 | `int x;` | `2 + 3`、`x > 10` |
| 出處 | [04 §1.10] | [04 §1.10] |

運算式後面加上分號，例如 `x = 5;`，叫做**運算式敘述** [04 §1.10]。凡是需要一個值的地方，都可以放一個運算式，例如 `int y = x + 1;` [04 §1.10]。

本頁的運算子分成五類：算術、複合賦值與遞增、比較、邏輯，以及決定先算誰的優先順序。

## 語法

### 算術運算子
| 運算子 | 意思 | `7 ? 4` 的結果 |
|---|---|---|
| `+` | 加 | 11 |
| `-` | 減 | 3 |
| `*` | 乘 | 28 |
| `/` | 除 | 1（整數除法，見下方） |
| `%` | 餘數 | 3 |

出處：[04 §6.2、§6.3]

減號也可以只放在**一個**值的前面，表示取負數，例如 `-x`。只有一個運算元的運算子叫做一元運算子 [04 §1.9、§6.2]。

範例檔：examples/30-arithmetic.cpp
```cpp
// 出處：learncpp 6.2、6.3（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << 7 + 4 << '\n';     // 加
    std::cout << 7 - 4 << '\n';     // 減
    std::cout << 7 * 4 << '\n';     // 乘
    std::cout << 7 / 4 << '\n';     // 除：兩邊都是整數 → 整數除法
    std::cout << 7 % 4 << '\n';     // 餘數
    return 0;
}
```
實際輸出：
```text
11
3
28
1
3
```

### 整數除法：小數直接丟掉
- `/` 的**兩邊都是整數**時，做的是整數除法：結果還是整數，小數部分直接丟掉，**不是四捨五入** [04 §6.2]、[03 §4.4]。
- 只要有一邊是浮點數，例如 `7.0`，就做一般的除法、保留小數 [04 §6.2]。
- 兩個整數變數相除又想保留小數時，用 `static_cast<double>(x)` 先把其中一個轉成 `double` [04 §6.2]。
- `static_cast<新型別>(值)` 是明確要求轉換型別，不會改變原本的變數 [03 §4.12]。本 wiki 只用它來處理整數除法。

範例檔：examples/31-integer-division.cpp
```cpp
// 出處：learncpp 6.2（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int x = 7;
    int y = 4;
    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "7.0 / 4 = " << 7.0 / 4 << '\n';
    return 0;
}
```
實際輸出：
```text
int / int = 1
double / int = 1.75
7.0 / 4 = 1.75
```
另外，整數除以 0 是未定義行為，程式很可能會當掉 [04 §6.2]。

### 優先順序：先算誰？
- 和數學一樣：先括號、再乘除、再加減 [04 §1.9]。優先順序高的運算子先算 [04 §6.1]。
- 同一個優先順序，由結合性決定順序。加減是由左到右：`7 - 4 - 1` 是 `(7 - 4) - 1` [04 §6.1]。
- 原站建議：不簡單的運算式**加括號**，讓別人不用查表也看得懂。經驗法則是：除了加減乘除，其他都加括號 [04 §6.1]。

範例檔：examples/32-precedence.cpp
```cpp
// 出處：learncpp 1.9、6.1（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << 2 + 3 * 4 << '\n';     // 先乘後加
    std::cout << (2 + 3) * 4 << '\n';   // 括號先算
    std::cout << 7 - 4 - 1 << '\n';     // 同一級：由左到右
    return 0;
}
```
實際輸出：
```text
14
20
2
```

### 複合賦值與遞增／遞減
| 寫法 | 等於 | 出處 |
|---|---|---|
| `x += 4;` | `x = x + 4;` | [04 §6.2] |
| `x -= 2;` | `x = x - 2;` | [04 §6.2] |
| `++x;` | 讓 x 加 1 | [04 §6.4] |
| `--x;` | 讓 x 減 1 | [04 §6.4] |

`*=`、`/=`、`%=` 也是同樣的道理 [04 §6.2]。

遞增還有 `x++` 這種寫法：
- 單獨寫成一個敘述時，`++x;` 和 `x++;` 效果相同；差別只有在放進更大的運算式時才會出現 [04 §6.4]。
- 原站建議優先用 `++x` [04 §6.4]，本 wiki 一律使用 `++x`。
- 不要在同一個敘述裡，對同一個變數使用超過一次 `++`、`=` 這類會改變它的運算，結果可能是未定義的 [04 §6.4]。

範例檔：examples/33-compound-increment.cpp
```cpp
// 出處：learncpp 6.2、6.4（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int x = 5;
    x += 4;                     // 等於 x = x + 4
    std::cout << x << '\n';
    x -= 2;                     // 等於 x = x - 2
    std::cout << x << '\n';
    ++x;                        // 遞增：加 1
    std::cout << x << '\n';
    --x;                        // 遞減：減 1
    std::cout << x << '\n';
    return 0;
}
```
實際輸出：
```text
9
7
8
7
```

### 餘數 `%`
- `%` 取整數相除的餘數：`7 % 4` 是 3。只能用在整數上 [04 §6.3]。
- 最常見的用途是**判斷能不能整除**：`x % y` 是 0，代表 x 可以被 y 整除。例如 `x % 2` 是 0 就是偶數 [04 §6.3]。
- 除數比被除數大時，餘數就是被除數本身，例如 `2 % 4` 是 2 [04 §6.3]。
- 有負數時，結果的正負號跟著左邊 [04 §6.3]。
- 所以原站建議盡量拿結果**和 0 比較**：用 `x % 2 == 1` 判斷奇數，遇到負的奇數會出錯，因為 `-5 % 2` 是 -1 [04 §6.3]。

範例檔：examples/34-remainder.cpp
```cpp
// 出處：learncpp 6.3（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << 10 % 2 << '\n';    // 0 → 10 可以被 2 整除
    std::cout << 7 % 2 << '\n';     // 1
    std::cout << 2 % 4 << '\n';     // 被除數比較小 → 餘數就是它自己
    std::cout << -6 % 4 << '\n';    // 結果的正負號跟著左邊
    return 0;
}
```
實際輸出：
```text
0
1
2
-2
```

### 比較運算子
| 運算子 | 意思 |
|---|---|
| `>` / `<` | 大於／小於 |
| `>=` / `<=` | 大於等於／小於等於 |
| `==` | 相等（**兩個**等號） |
| `!=` | 不相等 |

出處：[04 §6.7]

- 比較的結果都是 `bool`：`true` 或 `false` [04 §6.7]。這就是下一頁 if 的「條件」。
- 原站建議：不要寫多餘的 `== true`，例如 `if (b == true)` 直接寫成 `if (b)` [04 §6.7]。

在 `std::cout` 裡印出比較或邏輯運算的結果時，本 wiki 一律**加括號**。依據有兩個：原站「不簡單的運算式要加括號」的建議 [04 §6.1]，以及原站自己的範例也是這樣寫 [04 §6.7]。

範例檔：examples/35-relational.cpp
```cpp
// 出處：learncpp 6.7（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int a = 5;
    int b = 3;
    std::cout << std::boolalpha;    // 印出 true / false
    std::cout << (a > b) << '\n';
    std::cout << (a < b) << '\n';
    std::cout << (a >= 5) << '\n';
    std::cout << (a == b) << '\n';
    std::cout << (a != b) << '\n';
    return 0;
}
```
實際輸出：
```text
true
false
true
false
true
```
浮點數**不要用 `==` 比較**，見[新手常見錯誤 #8](common-mistakes.md#8-用--比較浮點數)。

### 邏輯運算子
| 運算子 | 名稱 | 什麼時候是 `true` |
|---|---|---|
| `&&` | AND（而且） | 兩邊**都**是 `true` |
| `\|\|` | OR（或者） | **任一邊**是 `true`（兩邊都是也算） |
| `!` | NOT（不是） | 把 `true` / `false` 反過來 |

出處：[04 §6.8]

- 用來一次檢查好幾個條件，例如「大於 10 **而且**小於 20」：`value > 10 && value < 20` [04 §6.8]。
- `!` 的優先順序很高：`!x > y` 會被當成 `(!x) > y`。想否定整個比較，要寫 `!(x > y)` [04 §6.8]。
- `&&` 比 `||` 先算。原站建議：兩個混用時，每一組都加上括號，例如 `(a && b) || (c && d)` [04 §6.8]。
- 短路求值：`&&` 的左邊是 `false`、或 `||` 的左邊是 `true` 時，右邊根本不會被計算 [04 §6.8]。

範例檔：examples/36-logical.cpp
```cpp
// 出處：learncpp 6.8（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int value = 15;
    std::cout << std::boolalpha;
    std::cout << (value > 10 && value < 20) << '\n';    // 兩個都成立才 true
    std::cout << (value == 0 || value == 1) << '\n';    // 任一個成立就 true
    std::cout << !(value > 10) << '\n';                 // 反過來
    return 0;
}
```
實際輸出：
```text
true
false
false
```

## 常見誤解
- ❌「`7 / 2` 是 3.5」→ 兩邊都是整數就做整數除法，結果是 3 [04 §6.2]。就算把結果存進 `double` 也一樣，見[常見錯誤 #7](common-mistakes.md#7-把整數相除的結果存進-double)。
- ❌「整數除法會四捨五入」→ 小數直接丟掉 [03 §4.4]。
- ❌「`0.3 == 0.2 + 0.1` 是 true」→ 是 false，見[常見錯誤 #8](common-mistakes.md#8-用--比較浮點數) [04 §6.7]。
- ❌「`2 ^ 3` 是 8」→ C++ 沒有次方運算子，`^` 不是次方，見[常見錯誤 #9](common-mistakes.md#9-用--當次方) [04 §6.1、§6.3]。
- ❌「`value == 0 || 1` 是在檢查 value 是 0 或 1」→ 這個條件永遠成立，要寫 `value == 0 || value == 1` [04 §6.8]。
- ❌「`=` 和 `==` 一樣」→ `=` 是賦值，`==` 才是比較 [02 §1.4]。

## 小測驗：預測輸出
先想想看這段程式會印出什麼，再點開答案。這個範例故意不寫註解，避免洩漏答案；內容和[常見錯誤 #7](common-mistakes.md#7-把整數相除的結果存進-double) 的 `86-int-division-to-double.cpp` 相同。

範例檔：examples/37-quiz-average.cpp
```cpp
// 出處：learncpp 6.2（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    double average = 7 / 2;
    std::cout << average << '\n';
    return 0;
}
```
<details><summary>答案</summary>

實際輸出：
```text
3
```
`7` 和 `2` 都是整數，所以先做整數除法得到 3，才存進 `double` [04 §6.2]。要得到 3.5，請寫 `7.0 / 2` [04 §6.2]。
</details>

## 相關概念
[變數與型別](variables-and-types.md)、[if-else](if-else.md)（下一頁：比較和邏輯的結果就是 if 的條件）、[新手常見錯誤](common-mistakes.md)

## 出處
[02] [../sources/02-learncpp-variables.md](../sources/02-learncpp-variables.md)：§1.4
[03] [../sources/03-learncpp-fundamental-types.md](../sources/03-learncpp-fundamental-types.md)：§4.4、§4.12
[04] [../sources/04-learncpp-operators.md](../sources/04-learncpp-operators.md)：§1.9、§1.10、§6.1、§6.2、§6.3、§6.4、§6.7、§6.8
