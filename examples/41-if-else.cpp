// 出處：learncpp 8.2（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x = 0;
    std::cin >> x;
    if (x > 10) {
        std::cout << x << " is greater than 10\n";
    } else {
        std::cout << x << " is not greater than 10\n";
    }
    return 0;
}
