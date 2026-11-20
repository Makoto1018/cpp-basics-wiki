// 出處：learncpp 8.8（改寫）→ sources/06-learncpp-loops.md
// 示範：無窮迴圈
// 示範：warning
#include <iostream>

int main()
{
    int count = 1;
    while (count <= 10);        // ← 多了分號：迴圈主體變成「什麼都不做」
    {
        std::cout << count << ' ';
        ++count;
    }
    std::cout << "done!\n";
    return 0;
}
