// 出處：learncpp 6.8（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int value = 15;
    std::cout << std::boolalpha;
    std::cout << (value > 10 && value < 20) << '\n';    // 兩個都成立才 true
    std::cout << (value == 0 || value == 1) << '\n';    // 任一個成立就 true
    std::cout << !(value > 10) << '\n';                 // 反過來
    return 0;
}
