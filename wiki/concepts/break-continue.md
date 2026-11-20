# break 與 continue

**一句話定義**：`break` **立刻結束整個迴圈**；`continue` **只結束這一輪**，直接進入下一輪 [06 §8.11]。
**先備概念**：[while 迴圈](while-loop.md)、[for 迴圈](for-loop.md)

## 白話解釋
用跑操場來想（本 wiki 的比喻）：
- `break`：不跑了，直接離開操場。
- `continue`：這一圈剩下的部分跳過，直接從下一圈開始跑。

| | `break` | `continue` |
|---|---|---|
| 結束什麼 | 整個迴圈 | 這一輪 |
| 接下來執行 | 迴圈**後面**的下一個敘述 | 下一輪（for 會先執行更新） |
| 出處 | [06 §8.11] | [06 §8.11] |

## 語法

### break：提早離開迴圈
- `break` 會結束 while 或 for 迴圈，程式從迴圈後面的下一個敘述繼續執行 [06 §8.11]。
- 它是離開故意寫的 `while (true)` 無窮迴圈最常見的方法 [06 §8.11]。
- 不要和 `return` 搞混：`break` 只結束迴圈，`return` 會結束整個函式 [06 §8.11]。在 `main` 裡寫 `return`，程式就結束了 [01 §1.1]。

下面的範例會一直讀數字，直到讀到 0 才停下來，最後印出總和。要讀幾個數字事先不知道，所以用 `while (true)` 加上 `break`：

範例檔：examples/70-break-sum.cpp
```cpp
// 出處：learncpp 8.11（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    int sum = 0;
    while (true) {              // 故意寫成無窮迴圈，靠 break 離開
        int num = 0;
        std::cin >> num;
        if (num == 0) { break; }    // 輸入 0 → 立刻離開迴圈
        sum += num;
    }
    std::cout << "Sum: " << sum << '\n';
    return 0;
}
```
輸入（`examples/70-break-sum.in`）：
```text
3 5 2 0
```
實際輸出：
```text
Sum: 10
```
（讀到 3、5、2 時都加進 sum；讀到 0 時執行 `break`，所以 `sum += num;` 沒有執行，直接跳到印出總和。）

### continue：跳過這一輪
- `continue` 結束**這一輪**，但不結束整個迴圈；它會直接跳到主體的最後面 [06 §8.11]。
- 在 for 迴圈裡，continue 之後**更新（例如 `++count`）仍然會執行**，因為更新本來就是在主體之後執行 [06 §8.11]。
- 最適合放在主體的開頭，用來「遇到某種情況就跳過這一輪」，可以少寫一層巢狀 [06 §8.11]。

範例檔：examples/71-continue.cpp
```cpp
// 出處：learncpp 8.11（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int count = 0; count < 10; ++count) {
        if (count % 4 == 0) {
            continue;           // 跳過這一輪剩下的部分，直接去做 ++count
        }
        std::cout << count << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出：
```text
1 2 3 5 6 7 9 done!
```
（0、4、8 可以被 4 整除，那三輪都跳過了，不會印出來。）

> ⚠️ 在 **while** 迴圈裡用 continue 要特別小心：如果更新迴圈變數的那一行在 continue 後面，就會被跳過，變成無窮迴圈 [06 §8.11]，見[常見錯誤 #17](common-mistakes.md#17-continue-跳過了更新)。

### 要不要用？
- 很多教科書反對用 break 和 continue，因為程式的流程會跳來跳去，比較難追蹤 [06 §8.11]。
- 但適當使用可以減少巢狀，也不用多寫一個布林變數 [06 §8.11]。
- 原站建議：**能讓迴圈邏輯更簡單時就用** [06 §8.11]。

> 本 wiki 的風格是 if 的主體一律加大括號。`70-break-sum.cpp` 為了符合 15 行限制，把 `if (num == 0) { break; }` 寫在同一行（見 CLAUDE.md）。

> 範圍外：`break` 也用在 `switch` 裡 [06 §8.11]，本 wiki 不介紹 switch。

## 常見誤解
- ❌「`continue` 會結束迴圈」→ 只結束這一輪，迴圈還會繼續 [06 §8.11]。
- ❌「`break` 會結束整個程式」→ 只結束迴圈；結束函式的是 `return` [06 §8.11]。
- ❌「continue 在 while 和 for 裡效果一樣」→ for 會在 continue 之後執行更新；while 沒有這個機制，更新那一行可能被跳過 [06 §8.11]。

## 相關概念
[while 迴圈](while-loop.md)、[for 迴圈](for-loop.md)、[新手常見錯誤](common-mistakes.md)

## 出處
[01] [../sources/01-learncpp-program-structure.md](../sources/01-learncpp-program-structure.md)：§1.1
[06] [../sources/06-learncpp-loops.md](../sources/06-learncpp-loops.md)：§8.11
