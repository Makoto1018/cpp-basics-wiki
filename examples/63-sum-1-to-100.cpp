// 出處：自編示意例（語法依據 sources/06-learncpp-loops.md §8.10、sources/04-learncpp-operators.md §6.2）
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i;               // 每一輪把 i 加進 sum
    }
    std::cout << "1 + 2 + ... + 100 = " << sum << '\n';
    return 0;
}
