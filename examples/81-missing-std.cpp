// 出處：learncpp 0.8（改寫）→ sources/01-learncpp-program-structure.md
// 示範：編譯失敗
#include <iostream>

int main()
{
    cout << "Hello world!\n";   // ← 少了 std::
    return 0;
}
