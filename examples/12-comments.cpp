// 出處：自編示意例（語法依據 sources/01-learncpp-program-structure.md §1.2）
#include <iostream>

int main()
{
    // 單行註解：從 // 到這行結尾都會被編譯器忽略
    std::cout << "Hello\n"; // 註解也可以放在程式碼右邊
    /* 多行註解：
       可以跨好幾行 */
    // std::cout << "Bye\n";   ← 被「註解掉」的程式碼，不會執行
    return 0;
}
