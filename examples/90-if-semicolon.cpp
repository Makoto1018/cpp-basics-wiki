// 出處：learncpp 8.3（改寫）→ sources/05-learncpp-if-else.md
// 示範：warning
#include <iostream>

int main()
{
    int x = 5;
    if (x > 10);                // ← 多了一個分號：if 到這裡就結束了
    {
        std::cout << x << " is greater than 10\n";
    }
    return 0;
}
