// 出處：learncpp 4.9（改寫）→ sources/03-learncpp-fundamental-types.md
#include <iostream>

int main()
{
    bool isRaining = true;
    bool isSunny = false;
    std::cout << isRaining << ' ' << isSunny << '\n';   // 預設印出 1 和 0
    std::cout << std::boolalpha;                         // 之後改印 true / false
    std::cout << isRaining << ' ' << isSunny << '\n';
    return 0;
}
