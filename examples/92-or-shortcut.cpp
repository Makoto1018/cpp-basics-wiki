// 出處：learncpp 6.8（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    int value = 5;
    if (value == 0 || 1) {      // ← 想檢查「value 是 0 或 1」，但寫錯了
        std::cout << "value is 0 or 1\n";
    }
    return 0;
}
