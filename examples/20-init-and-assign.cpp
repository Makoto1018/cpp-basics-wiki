// 出處：learncpp 1.4（改寫）→ sources/02-learncpp-variables.md
#include <iostream>

int main()
{
    int width = 5;              // 初始化：定義的同時給值
    std::cout << width << '\n';

    width = 7;                  // 賦值：存進新的值，舊的 5 被覆蓋
    std::cout << width << '\n';
    return 0;
}
