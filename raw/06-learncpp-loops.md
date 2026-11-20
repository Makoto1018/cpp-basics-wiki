---
title: learncpp — 迴圈
site: https://www.learncpp.com/
retrieved: 2026-11-20
format: 摘錄筆記（非全文；由 Claude Code 以 web-fetch 逐篇讀取原頁後擷取，程式碼為原頁原文）
lessons:
  - id: "8.8"
    title: Introduction to loops and while statements
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
  - id: "8.9"
    title: Do while statements（延伸閱讀，可選）
    url: https://www.learncpp.com/cpp-tutorial/do-while-statements/
  - id: "8.10"
    title: For statements
    url: https://www.learncpp.com/cpp-tutorial/for-statements/
  - id: "8.11"
    title: Break and continue
    url: https://www.learncpp.com/cpp-tutorial/break-and-continue/
---

> 收錄 lesson：8.8、8.9、8.10、8.11
> 這是**摘錄筆記**，不是全文轉載：重點為忠實改述（保留原站英文用語），引號內為原文短句，程式碼區塊為原頁原文。
> 本檔為唯讀原始資料，ingest 時不可修改。

## 8.8 Introduction to loops and while statements
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/ -->

### Key points
- A loop is a control flow construct that lets a piece of code run repeatedly until some condition is met.
- Motivation: writing out each printed line by hand works for 1 to 10, but not when the count is only known at run time (for example, a number the user enters).
- The while statement (while loop) is the simplest of the three loop types in C++. Its form is `while (condition)` followed by a statement, similar to an if-statement.
- Each time a while statement runs, the condition is evaluated. If it is true, the statement runs, and then control returns to the top and the condition is evaluated again. Unlike an if-statement, the body can run many times.
- If the condition is false at the start, the body is skipped entirely. The page's example with `count` set to 15 prints only `done!`.
- An infinite loop is one whose condition always stays true. The page's example never increments `count`, so it prints `1` forever.
- An intentional infinite loop is written `while (true)`. The page lists the ways out: a return-statement, a break-statement, an exit-statement, a goto-statement, a thrown exception, or the user killing the program. It notes this pattern is common in continuously running web server applications.
- A semicolon placed after a while condition makes the body a null statement. The loop then does nothing forever and the program appears hung. The page contrasts this with if-statements, where a trailing semicolon is always a mistake. It also gives an intentional use: `while (keepRunning());` keeps calling a function until it returns false.
- A loop variable is a variable that controls how many times a loop executes (for example `count`). A counter is the most common kind: a loop variable that counts how many times the loop has run.
- Loop variables are often named `i`, `j`, or `k`. The page notes these are hard to search for, and suggests more unique names or real names such as `count`, `index`, or `userCount`.
- Each execution of the loop body is an iteration. The remainder operator (`%`) on the counter can trigger an action every Nth iteration, such as printing a newline when `count % 10 == 0`.
- Integral loop variables should almost always be signed. In the page's unsigned countdown example, `count >= 0` is never false: after `0` the value wraps to `4294967295` (assuming 32-bit integers), so the loop never ends.
- Nested loops are a loop inside another loop. Declaring the inner loop variable inside the outer loop body means it is recreated and reinitialized on each outer iteration. The page advises declaring variables in the smallest scope possible.

### Code examples
```cpp
#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done!\n";

    return 0;
}
```
Output shown on page:
```text
1 2 3 4 5 6 7 8 9 10 done!
```

```cpp
#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10) // this condition will never be false
    {
        std::cout << count << ' '; // so this line will repeatedly execute
    }

    std::cout << '\n'; // this line will never execute

    return 0; // this line will never execute
}
```

### Best practice / Warnings
- Best practice: Favor `while(true)` for intentional infinite loops.
- Best practice: Integral loop variables should generally be a signed integral type.
- Warning: Be careful about placing a semicolon after the condition of a while-statement. It results in an infinite loop unless the condition can somehow become false.

## 8.9 Do while statements（延伸閱讀，可選）
<!-- 來源：https://www.learncpp.com/cpp-tutorial/do-while-statements/ -->

### Key points
- Motivating problem: showing a menu and re-asking until the user picks a valid option. A while loop checks its condition first, which makes this awkward.
- Workaround 1: initialize the selection to 0 so the loop starts. This only works if 0 is not a valid choice, and it introduces magic numbers.
- Workaround 2: add a separate bool (`invalid`) to gate the loop. This avoids the magic number but adds a variable and more room for errors.
- The do-while statement has the form `do` statement `while (condition);`, with a semicolon after the condition.
- It works like a while loop, except the statement always executes at least once. After it runs, the condition is checked, and if true, execution jumps back to the top of the do block.
- Because the condition is evaluated after the block, a variable used in that condition must be declared outside the do block. Otherwise it is destroyed before the condition is checked.
- The page says do-while loops are not common in practice. A condition at the bottom obscures the loop condition and can lead to errors, so many developers recommend avoiding them. The page takes a softer stance and prefers while loops when the choice is otherwise equal.

### Code examples
```cpp
do
    statement; // can be a single statement or a compound statement
while (condition);
```

### Best practice / Warnings
- Best practice: Favor while loops over do-while when given an equal choice.

## 8.10 For statements
<!-- 來源：https://www.learncpp.com/cpp-tutorial/for-statements/ -->

### Key points
- The for statement (for loop) is the most used loop in C++. It is preferred when there is an obvious loop variable, because it defines, initializes, tests, and changes loop variables in one place.
- As of C++11 there are two kinds of for loops: the classic for statement (this lesson) and the range-based for statement (covered in a later lesson).
- Syntax: `for (init-statement; condition; end-expression)` followed by a statement.
- The page's easiest way to understand it is an equivalent while loop: the init-statement goes in an enclosing block before the loop, the condition becomes the while condition, and the end-expression is the last line of the body. The outer braces are needed because the loop variable goes out of scope when the loop ends.
- The init-statement runs once, when the loop starts. Variables defined there have "loop scope" and exist from their definition through the end of the loop.
- Execution order: init-statement, then condition (if false, the loop ends), then loop body, then end-expression, then back to the condition.
- The end-expression runs after the body, so the loop variable is changed before the condition is checked again.
- Variants shown on the page include counting down with `--i` and stepping by 2 with `i += 2`. A `pow()` example uses a for loop with `i` from 0 up to, but not including, `exponent`.
- For numeric conditions, prefer `<` or `<=` over `!=`. With `!=`, the loop never ends if the variable jumps over the end value. The page's example shows the `<` loop still terminates, while the `!=` loop becomes infinite.
- Off-by-one errors happen when a loop runs one time too many or too few. Using `i < 5` instead of `i <= 5` prints `1 2 3 4` instead of `1 2 3 4 5`. The page also says mixing pre- and post-increment can cause them.
- Any part of the for statement may be omitted. The page says `for (;;)` is an infinite loop equivalent to `while (true)`, because the standard treats an omitted condition as true. It calls this inconsistent and recommends `while (true)` instead.
- Multiple counters: the init-statement can define several variables, and the end-expression can use the comma operator to change them. The page calls this about the only place in C++ where this is considered acceptable.
- Nested for loops: the inner loop runs in its entirety on each iteration of the outer loop.
- Variables used only inside a loop should be defined inside the loop. Creating a variable has no cost, but the page says a wider scope can make the program harder to read and possibly slower to optimize.
- Conclusion: use for when there is a counter variable. Use while when there is no counter.

### Code examples
```cpp
#include <iostream>

int main()
{
    for (int i{ 1 }; i <= 10; ++i)
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}
```
Output shown on page:
```text
1 2 3 4 5 6 7 8 9 10
```

```cpp
#include <iostream>

int main()
{
    for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y)
        std::cout << x << ' ' << y << '\n';

    return 0;
}
```
Output shown on page:
```text
0 9
1 8
2 7
3 6
4 5
5 4
6 3
7 2
8 1
9 0
```

```cpp
#include <iostream>

int main()
{
    { // the block here ensures block scope for i
        int i{ 1 }; // our init-statement
        while (i <= 10) // our condition
        {
            std::cout << i << ' '; // our statement
            ++i; // our end-expression
        }
    }

    std::cout << '\n';
}
```

### Best practice / Warnings
- Key insight (execution order): init-statement; condition (loop ends here if false); loop body; end-expression; then back to the condition.
- Best practice: Avoid `operator!=` when doing numeric comparisons in the for-loop condition. Prefer `operator<` or `operator<=` where possible.
- Best practice: Defining multiple variables in the init-statement and using the comma operator in the end-expression is acceptable inside a for-statement.
- Best practice: Variables used only inside a loop should be defined inside the scope of the loop.
- Best practice: Prefer for-loops over while-loops when there is an obvious loop variable. Prefer while-loops when there is no obvious loop variable.
- Body text (not a box): the page recommends avoiding `for (;;)` and using `while (true)` instead.

## 8.11 Break and continue
<!-- 來源：https://www.learncpp.com/cpp-tutorial/break-and-continue/ -->

### Key points
- The break statement ends a while loop, do-while loop, for loop, or switch statement. Execution continues with the next statement after the loop or switch.
- In a switch, a break at the end of each case prevents fallthrough into the next case. The page points to lesson 8.6 for more on fallthrough.
- In a loop, break ends the loop early. The page's example lets the user enter up to 10 numbers, stops when 0 is entered, and then prints the sum.
- break is also a common way to leave an intentional `while (true)` infinite loop.
- break versus return: break ends only the switch or loop, and execution resumes after it. return ends the entire function, and execution resumes where the function was called.
- The continue statement ends the current iteration of a loop without terminating the whole loop. Execution jumps to the bottom of the loop body.
- In a for loop, the end-expression still runs after continue, because it runs after the body.
- In while and do-while loops, continue can skip the lines that change the condition variable. The page's example never increments `count` after it reaches 5, so the program prints 0 to 4 and then loops forever.
- The page notes that if there is an obvious counter, a for loop should be used instead of a while or do-while loop.
- The page says many textbooks warn against break and continue because they make the flow jump around and harder to follow. Used judiciously, though, they can reduce nested blocks and the need for Boolean control variables.
- The page's example replaces a Boolean `keepLooping` flag with `while (true)` and a single break. This removes the flag, the else, and the nested block.
- continue is most effective at the top of a for loop, to skip iterations when a condition is met and avoid a nested block.
- An early return is a return that is not the last statement in a function. The page says early returns are more helpful than harmful, while acknowledging there is "a bit of art" to the practice. A middle ground is early returns only for parameter validation.

### Code examples
Fragment (the page's complete program wraps this in main()):
```cpp
for (int count{ 0 }; count < 10; ++count)
{
    // if the number is divisible by 4, skip this iteration
    if ((count % 4) == 0)
        continue; // go to next iteration

    // If the number is not divisible by 4, keep going
    std::cout << count << '\n';

    // The continue statement jumps to here
}
```
Output shown on page:
```text
1
2
3
5
6
7
9
```

Fragment (the page's complete program wraps this in main()):
```cpp
int count{ 0 };
while (count < 10)
{
    if (count == 5)
        continue; // jump to end of loop body

    std::cout << count << '\n';

    ++count; // this statement is never executed after count reaches 5

    // The continue statement jumps to here
}
```
Output shown on page (the page says the program then loops forever):
```text
0
1
2
3
4
```

### Best practice / Warnings
- Best practice: Use break and continue when they simplify your loop logic.
- Best practice: Use early returns when they simplify your function's logic.
