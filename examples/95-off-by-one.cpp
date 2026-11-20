// 出處：learncpp 8.10（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int i = 1; i < 5; ++i) {   // ← 想印 1 到 5，但條件寫成 < 5
        std::cout << i << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
