# 新手常見錯誤

**一句話定義**：新手最常寫錯的地方彙整。每一條都附上❌錯誤寫法、編譯器的**真實**訊息或實際輸出，以及✅正確寫法。
**先備概念**：每一條都標了所屬的概念頁

> 錯誤訊息一律複製自 `examples/*.err`（本機 g++ 15.2 實際產生），不是推測的。

## 1. 漏了分號
**所屬概念**：[程式骨架](program-structure.md)

大部分敘述都要以分號結尾 [01 §1.1]；少了分號是語法錯誤，程式無法編譯 [01 §3.1]。

❌ 範例檔：examples/80-missing-semicolon.cpp
```cpp
// 出處：learncpp 1.1（改寫）→ sources/01-learncpp-program-structure.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    std::cout << "Hello world!\n"   // ← 這行少了分號
    return 0;
}
```
g++ 的錯誤訊息（`examples/80-missing-semicolon.err`）：
```text
80-missing-semicolon.cpp: In function 'int main()':
80-missing-semicolon.cpp:7:34: error: expected ';' before 'return'
    7 |     std::cout << "Hello world!\n"   // ← 這行少了分號
      |                                  ^
      |                                  ;
    8 |     return 0;
      |     ~~~~~~                        
```
怎麼讀：`7:34` 表示第 7 行第 34 個字元 [01 §1.1]；`expected ';' before 'return'` 表示「在 `return` 之前應該要有分號」。g++ 還用 `^` 和 `;` 標出了該補分號的位置。

✅ 修正：在第 7 行結尾補上 `;`（正確寫法見 `examples/10-hello-world.cpp`）。

> ⚔️ 衝突：原站說編譯器有時會把錯誤回報在**下一行**，例如 Visual Studio 回報在 `return` 那一行 [01 §1.1]。本機 g++ 實測回報在第 7 行，就是漏分號的那一行。不同編譯器行為不同，所以錯誤不在回報的那一行時，記得往上一行找 [01 §1.1]。

## 2. 忘了寫 `std::`
**所屬概念**：[程式骨架](program-structure.md)

使用 `cout`、`cin`、`endl` 時，除了要 `#include <iostream>`，每次使用都要在前面加上 `std::` [01 §0.8]。

❌ 範例檔：examples/81-missing-std.cpp
```cpp
// 出處：learncpp 0.8（改寫）→ sources/01-learncpp-program-structure.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    cout << "Hello world!\n";   // ← 少了 std::
    return 0;
}
```
g++ 的錯誤訊息（`examples/81-missing-std.err`）：
```text
81-missing-std.cpp: In function 'int main()':
81-missing-std.cpp:7:5: error: 'cout' was not declared in this scope; did you mean 'std::cout'?
    7 |     cout << "Hello world!\n";   // ← 少了 std::
      |     ^~~~
      |     std::cout
In file included from 81-missing-std.cpp:3:
C:/mingw64/lib/gcc/x86_64-w64-mingw32/15.2.0/include/c++/iostream:65:18: note: 'std::cout' declared here
   65 |   extern ostream cout;          ///< Linked to standard output
      |                  ^~~~
```
怎麼讀：`'cout' was not declared in this scope` 是「`cout` 在這裡沒有被宣告」；`did you mean 'std::cout'?` 是 g++ 直接給的修正建議。後面以 `note:` 開頭的段落寫著 `'std::cout' declared here`，指出 `std::cout` 是在 iostream 裡宣告的。

✅ 修正：改成 `std::cout`（見 `examples/10-hello-world.cpp`）。

## 3. 把 `'\n'` 寫成 `'/n'`
**所屬概念**：[程式骨架](program-structure.md)

換行字元 `'\n'` 用的是**反斜線**；寫成斜線 `'/n'` 雖然能編譯，結果卻很奇怪，原站說常常會印出 `12142` [01 §1.5]。

❌ 範例檔：examples/82-slash-n.cpp
```cpp
// 出處：learncpp 1.5（改寫）→ sources/01-learncpp-program-structure.md
// 示範：warning
#include <iostream>

int main()
{
    std::cout << "Hello" << '/n';   // ← 斜線方向寫反了，應該是 '\n'
    return 0;
}
```
g++ 的警告訊息（`examples/82-slash-n.err`）：
```text
82-slash-n.cpp:7:29: warning: multi-character character constant [-Wmultichar]
    7 |     std::cout << "Hello" << '/n';   // ← 斜線方向寫反了，應該是 '\n'
      |                             ^~~~
```
實際輸出（`examples/82-slash-n.out`）：
```text
Hello12142
```
怎麼讀：這是 `warning`（警告），不是 `error`（錯誤），所以程式還是能編譯。但不能因此忽略它：沒有換行，反而多印了 `12142`，和原站說的一樣 [01 §1.5]。

✅ 修正：改成 `'\n'`（見 `examples/11-cout-chain.cpp`）。

## 4. 使用沒有初始化的變數
**所屬概念**：[變數與型別](variables-and-types.md)

C++ 不會自動把變數設成 0。沒有初始化的變數，裡面是記憶體原本的垃圾值；使用它的值是**未定義行為** [02 §1.6]。

❌ 範例檔：examples/83-uninitialized.cpp
```cpp
// 出處：learncpp 1.6（改寫）→ sources/02-learncpp-variables.md
// 示範：未定義行為
// 示範：warning
#include <iostream>

int main()
{
    int x;                      // ← 沒有初始化
    std::cout << x << '\n';     // 印出來的值無法預測
    return 0;
}
```
g++ 的警告訊息（`examples/83-uninitialized.err`）：
```text
83-uninitialized.cpp: In function 'int main()':
83-uninitialized.cpp:9:23: warning: 'x' is used uninitialized [-Wuninitialized]
    9 |     std::cout << x << '\n';     // 印出來的值無法預測
      |                       ^~~~
83-uninitialized.cpp:8:9: note: 'x' was declared here
    8 |     int x;                      // ← 沒有初始化
      |         ^
```
怎麼讀：
- `'x' is used uninitialized` 是說「`x` 還沒初始化就被使用了」。
- `note:` 指出 `x` 是在第 8 行宣告的。
- 大多數現代編譯器都會試著抓出這種錯誤 [02 §1.6]。

這是 `warning`，程式**照樣能編譯和執行**，所以更要注意。

這個範例故意不附輸出，因為印出什麼是無法預測的。原站列出的未定義行為症狀包括 [02 §1.6]：
- 每次執行結果不同。
- 也可能每次都給出**同樣的錯誤結果**，甚至剛好看起來正確。
- 換了編譯器，或改了其他無關的程式碼，就壞掉。

所以「我跑了幾次都一樣」**不代表沒問題**。

✅ 修正：定義時就初始化，例如 `int x = 0;` [02 §1.4]。

## 5. 識別字用數字開頭
**所屬概念**：[變數與型別](variables-and-types.md)

變數名稱只能以字母或底線開頭，不能用數字開頭 [02 §1.7]。

❌ 範例檔：examples/84-digit-identifier.cpp
```cpp
// 出處：learncpp 1.7（改寫）→ sources/02-learncpp-variables.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    int 1x = 5;                 // ← 識別字不能用數字開頭
    std::cout << 1x << '\n';
    return 0;
}
```
g++ 的錯誤訊息（`examples/84-digit-identifier.err`）：
```text
84-digit-identifier.cpp: In function 'int main()':
84-digit-identifier.cpp:7:9: error: expected unqualified-id before numeric constant
    7 |     int 1x = 5;                 // ← 識別字不能用數字開頭
      |         ^~
84-digit-identifier.cpp:8:18: error: unable to find numeric literal operator 'operator""x'
    8 |     std::cout << 1x << '\n';
      |                  ^~
84-digit-identifier.cpp:8:18: note: use '-fext-numeric-literals' to enable more built-in suffixes
```
怎麼讀：這次的訊息**完全沒有提到「不能用數字開頭」**。
- 第一個錯誤 `expected unqualified-id before numeric constant` 的後半段是「在數字常數（numeric constant）之前」。`^~` 標在 `1x` 底下，對照命名規則就知道，問題出在名字用數字開頭 [02 §1.7]。
- 第二個錯誤（8:18）指的也是同一個 `1x`。

> ⚠️ 待查證：`expected unqualified-id` 的確切意思，以及 `note:` 建議的 `-fext-numeric-literals` 是什麼。目前的來源都沒有說明，本 wiki 的修正方法只依據命名規則 [02 §1.7]。

遇到看不懂的訊息時，先看**第一個** `error` 指到的位置（7:9，`^~` 標在 `1x` 下面），再對照那一行和上一行 [01 §0.7、§1.1]。

> ⚠️ 待查證：「修好第一個錯誤後重新編譯，後面連帶的錯誤常常會一起消失」。本例看起來是這樣，但目前的來源沒有這個說法。

✅ 修正：改用字母開頭的名字，例如 `x1` 或更有意義的 `count`。

## 6. 字元用了雙引號
**所屬概念**：[變數與型別](variables-and-types.md)

`char` 只能存一個字元，字元要用**單引號**；雙引號代表的是文字 [03 §4.11]、[02 §1.3]。

❌ 範例檔：examples/85-char-double-quotes.cpp
```cpp
// 出處：learncpp 4.11（改寫）→ sources/03-learncpp-fundamental-types.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    char grade = "A";           // ← 字元要用單引號 'A'，雙引號是文字
    std::cout << grade << '\n';
    return 0;
}
```
g++ 的錯誤訊息（`examples/85-char-double-quotes.err`）：
```text
85-char-double-quotes.cpp: In function 'int main()':
85-char-double-quotes.cpp:7:18: error: invalid conversion from 'const char*' to 'char' [-fpermissive]
    7 |     char grade = "A";           // ← 字元要用單引號 'A'，雙引號是文字
      |                  ^~~
      |                  |
      |                  const char*
```
怎麼讀：`invalid conversion from … to 'char'` 意思是「沒辦法把右邊的東西轉成 `char`」，也就是型別對不上。g++ 在 `"A"` 下方用 `|` 標出了它的型別 `const char*`；這種型別屬於本 wiki 範圍外的概念，不展開。

✅ 修正：改成單引號 `char grade = 'A';`（見 `examples/27-char.cpp`）。

## 7. 把整數相除的結果存進 double
**所屬概念**：[運算子](operators.md)

`/` 的兩邊都是整數時，做的是整數除法，小數會被丟掉 [04 §6.2]。結果存進哪種型別的變數，**不會**改變除法的方式（`=` 右邊的運算式先算完，才存進變數 [04 §1.10]）。

❌ 範例檔：examples/86-int-division-to-double.cpp
```cpp
// 出處：learncpp 6.2（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    double average = 7 / 2;     // ← 兩邊都是整數，先做整數除法得到 3，才存進 double
    std::cout << average << '\n';
    return 0;
}
```
實際輸出：
```text
3
```
g++ 開了 `-Wall -Wextra` 也**沒有任何警告**，所以這種錯誤只能靠自己注意。

✅ 修正：讓其中一邊變成浮點數，例如 `7.0 / 2`；如果是變數，就寫 `static_cast<double>(x) / y` [04 §6.2]（見 `examples/31-integer-division.cpp`）。

## 8. 用 == 比較浮點數
**所屬概念**：[運算子](operators.md)

浮點數有捨入誤差，算出來的值常常和數學上的值差一點點，所以用 `==` 比較很危險 [04 §6.7]、[03 §4.8]。

❌ 範例檔：examples/87-float-equality.cpp
```cpp
// 出處：learncpp 6.7（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << (0.3 == 0.2 + 0.1) << '\n';    // ← 數學上相等，程式卻說不相等
    return 0;
}
```
實際輸出：
```text
false
```

✅ 原站的建議：浮點數只要可能是算出來的，就避免用 `==` 和 `!=` 比較 [04 §6.7]。
> 範圍外：「夠接近就算相等」的比較方法（epsilon）原站有介紹，但對入門來說太深，本 wiki 不展開 [04 §6.7]。

## 9. 用 ^ 當次方
**所屬概念**：[運算子](operators.md)

C++ **沒有**次方運算子，`^` 是位元運算，屬於範圍外的概念 [04 §6.1、§6.3]。

❌ 範例檔：examples/88-caret-power.cpp
```cpp
// 出處：learncpp 6.1、6.3（改寫）→ sources/04-learncpp-operators.md
// 示範：warning
#include <iostream>

int main()
{
    std::cout << (2 ^ 3) << '\n';   // ← 想算 2 的 3 次方，但 ^ 不是次方
    return 0;
}
```
g++ 的警告訊息（`examples/88-caret-power.err`）：
```text
88-caret-power.cpp: In function 'int main()':
88-caret-power.cpp:7:21: warning: result of '2^3' is 1; did you mean '1 << 3' (8)? [-Wxor-used-as-pow]
    7 |     std::cout << (2 ^ 3) << '\n';   // ← 想算 2 的 3 次方，但 ^ 不是次方
      |                     ^
      |                   -
      |                   1 <<
88-caret-power.cpp:7:19: note: you can silence this warning by using a hexadecimal constant (0x2 rather than 2)
    7 |     std::cout << (2 ^ 3) << '\n';   // ← 想算 2 的 3 次方，但 ^ 不是次方
      |                   ^
      |                   0x2
```
實際輸出（`examples/88-caret-power.out`）：
```text
1
```
怎麼讀：
- `result of '2^3' is 1` 已經直接告訴你：結果是 1，不是 8。
- 但它建議的 `1 << 3`，`<<` 在這裡是位移運算子，屬於範圍外的概念 [04 §6.1]；後面 `note:` 說的是 `you can silence this warning`，也就是「怎麼讓這個警告消失」，不是怎麼修正錯誤。兩者都**不要照抄**。

✅ 修正：要算次方，原站的方法是 `#include <cmath>` 再用 `std::pow(2.0, 3.0)`，結果是 `double` [04 §6.3]。像 2 的 3 次方這種小次方，直接寫 `2 * 2 * 2` 也可以。

## 10. 在條件裡用 = 而不是 ==
**所屬概念**：[if-else](if-else.md)

判斷相等要用 `==`。寫成 `=` 就變成「賦值」：`if (x = 0)` 會先把 0 存進 x，再用 x 的值（0）當條件，而 0 會被當成 `false` [05 §8.3]、[05 §4.10]。

❌ 範例檔：examples/89-assign-in-if.cpp
```cpp
// 出處：learncpp 8.3（改寫）→ sources/05-learncpp-if-else.md
// 示範：warning
#include <iostream>

int main()
{
    std::cout << "Enter 0 or 1: ";
    int x = 0;
    std::cin >> x;
    if (x = 0) {                // ← 應該是 ==，這裡變成「把 0 賦值給 x」
        std::cout << "You entered 0\n";
    } else {
        std::cout << "You entered 1\n";
    }
    return 0;
}
```
輸入（`examples/89-assign-in-if.in`）：
```text
0
```
實際輸出：
```text
Enter 0 or 1: You entered 1
```
g++ 的警告訊息（`examples/89-assign-in-if.err`）：
```text
89-assign-in-if.cpp: In function 'int main()':
89-assign-in-if.cpp:10:11: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
   10 |     if (x = 0) {                // ← 應該是 ==，這裡變成「把 0 賦值給 x」
      |         ~~^~~
```
怎麼讀：
- `assignment used as truth value` 的意思是「把賦值拿來當條件」，這正是錯誤所在。
- 但它的建議 `suggest parentheses` 是要你加括號。括號只會改變運算的組合方式 [04 §6.1]，`(x = 0)` 仍然是賦值，**加了括號程式還是錯的**。

輸入 0，卻印出 `You entered 1`，和原站描述的結果相同 [05 §8.3]。

✅ 修正：改成 `if (x == 0)`。

## 11. if 條件後面多了分號
**所屬概念**：[if-else](if-else.md)

只有一個分號的敘述叫空敘述，什麼都不做。在 if 條件後面多加分號，if 控制的就是這個空敘述；後面原本想「條件成立才執行」的敘述，變成**一定會執行**，即使它放在區塊裡 [05 §8.3]。

❌ 範例檔：examples/90-if-semicolon.cpp
```cpp
// 出處：learncpp 8.3（改寫）→ sources/05-learncpp-if-else.md
// 示範：warning
#include <iostream>

int main()
{
    int x = 5;
    if (x > 10);                // ← 多了一個分號：if 到這裡就結束了
    {
        std::cout << x << " is greater than 10\n";
    }
    return 0;
}
```
實際輸出：
```text
5 is greater than 10
```
g++ 的警告訊息（`examples/90-if-semicolon.err`）：
```text
90-if-semicolon.cpp: In function 'int main()':
90-if-semicolon.cpp:8:16: warning: suggest braces around empty body in an 'if' statement [-Wempty-body]
    8 |     if (x > 10);                // ← 多了一個分號：if 到這裡就結束了
      |                ^
90-if-semicolon.cpp:8:5: warning: this 'if' clause does not guard... [-Wmisleading-indentation]
    8 |     if (x > 10);                // ← 多了一個分號：if 到這裡就結束了
      |     ^~
90-if-semicolon.cpp:9:5: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'if'
    9 |     {
      |     ^
```
怎麼讀：
- `empty body in an 'if' statement` 的意思是「這個 if 的主體是空的」，`^` 就指在那個分號上。
- 第二個警告的意思是：第 9 行的區塊**看起來**像是受 if 控制，其實沒有。

✅ 修正：刪掉 `if (x > 10)` 後面的分號。

## 12. if / else 沒加大括號
**所屬概念**：[if-else](if-else.md)

沒有大括號時，if 和 else 都只控制緊接在後面的**一個**敘述，**不管縮排怎麼排** [05 §8.2]。

❌ 範例檔：examples/91-missing-braces.cpp
```cpp
// 出處：learncpp 8.2（改寫）→ sources/05-learncpp-if-else.md
// 示範：warning
#include <iostream>

int main()
{
    int x = 5;
    if (x > 10)
        std::cout << "x is big\n";
    else
        std::cout << "x is small\n";
        std::cout << "Too bad!\n";  // ← 看起來屬於 else，其實不是
    return 0;
}
```
實際輸出：
```text
x is small
Too bad!
```
g++ 的警告訊息（`examples/91-missing-braces.err`）：
```text
91-missing-braces.cpp: In function 'int main()':
91-missing-braces.cpp:10:5: warning: this 'else' clause does not guard... [-Wmisleading-indentation]
   10 |     else
      |     ^~~~
91-missing-braces.cpp:12:9: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'else'
   12 |         std::cout << "Too bad!\n";  // ← 看起來屬於 else，其實不是
      |         ^~~
```
怎麼讀：「這個 `else` 並沒有控制第 12 行，第 12 行的縮排會讓人誤會」。

這個例子裡 x 是 5，看起來好像沒事。但把 x 改成大於 10 的數，`Too bad!` 還是會印出來，因為它根本不屬於 else [05 §8.2]。

✅ 修正：if 和 else 的主體一律加大括號，這也是本 wiki 的規定（見 `examples/43-block.cpp`）[05 §8.2]。

## 13. 寫成 value == 0 || 1
**所屬概念**：[if-else](if-else.md)、[運算子](operators.md)

想檢查「value 是 0 或 1」，卻寫成 `value == 0 || 1`。這個條件**永遠成立**：`||` 的右邊只有 `1`，而 1 會被轉成 `true` [04 §6.8]、[05 §4.10]。

❌ 範例檔：examples/92-or-shortcut.cpp
```cpp
// 出處：learncpp 6.8（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int value = 5;
    if (value == 0 || 1) {      // ← 想檢查「value 是 0 或 1」，但寫錯了
        std::cout << "value is 0 or 1\n";
    }
    return 0;
}
```
實際輸出：
```text
value is 0 or 1
```
value 明明是 5，條件卻成立了。g++ 開了 `-Wall -Wextra` 也**沒有任何警告**。

✅ 修正：每一邊都寫完整的比較，`value == 0 || value == 1` [04 §6.8]。

## 14. 忘了更新迴圈變數
**所屬概念**：[while 迴圈](while-loop.md)

迴圈的條件要靠主體裡的更新，才有機會變成 `false`。忘了更新的話，條件永遠成立，變成無窮迴圈 [06 §8.8]。

❌ 範例檔：examples/93-infinite-loop.cpp
```cpp
// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
// 示範：無窮迴圈
#include <iostream>

int main()
{
    int count = 1;
    while (count <= 10) {
        std::cout << count << ' ';  // ← 忘了 ++count，count 永遠是 1
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出（只保留前 200 bytes；程式停不下來，2 秒後被強制中止）：
```text
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
```
`1` 會一直印下去，`done!` 永遠不會出現，和原站描述的相同 [06 §8.8]。編譯時**沒有任何警告**。

> 程式卡在無窮迴圈時，可以在終端機按 `Ctrl+C` 強制結束。⚠️ 待查證：目前的來源沒有提到這個操作。原站只說可以由使用者「kill」程式 [06 §8.8]。

✅ 修正：在主體最後加上 `++count;`（見 `examples/50-while-count.cpp`）。

## 15. while 條件後面多了分號
**所屬概念**：[while 迴圈](while-loop.md)

while 條件後面多一個分號，迴圈的主體就變成「什麼都不做」的空敘述。條件永遠不會改變，於是程式卡住，看起來像當掉一樣 [06 §8.8]。

❌ 範例檔：examples/94-while-semicolon.cpp
```cpp
// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
// 示範：無窮迴圈
// 示範：warning
#include <iostream>

int main()
{
    int count = 1;
    while (count <= 10);        // ← 多了分號：迴圈主體變成「什麼都不做」
    {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出（什麼都沒印；程式停不下來，2 秒後被強制中止）：
```text

```
g++ 的警告訊息（`examples/94-while-semicolon.err`）：
```text
94-while-semicolon.cpp: In function 'int main()':
94-while-semicolon.cpp:9:5: warning: this 'while' clause does not guard... [-Wmisleading-indentation]
    9 |     while (count <= 10);        // ← 多了分號：迴圈主體變成「什麼都不做」
      |     ^~~~~
94-while-semicolon.cpp:10:5: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'while'
   10 |     {
      |     ^
```
怎麼讀：意思是「第 10 行的區塊看起來屬於 while，其實不是」。

和 if 多分號（[#11](#11-if-條件後面多了分號)）比較：if 的版本 g++ 還會說「主體是空的」（`empty body`）；while 的版本只有這個縮排警告，比較容易忽略。

✅ 修正：刪掉 `while (count <= 10)` 後面的分號。

## 16. 差一錯誤
**所屬概念**：[for 迴圈](for-loop.md)

迴圈多跑一次或少跑一次，叫做差一錯誤（off-by-one error）。最常見的原因是 `<` 和 `<=` 用錯 [06 §8.10]。

❌ 範例檔：examples/95-off-by-one.cpp
```cpp
// 出處：learncpp 8.10（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int i = 1; i < 5; ++i) {   // ← 想印 1 到 5，但條件寫成 < 5
        std::cout << i << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出：
```text
1 2 3 4 done!
```
少了 5。編譯時**沒有任何警告**，因為從語法來看，程式完全正確，這是語意錯誤 [01 §3.1]。

✅ 修正：改成 `i <= 5`。

## 17. continue 跳過了更新
**所屬概念**：[break 與 continue](break-continue.md)

在 while 迴圈裡，如果更新迴圈變數的那一行放在 `continue` 後面，continue 就會跳過它。迴圈變數永遠不再改變，變成無窮迴圈 [06 §8.11]。for 迴圈不會有這個問題，因為 continue 之後仍然會執行更新 [06 §8.11]。

❌ 範例檔：examples/96-continue-skips-update.cpp
```cpp
// 出處：learncpp 8.11（改寫）→ sources/06-learncpp-loops.md
// 示範：無窮迴圈
#include <iostream>

int main()
{
    int count = 0;
    while (count < 10) {
        if (count == 5) {
            continue;           // ← 跳過了下面的 ++count，count 永遠停在 5
        }
        std::cout << count << '\n';
        ++count;
    }
    return 0;
}
```
實際輸出（程式停不下來，2 秒後被強制中止）：
```text
0
1
2
3
4
```
印出 0 到 4 之後，程式就**安靜地卡住**：沒有輸出，也不會結束。這和原站描述的相同 [06 §8.11]。

✅ 修正：有明顯的計數器時，改用 for 迴圈 [06 §8.11]：
```text
for (int count = 0; count < 10; ++count) { … }
```
這樣 continue 之後仍然會執行 `++count`。

## 相關概念
[程式骨架](program-structure.md)、[變數與型別](variables-and-types.md)、[運算子](operators.md)、[if-else](if-else.md)、[while 迴圈](while-loop.md)、[for 迴圈](for-loop.md)、[break 與 continue](break-continue.md)

## 出處
[01] [../sources/01-learncpp-program-structure.md](../sources/01-learncpp-program-structure.md)：§0.8、§1.1、§1.5、§3.1
[02] [../sources/02-learncpp-variables.md](../sources/02-learncpp-variables.md)：§1.3、§1.4、§1.6、§1.7
[03] [../sources/03-learncpp-fundamental-types.md](../sources/03-learncpp-fundamental-types.md)：§4.8、§4.11
[04] [../sources/04-learncpp-operators.md](../sources/04-learncpp-operators.md)：§1.10、§6.1、§6.2、§6.3、§6.7、§6.8
[05] [../sources/05-learncpp-if-else.md](../sources/05-learncpp-if-else.md)：§4.10、§8.2、§8.3
[06] [../sources/06-learncpp-loops.md](../sources/06-learncpp-loops.md)：§8.8、§8.10、§8.11
