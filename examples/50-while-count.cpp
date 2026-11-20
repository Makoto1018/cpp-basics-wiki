// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    int count = 1;
    while (count <= 10) {       // 每一輪開始前都先檢查條件
        std::cout << count << ' ';
        ++count;                // 更新變數，條件才有機會變成 false
    }
    std::cout << "done!\n";
    return 0;
}
