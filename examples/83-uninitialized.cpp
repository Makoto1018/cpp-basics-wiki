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
