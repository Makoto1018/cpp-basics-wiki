// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    std::cout << "How many? ";
    int n = 0;
    std::cin >> n;              // 要重複幾次，執行時才知道
    int count = 1;
    while (count <= n) {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
