---
title: learncpp — if-else
site: https://www.learncpp.com/
retrieved: 2026-11-20
format: 摘錄筆記（非全文；由 Claude Code 以 web-fetch 逐篇讀取原頁後擷取，程式碼為原頁原文）
lessons:
  - id: "4.10"
    title: Introduction to if statements
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/
  - id: "7.1"
    title: Compound statements (blocks)
    url: https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/
  - id: "8.1"
    title: Control flow introduction
    url: https://www.learncpp.com/cpp-tutorial/control-flow-introduction/
  - id: "8.2"
    title: If statements and blocks
    url: https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/
  - id: "8.3"
    title: Common if statement problems
    url: https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/
---

> 收錄 lesson：4.10、7.1、8.1、8.2、8.3
> 這是**摘錄筆記**，不是全文轉載：重點為忠實改述（保留原站英文用語），引號內為原文短句，程式碼區塊為原頁原文。
> 本檔為唯讀原始資料，ingest 時不可修改。

## 4.10 Introduction to if statements
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-if-statements/ -->

### Key points
- An if statement executes one (or more) lines of code only if a condition is true. The simplest form is `if (condition) true_statement;`, usually written with the statement on the next indented line.
- A condition (also called a conditional expression) is an expression that evaluates to a Boolean value.
- If the condition is true, true_statement executes; if it is false, true_statement is skipped.
- The equality operator (==) returns true if its operands are equal and false if they are not.
- Warning box: an if statement only conditionally executes a single statement; running multiple statements conditionally requires a block, covered in lesson 8.2.
- The if-else form, `if (condition) true_statement; else false_statement;`, runs exactly one of the two statements. The page says two separate if statements testing x == 0 and x != 0 are "more complex than they need to be."
- Statements can be chained by adding an `else if`, and as many conditions as needed can be chained. The less-than (<) and greater-than (>) operators also return Boolean values.
- A function that returns bool can be used directly as the condition, as in the isEqual() example.
- A non-Boolean condition is converted to bool: non-zero values become true and zero becomes false. The page's example prints "hi" for `int x { 4 };` because 4 is non-zero.
- An early return is a return statement that is not the last statement in a function. Combined with an if statement, it can return a value only under some conditions (the page's abs() example returns -x only when x < 0).
- An unconditional early return is not useful, since any code after it never runs. The page says early returns were historically frowned upon but are more accepted in modern programming, particularly to simplify a function or abort it on an error.
- Quiz 3 solution: an `if (condition) return true; else return false;` pattern can be replaced by the single statement `return condition`.
- Quiz 2 (prime digit check): the page shows an if-else chain, and mentions that advanced readers could use the logical OR (||) operator or a switch statement instead (covered in later lessons).

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x == 0)
        std::cout << "The value is zero\n";

    return 0;
}
```
Output shown on page (two runs; with input 5, nothing further is printed):
```text
Enter an integer: 0
The value is zero

Enter an integer: 5
```

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;

    if (x == 0)
        std::cout << "The value is zero\n";
    else
        std::cout << "The value is non-zero\n";

    return 0;
}
```
Output shown on page:
```text
Enter an integer: 0
The value is zero

Enter an integer: 5
The value is non-zero
```

```cpp
#include <iostream>

int main()
{
    int x { 4 };
    if (x) // nonsensical, but for the sake of example...
        std::cout << "hi\n";
    else
        std::cout << "bye\n";

    return 0;
}
```
Output shown on page:
```text
hi
```

### Best practice / Warnings
- Warning: if statements only conditionally execute a single statement. Use a block (see lesson 8.2) to conditionally execute multiple statements.
- Key insight: `if (x)` means "if x is non-zero/non-empty".

## 7.1 Compound statements (blocks)
<!-- 來源：https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/ -->

### Key points
- A compound statement (also called a block, or block statement) is a group of zero or more statements that the compiler treats as if it were a single statement.
- A block begins with `{` and ends with `}`, with the statements to be executed placed in between. No semicolon is needed after the closing brace.
- Blocks can be used anywhere a single statement is allowed. The page notes that a function body is a block, and that a declaration like `int value {};` inside a block is initialization, not a block.
- Blocks can be nested inside other blocks, although functions cannot be nested inside other functions. The enclosing block is the outer block; the enclosed one is the inner or nested block.
- The most common use of blocks is with if statements: a block replaces the single statement so that several statements run when the condition is true. The page's example has one block after `if (value >= 0)` and another after `else`.
- The nesting level (nesting depth) of a function is the maximum number of nested blocks you can be inside at any point in the function, counting the outer block. The page's example has 4 blocks but a nesting level of 3.
- The C++ standard says compilers should support 256 levels of nesting, but the page notes not all do; it says Visual Studio supports fewer.
- Overly nested blocks are hard to read and are good candidates for refactoring, with the most-nested blocks becoming separate functions.

### Code examples
Fragment of the page's full program (the if/else portion, as written on the page):
```cpp
    if (value >= 0)
    { // start of nested block
        std::cout << value << " is a positive integer (or zero)\n";
        std::cout << "Double this number is " << value * 2 << '\n';
    } // end of nested block
    else
    { // start of another nested block
        std::cout << value << " is a negative integer\n";
        std::cout << "The positive of this number is " << -value << '\n';
    } // end of another nested block
```
Output shown on page:
```text
Enter an integer: 3
3 is a positive integer (or zero)
Double this number is 6

Enter an integer: -4
-4 is a negative integer
The positive of this number is 4
```

### Best practice / Warnings
- Best practice: keep the nesting level of your functions to 3 or less. If a function needs more nested levels, consider refactoring it into sub-functions.

## 8.1 Control flow introduction
<!-- 來源：https://www.learncpp.com/cpp-tutorial/control-flow-introduction/ -->

### Key points
- When a program runs, the CPU begins at the top of main(), executes statements in sequential order by default, and the program terminates at the end of main().
- The specific sequence of statements executed is called the program's execution path (or path).
- A straight-line program executes the same statements in the same order every time it runs.
- Straight-line programs cannot handle cases such as re-prompting after invalid input, because the number of retries is not knowable until runtime.
- Control flow statements change the normal path of execution. When the point of execution moves to a non-sequential statement, this is called branching.
- The page's categories: conditional statements (if, else, switch); jumps (goto, break, continue); function calls (function calls, return); loops (while, do-while, for, ranged-for); halts (std::exit(), std::abort()); exceptions (try, throw, catch).
- The chapter covers all of these categories except exceptions, which get a later chapter (chapter 27).
- Control flow, particularly loops, is what allows programs with real utility beyond toy programs, according to the page.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    
    int x{};
    std::cin >> x;

    std::cout << "You entered " << x << '\n';

    return 0;
}
```
(The page does not show output for this program. It states that the execution path includes lines 5, 7, 8, 10, and 12, in that order, making it a straight-line program.)

### Best practice / Warnings
(none)

## 8.2 If statements and blocks
<!-- 來源：https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/ -->

### Key points
- A conditional statement specifies whether some associated statement(s) should be executed. C++ has two basic kinds: if statements and switch statements (switch is covered in later lessons).
- An if statement takes the form `if (condition) true_statement;`, with an optional `else false_statement;`. If the condition is false and an else exists, the false_statement executes.
- Without a block, an if or else governs only one statement, regardless of indentation. The page's example prints "Too bad!" for every input because it is not inside the else.
- To run several statements under an else (or if), wrap them in a block; the block is treated as a single statement.
- Implicit blocks: if no block is written after if or else, the compiler implicitly creates one, so `if (condition) s; else t;` is equivalent to using braces around each branch.
- Because of implicit blocks, a variable declared directly in an if or else branch (such as `int x{ 5 };`) has block scope and is destroyed at the end of its branch, so using it after the if-else does not compile.
- The page describes a debate about putting braces around single statements. Reasons given for braces: it prevents accidentally adding statements that appear conditional but are not, it makes debugging easier (commenting out one call can make another statement conditional), and `if constexpr` (C++23) requires blocks.
- The main argument against braces is that they spread code vertically, reducing how much code is visible at once. The page says the community seems more in favor of always using blocks, though this is not universal.
- Use if-else when only the code after the first true condition should execute. Use if-if (a sequence of if statements) when the code after all true conditions should execute.
- When every associated statement returns a value, the if-if form behaves the same as the if-else form, since the first return ends the function. Many programmers then omit the else keywords.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    if (x > 10)
        std::cout << x << " is greater than 10\n";
    else
        std::cout << x << " is not greater than 10\n";

    return 0;
}
```
Output shown on page:
```text
Enter a number: 15
15 is greater than 10

Enter a number: 4
4 is not greater than 10
```

```cpp
char getFirstMatchingChar(bool a, bool b, bool c)
{
    if (a) // always evaluates
        return 'a'; // returns when if-statement is true
    if (b) // only evaluates when prior if-statement condition is false
        return 'b'; // returns when if-statement is true
    if (c) // only evaluates when prior if-statement condition is false
        return 'c'; // returns when if-statement is true

    return 0;
}
```

### Best practice / Warnings
- Best practice: consider putting single statements associated with an if or else in blocks, particularly while learning. The page notes experienced developers sometimes skip this in favor of tighter vertical spacing.
- Middle-ground alternative (from the page): put a single statement on the same line as the if or else. The page lists debugging drawbacks: you cannot easily tell whether the statement ran or was skipped, and you cannot breakpoint just the associated statement.
- Key insight: when all associated statements return a value, you can always just use if-if, since else provides no value.

## 8.3 Common if statement problems
<!-- 來源：https://www.learncpp.com/cpp-tutorial/common-if-statement-problems/ -->

### Key points
- If statements can be nested. The page's example comment calls nesting them this way "bad coding style."
- The dangling else problem: when an else could match either an outer or inner if, it pairs with the last unmatched if statement in the same block.
- In the page's unblocked example, input 21 prints "21 is negative" because the else attaches to the inner if.
- To avoid this ambiguity, enclose the inner if in a block. An else inside that block attaches to the inner if; an else outside it attaches to the outer if.
- Nested ifs can often be flattened by restructuring the logic or using logical operators (covered in lesson 6.8). The page says less-nested code is less error prone; it shows an if / else if / else chain as a flattened version.
- Logical operators let one if check multiple conditions: && (logical and) is true when both conditions are true, and || (logical or) is true when either is true.
- A null statement is an expression statement that consists of just a semicolon. It does nothing and is typically placed on its own line. The page says it is rarely used intentionally with if statements.
- An accidental semicolon after an if condition makes the following statement run unconditionally, even if it is inside a block.
- Inside a conditional, use == for equality testing, not = (assignment). The page's example `if (x = 0)` assigns 0 to x, the condition is then false, and the program always prints "You entered 1".
- Tip box: Python uses `pass` as a null statement placeholder. The page shows that C++ can mimic this with a preprocessor `#define PASS`, whose trailing semicolon acts as a null statement.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter 0 or 1: ";
    int x{};
    std::cin >> x;
    if (x = 0) // oops, we used an assignment here instead of a test for equality
        std::cout << "You entered 0\n";
    else
        std::cout << "You entered 1\n";

    return 0;
}
```
Output shown on page:
```text
Enter 0 or 1: 0
You entered 1
```

```cpp
if (x >= 0)
{
    if (x <= 20)
        std::cout << x << " is between 0 and 20\n";
    else // attached to inner if statement
        std::cout << x << " is greater than 20\n";
}
else // attached to outer if statement
    std::cout << x << " is negative\n";
```

```cpp
if (nuclearCodesActivated()); // note the semicolon at the end of this line
    blowUpTheWorld();
```

### Best practice / Warnings
- Warning: do not "terminate" an if statement with a semicolon, otherwise the statement(s) meant to run conditionally will run unconditionally instead (even if they are inside a block).
- Tip: the `pass` / `#define PASS` approach described in Key points.
