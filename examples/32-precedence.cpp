// 出處：learncpp 1.9、6.1（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << 2 + 3 * 4 << '\n';     // 先乘後加
    std::cout << (2 + 3) * 4 << '\n';   // 括號先算
    std::cout << 7 - 4 - 1 << '\n';     // 同一級：由左到右
    return 0;
}
