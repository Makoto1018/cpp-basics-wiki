// 出處：learncpp 4.11（改寫）→ sources/03-learncpp-fundamental-types.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    char grade = "A";           // ← 字元要用單引號 'A'，雙引號是文字
    std::cout << grade << '\n';
    return 0;
}
