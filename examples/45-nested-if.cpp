// 出處：learncpp 8.3（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    int x = 25;
    if (x >= 0) {                   // 外層的 if
        if (x <= 20) {              // 內層的 if：外層成立才會檢查
            std::cout << x << " is between 0 and 20\n";
        } else {                    // 這個 else 屬於內層的 if
            std::cout << x << " is greater than 20\n";
        }
    }
    return 0;
}
