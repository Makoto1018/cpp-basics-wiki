// 出處：learncpp 8.2（改寫）→ sources/05-learncpp-if-else.md
// 示範：warning
#include <iostream>

int main()
{
    int x = 5;
    if (x > 10)
        std::cout << "x is big\n";
    else
        std::cout << "x is small\n";
        std::cout << "Too bad!\n";  // ← 看起來屬於 else，其實不是
    return 0;
}
