// 出處：learncpp 4.10（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x = 0;
    std::cin >> x;
    if (x == 0) {
        std::cout << "The value is zero\n";
    }
    std::cout << "Done\n";
    return 0;
}
