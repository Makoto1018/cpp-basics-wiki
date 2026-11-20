// 出處：learncpp 8.11（改寫）→ sources/06-learncpp-loops.md
#include <iostream>

int main()
{
    int sum = 0;
    while (true) {              // 故意寫成無窮迴圈，靠 break 離開
        int num = 0;
        std::cin >> num;
        if (num == 0) { break; }    // 輸入 0 → 立刻離開迴圈
        sum += num;
    }
    std::cout << "Sum: " << sum << '\n';
    return 0;
}
