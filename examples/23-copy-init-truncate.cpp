// 出處：learncpp 1.4（改寫）→ sources/02-learncpp-variables.md
#include <iostream>

int main()
{
    int w = 4.5;                // 用 = 初始化：4.5 不是整數，但編譯器照樣接受
    std::cout << w << '\n';
    return 0;
}
