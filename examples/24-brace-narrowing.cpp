// 出處：learncpp 1.4（改寫）→ sources/02-learncpp-variables.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    int w{4.5};                 // 用大括號初始化：編譯器會擋下來
    std::cout << w << '\n';
    return 0;
}
