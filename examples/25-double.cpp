// 出處：learncpp 4.8（改寫）→ sources/03-learncpp-fundamental-types.md
#include <iostream>

int main()
{
    double price = 5.0;
    double height = 6.7;
    double big = 9876543.21;
    std::cout << price << '\n';     // 小數部分是 0 時，不會印出 .0
    std::cout << height << '\n';
    std::cout << big << '\n';       // 預設只顯示 6 位有效數字
    return 0;
}
