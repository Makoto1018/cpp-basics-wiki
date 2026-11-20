// 出處：learncpp 8.10（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int i = 5; i >= 1; --i) {      // 倒數
        std::cout << i << ' ';
    }
    std::cout << "liftoff!\n";
    for (int i = 0; i <= 10; i += 2) {  // 一次加 2
        std::cout << i << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
