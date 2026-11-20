// 出處：learncpp 6.7（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int a = 5;
    int b = 3;
    std::cout << std::boolalpha;    // 印出 true / false
    std::cout << (a > b) << '\n';
    std::cout << (a < b) << '\n';
    std::cout << (a >= 5) << '\n';
    std::cout << (a == b) << '\n';
    std::cout << (a != b) << '\n';
    return 0;
}
