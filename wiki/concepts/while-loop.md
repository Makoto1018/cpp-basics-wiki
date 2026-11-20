# while 迴圈

**一句話定義**：迴圈（loop）讓一段程式**重複執行**；while 迴圈在條件成立時一直重複執行主體，直到條件變成 `false` 為止 [06 §8.8]。
**先備概念**：[if-else](if-else.md)、[運算子](operators.md)（`++` 和比較運算子）

## 白話解釋
要印出 1 到 10，一行一行寫 `std::cout` 還做得到；但如果要印幾個數字，**執行時才知道**（例如由使用者輸入），就沒辦法事先寫好了 [06 §8.8]。迴圈就是用來解決這個問題的。原站說，控制流程，尤其是迴圈，讓程式能做真正有用的事 [05 §8.1]。

while 和 if 長得很像。差別在於：**if 的主體最多執行一次，while 的主體可以執行很多次** [06 §8.8]。可以想成「會一直回頭再檢查一次的 if」（本 wiki 的比喻）。

## 語法
```text
while (條件) {
    主體
}
```
每一次的流程是 [06 §8.8]：
1. 檢查條件。
2. `true` → 執行主體，然後**回到第 1 步**。
3. `false` → 結束迴圈，接著執行迴圈後面的敘述。

一些名詞 [06 §8.8]：
- 主體每執行一次，叫做**一輪**（iteration）。
- 控制迴圈要跑幾次的變數，叫做**迴圈變數**（loop variable）。最常見的是計數器（counter），用來數「已經跑了幾輪」。
- 主體裡一定要**更新迴圈變數**，條件才有機會變成 `false`。

範例檔：examples/50-while-count.cpp
```cpp
// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    int count = 1;
    while (count <= 10) {       // 每一輪開始前都先檢查條件
        std::cout << count << ' ';
        ++count;                // 更新變數，條件才有機會變成 false
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出：
```text
1 2 3 4 5 6 7 8 9 10 done!
```
（count 變成 11 時，`count <= 10` 是 `false`，迴圈結束，接著印出 `done!`。）

### 條件一開始就不成立
一開始條件就是 `false` 的話，主體**一次都不會執行** [06 §8.8]。

範例檔：examples/51-while-false-start.cpp
```cpp
// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    int count = 15;
    while (count <= 10) {       // 一開始就是 false → 主體一次都不執行
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
```
實際輸出：
```text
done!
```

### 次數到執行時才知道
範例檔：examples/52-while-user-count.cpp
```cpp
// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    std::cout << "How many? ";
    int n = 0;
    std::cin >> n;              // 要重複幾次，執行時才知道
    int count = 1;
    while (count <= n) {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
```
輸入（`examples/52-while-user-count.in`）：
```text
5
```
實際輸出：
```text
How many? 1 2 3 4 5 done!
```

### 無窮迴圈
- 條件**永遠成立**的迴圈，叫做無窮迴圈（infinite loop）。最常見的原因是忘了更新迴圈變數 [06 §8.8]，見[常見錯誤 #14](common-mistakes.md#14-忘了更新迴圈變數)。
- while 條件後面多一個分號，也會變成無窮迴圈 [06 §8.8]，見[常見錯誤 #15](common-mistakes.md#15-while-條件後面多了分號)。
- 有時候是**故意**寫無窮迴圈，原站建議寫成 `while (true)`，再用 `break` 離開 [06 §8.8、§8.11]，見 [break 與 continue](break-continue.md)。

### 迴圈變數的命名
迴圈變數常被取名為 `i`、`j`、`k`，但這種名字很難搜尋，可以考慮用 `count`、`index` 這類有意義的名字 [06 §8.8]。

## 常見誤解
- ❌「while 的主體至少會執行一次」→ 條件一開始就是 `false` 的話，一次都不會執行 [06 §8.8]。
- ❌「條件裡用到的變數會自己改變」→ 必須在主體裡自己更新，否則就是無窮迴圈 [06 §8.8]。
- ❌「while 後面加分號沒關係」→ 主體會變成空的，程式卡住 [06 §8.8]。

## 小測驗：預測輸出
先想想看這段程式會印出什麼，再點開答案。這個範例故意不寫註解，避免洩漏答案；內容和 `51-while-false-start.cpp` 相同。

範例檔：examples/53-quiz-while.cpp
```cpp
// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    int count = 15;
    while (count <= 10) {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
```
<details><summary>答案</summary>

實際輸出：
```text
done!
```
`count` 一開始是 15，第一次檢查 `count <= 10` 就是 `false`，所以主體一次都不執行 [06 §8.8]。
</details>

## 相關概念
[if-else](if-else.md)、[for 迴圈](for-loop.md)（有計數器時更好用）、[break 與 continue](break-continue.md)、[新手常見錯誤](common-mistakes.md)

## 出處
[05] [../sources/05-learncpp-if-else.md](../sources/05-learncpp-if-else.md)：§8.1
[06] [../sources/06-learncpp-loops.md](../sources/06-learncpp-loops.md)：§8.8、§8.11
