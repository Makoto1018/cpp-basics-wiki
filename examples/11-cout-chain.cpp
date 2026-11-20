// 出處：learncpp 1.5（改寫）→ sources/01-learncpp-program-structure.md
#include <iostream>

int main()
{
    std::cout << "Hi!" << '\n';                 // 用 << 串接：先印文字，再印換行
    std::cout << "My name is " << "Alex." << '\n';
    return 0;
}
