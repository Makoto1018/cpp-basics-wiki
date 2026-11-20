// 出處：learncpp 6.1、6.3（改寫）→ sources/04-learncpp-operators.md
// 示範：warning
#include <iostream>

int main()
{
    std::cout << (2 ^ 3) << '\n';   // ← 想算 2 的 3 次方，但 ^ 不是次方
    return 0;
}
