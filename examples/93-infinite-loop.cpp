// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
// 示範：無窮迴圈
#include <iostream>

int main()
{
    int count = 1;
    while (count <= 10) {
        std::cout << count << ' ';  // ← 忘了 ++count，count 永遠是 1
    }
    std::cout << "done!\n";
    return 0;
}
