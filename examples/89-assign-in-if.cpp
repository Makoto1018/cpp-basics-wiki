// 出處：learncpp 8.3（改寫）→ sources/05-learncpp-if-else.md
// 示範：warning
#include <iostream>

int main()
{
    std::cout << "Enter 0 or 1: ";
    int x = 0;
    std::cin >> x;
    if (x = 0) {                // ← 應該是 ==，這裡變成「把 0 賦值給 x」
        std::cout << "You entered 0\n";
    } else {
        std::cout << "You entered 1\n";
    }
    return 0;
}
