// 出處：learncpp 6.2（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    double average = 7 / 2;     // ← 兩邊都是整數，先做整數除法得到 3，才存進 double
    std::cout << average << '\n';
    return 0;
}
