// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    int count = 15;
    while (count <= 10) {       // 一開始就是 false → 主體一次都不執行
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
