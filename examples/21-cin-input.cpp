// 出處：learncpp 1.5（改寫）→ sources/01-learncpp-program-structure.md
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x = 0;                  // 先初始化，再讀入
    std::cin >> x;              // 程式停在這裡，等使用者輸入
    std::cout << "You entered " << x << '\n';
    return 0;
}
