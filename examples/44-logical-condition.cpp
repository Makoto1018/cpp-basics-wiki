// 出處：learncpp 6.8（改寫）→ sources/04-learncpp-operators.md
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int value = 0;
    std::cin >> value;
    if (value > 10 && value < 20) {
        std::cout << "Your value is between 10 and 20\n";
    } else {
        std::cout << "Your value is not between 10 and 20\n";
    }
    return 0;
}
