// 出處：learncpp 8.10（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    for (int i = 1; i <= 10; ++i) {     // 初始化; 條件; 更新
        std::cout << i << ' ';
    }
    std::cout << "done!\n";
    return 0;
}
