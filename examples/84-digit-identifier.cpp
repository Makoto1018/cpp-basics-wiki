// 出處：learncpp 1.7（改寫）→ sources/02-learncpp-variables.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    int 1x = 5;                 // ← 識別字不能用數字開頭
    std::cout << 1x << '\n';
    return 0;
}
