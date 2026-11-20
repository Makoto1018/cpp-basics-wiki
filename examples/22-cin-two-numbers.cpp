// 出處：learncpp 1.5（改寫）→ sources/01-learncpp-program-structure.md
#include <iostream>

int main()
{
    std::cout << "Enter two numbers separated by a space: ";
    int x = 0;
    int y = 0;
    std::cin >> x >> y;         // 一次讀兩個值，用空白分開
    std::cout << "You entered " << x << " and " << y << '\n';
    return 0;
}
