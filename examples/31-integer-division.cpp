// 出處：learncpp 6.2（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int x = 7;
    int y = 4;
    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "7.0 / 4 = " << 7.0 / 4 << '\n';
    return 0;
}
