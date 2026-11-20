// 出處：learncpp 6.2、6.4（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int x = 5;
    x += 4;                     // 等於 x = x + 4
    std::cout << x << '\n';
    x -= 2;                     // 等於 x = x - 2
    std::cout << x << '\n';
    ++x;                        // 遞增：加 1
    std::cout << x << '\n';
    --x;                        // 遞減：減 1
    std::cout << x << '\n';
    return 0;
}
