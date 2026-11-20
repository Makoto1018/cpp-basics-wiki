// 出處：learncpp 8.11（改寫）→ sources/06-learncpp-loops.md
// 示範：無窮迴圈
#include <iostream>

int main()
{
    int count = 0;
    while (count < 10) {
        if (count == 5) {
            continue;           // ← 跳過了下面的 ++count，count 永遠停在 5
        }
        std::cout << count << '\n';
        ++count;
    }
    return 0;
}
