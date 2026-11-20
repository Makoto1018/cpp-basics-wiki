// 出處：learncpp 6.3（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << 10 % 2 << '\n';    // 0 → 10 可以被 2 整除
    std::cout << 7 % 2 << '\n';     // 1
    std::cout << 2 % 4 << '\n';     // 被除數比較小 → 餘數就是它自己
    std::cout << -6 % 4 << '\n';    // 結果的正負號跟著左邊
    return 0;
}
