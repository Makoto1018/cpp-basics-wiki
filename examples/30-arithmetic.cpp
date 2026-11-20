// 出處：learncpp 6.2、6.3（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << 7 + 4 << '\n';     // 加
    std::cout << 7 - 4 << '\n';     // 減
    std::cout << 7 * 4 << '\n';     // 乘
    std::cout << 7 / 4 << '\n';     // 除：兩邊都是整數 → 整數除法
    std::cout << 7 % 4 << '\n';     // 餘數
    return 0;
}
