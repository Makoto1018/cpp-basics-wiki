// 出處：learncpp 8.11（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int count = 0; count < 10; ++count) {
        if (count % 4 == 0) {
            continue;           // 跳過這一輪剩下的部分，直接去做 ++count
        }
        std::cout << count << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
