// 出處：自編示意例（語法依據 sources/05-learncpp-if-else.md §4.10）
#include <iostream>

int main()
{
    int score = 0;
    std::cin >> score;
    if (score >= 90) {
        std::cout << "Grade A\n";
    } else if (score >= 60) {
        std::cout << "Pass\n";
    } else {
        std::cout << "Failed\n";
    }
    return 0;
}
