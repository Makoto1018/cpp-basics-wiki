// 出處：自編示意例（語法依據 sources/06-learncpp-loops.md §8.10）
#include <iostream>

int main()
{
    for (int i = 1; i <= 9; ++i) {         // 外層：第幾列
        for (int j = 1; j <= 9; ++j) {     // 內層：每一列跑完 9 次
            std::cout << i * j;
            if (j < 9) {
                std::cout << '\t';          // \t 是 tab，讓數字對齊
            }
        }
        std::cout << '\n';
    }
    return 0;
}
