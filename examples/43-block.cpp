// 出處：learncpp 7.1（改寫）→ sources/05-learncpp-if-else.md
#include <iostream>

int main()
{
    int value = 0;
    std::cin >> value;
    if (value >= 0) {
        std::cout << value << " is a positive integer (or zero)\n";
        std::cout << "Double this number is " << value * 2 << '\n';
    } else {
        std::cout << value << " is a negative integer\n";
        std::cout << "The positive of this number is " << -value << '\n';
    }
    return 0;
}
