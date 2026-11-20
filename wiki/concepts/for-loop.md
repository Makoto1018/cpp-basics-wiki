# for 迴圈

**一句話定義**：for 迴圈把迴圈變數的**初始化、條件檢查、更新**集中寫在同一行，是 C++ 最常用的迴圈 [06 §8.10]。
**先備概念**：[while 迴圈](while-loop.md)

## 白話解釋
寫 while 迴圈時，計數器的三個步驟分散在三個地方：初始化在迴圈前面，條件在 while 那一行，更新在主體最後面。for 把它們集中在一行，一眼就看得出這個迴圈會跑幾次 [06 §8.10]。

原站的建議 [06 §8.10]：
- 有明顯的計數器（例如「做 10 次」）時，用 for。
- 沒有計數器（例如「一直做，直到使用者輸入 0」）時，用 while。

## 語法
```text
for (初始化; 條件; 更新) {
    主體
}
```
原站把三個部分稱為 init-statement、condition、end-expression [06 §8.10]。

**執行順序** [06 §8.10]：
1. 初始化：**只執行一次**。
2. 檢查條件：`false` 就結束迴圈。
3. 執行主體。
4. 執行更新。
5. 回到第 2 步。

範例檔：examples/60-for-count.cpp
```cpp
// 出處：learncpp 8.10（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int i = 1; i <= 10; ++i) {     // 初始化; 條件; 更新
        std::cout << i << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出：
```text
1 2 3 4 5 6 7 8 9 10 done!
```

### for 和 while 的對應
上面的 for 迴圈和 [while 迴圈](while-loop.md)頁的 `50-while-count.cpp` 做的事情一樣，輸出也完全相同 [06 §8.10]：

| for 的部分 | `for (int i = 1; i <= 10; ++i)` | while 版本裡在哪裡 |
|---|---|---|
| 初始化 | `int i = 1` | 迴圈**前面**的 `int count = 1;` |
| 條件 | `i <= 10` | `while (count <= 10)` |
| 更新 | `++i` | 主體**最後一行**的 `++count;` |

有一個差別：在 for 的初始化裡定義的變數（`i`），**只在迴圈裡面有效**，迴圈結束後就不存在了 [06 §8.10]。

### 倒數、一次跳好幾個
更新的部分不一定要寫 `++i`，可以用 `--i` 倒數，也可以用 `i += 2` 一次加 2 [06 §8.10]。

範例檔：examples/61-for-step.cpp
```cpp
// 出處：learncpp 8.10（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int i = 5; i >= 1; --i) {      // 倒數
        std::cout << i << ' ';
    }
    std::cout << "liftoff!\n";
    for (int i = 0; i <= 10; i += 2) {  // 一次加 2
        std::cout << i << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出：
```text
5 4 3 2 1 liftoff!
0 2 4 6 8 10 done!
```

### 範例：1 加到 100
這個範例把 for 和 `+=`（[運算子](operators.md)）組合起來。每一輪都把 `i` 加進 `sum`，迴圈結束時，`sum` 就是總和。

範例檔：examples/63-sum-1-to-100.cpp
```cpp
// 出處：自編示意例（語法依據 sources/06-learncpp-loops.md §8.10、sources/04-learncpp-operators.md §6.2）
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i;               // 每一輪把 i 加進 sum
    }
    std::cout << "1 + 2 + ... + 100 = " << sum << '\n';
    return 0;
}
```
實際輸出：
```text
1 + 2 + ... + 100 = 5050
```
> ⚠️ 待查證：這種「在迴圈外定義一個變數，每一輪把東西加進去」的寫法，通常稱為累加器（accumulator），但目前的來源沒有介紹這個名詞和寫法（CLAUDE.md 列為已知缺口）。這裡只示範語法。

### 巢狀 for：九九乘法表
迴圈裡面可以再放迴圈：**外層每跑一輪，內層就完整跑完一次** [06 §8.10]。下面的範例共執行 9 × 9 = 81 次 `std::cout << i * j;`。

範例檔：examples/62-nested-for.cpp
```cpp
// 出處：自編示意例（語法依據 sources/06-learncpp-loops.md §8.10）
#include <iostream>

int main()
{
    for (int i = 1; i <= 9; ++i) {         // 外層：第幾列
        for (int j = 1; j <= 9; ++j) {     // 內層：每一列跑完 9 次
            std::cout << i * j;
            if (j < 9) {
                std::cout << '\t';          // \t 是 tab，讓數字對齊
            }
        }
        std::cout << '\n';
    }
    return 0;
}
```
實際輸出：
```text
1	2	3	4	5	6	7	8	9
2	4	6	8	10	12	14	16	18
3	6	9	12	15	18	21	24	27
4	8	12	16	20	24	28	32	36
5	10	15	20	25	30	35	40	45
6	12	18	24	30	36	42	48	54
7	14	21	28	35	42	49	56	63
8	16	24	32	40	48	56	64	72
9	18	27	36	45	54	63	72	81
```
（`'\t'` 是 tab 的跳脫序列 [03 §4.11]。）

### 條件怎麼寫：`<`、`<=`，不要用 `!=`
- 原站建議：數值的條件用 `<` 或 `<=`，不要用 `!=`。如果變數一次跳過好幾個數，可能剛好跳過終點，變成無窮迴圈 [06 §8.10]。
- `<` 和 `<=` 只差一個字，結果卻會差一輪，這叫**差一錯誤**（off-by-one error）[06 §8.10]，見[常見錯誤 #16](common-mistakes.md#16-差一錯誤)。
- `for (;;)` 也是無窮迴圈，但原站建議寫成 `while (true)`，比較清楚 [06 §8.10]。

## 常見誤解
- ❌「for 的初始化每一輪都會執行」→ 只在一開始執行一次 [06 §8.10]。
- ❌「更新是在主體之前執行」→ 是在主體**之後**執行 [06 §8.10]。
- ❌「`i < 5` 會跑到 5」→ 只跑到 4，見[常見錯誤 #16](common-mistakes.md#16-差一錯誤) [06 §8.10]。
- ❌「迴圈結束後還能用 `i`」→ 在 for 的初始化裡定義的變數，只在迴圈裡面有效 [06 §8.10]。

## 相關概念
[while 迴圈](while-loop.md)、[break 與 continue](break-continue.md)、[運算子](operators.md)、[新手常見錯誤](common-mistakes.md)

## 出處
[03] [../sources/03-learncpp-fundamental-types.md](../sources/03-learncpp-fundamental-types.md)：§4.11
[04] [../sources/04-learncpp-operators.md](../sources/04-learncpp-operators.md)：§6.2
[06] [../sources/06-learncpp-loops.md](../sources/06-learncpp-loops.md)：§8.10
