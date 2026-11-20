// 出處：learncpp 4.11（改寫）→ sources/03-learncpp-fundamental-types.md
#include <iostream>

int main()
{
    char grade = 'A';           // 字元用單引號
    char digit = '5';           // 這是「字元 5」，不是整數 5
    std::cout << "Grade: " << grade << '\n';
    std::cout << "Digit: " << digit << '\n';
    return 0;
}
