// 出處：learncpp 1.5（改寫）→ sources/01-learncpp-program-structure.md
// 示範：warning
#include <iostream>

int main()
{
    std::cout << "Hello" << '/n';   // ← 斜線方向寫反了，應該是 '\n'
    return 0;
}
