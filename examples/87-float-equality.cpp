// 出處：learncpp 6.7（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << (0.3 == 0.2 + 0.1) << '\n';    // ← 數學上相等，程式卻說不相等
    return 0;
}
