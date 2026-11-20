---
title: learncpp — 運算子
site: https://www.learncpp.com/
retrieved: 2026-11-20
format: 摘錄筆記（非全文；由 Claude Code 以 web-fetch 逐篇讀取原頁後擷取，程式碼為原頁原文）
lessons:
  - id: "1.9"
    title: Introduction to literals and operators
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-literals-and-operators/
  - id: "1.10"
    title: Introduction to expressions
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/
  - id: "6.1"
    title: Operator precedence and associativity
    url: https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/
  - id: "6.2"
    title: Arithmetic operators
    url: https://www.learncpp.com/cpp-tutorial/arithmetic-operators/
  - id: "6.3"
    title: Remainder and Exponentiation
    url: https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
  - id: "6.4"
    title: Increment/decrement operators, and side effects
    url: https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/
  - id: "6.7"
    title: Relational operators and floating point comparisons
    url: https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
  - id: "6.8"
    title: Logical operators
    url: https://www.learncpp.com/cpp-tutorial/logical-operators/
---

> 收錄 lesson：1.9、1.10、6.1、6.2、6.3、6.4、6.7、6.8
> 這是**摘錄筆記**，不是全文轉載：重點為忠實改述（保留原站英文用語），引號內為原文短句，程式碼區塊為原頁原文。
> 本檔為唯讀原始資料，ingest 時不可修改。

## 1.9 Introduction to literals and operators
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-literals-and-operators/ -->

### Key points
- A literal (also called a literal constant) is a fixed value inserted directly into the source code, such as "Hello world!" or 5.
- Literals and variables both have a value and a type. A literal's value is fixed and cannot be changed, which is why literals are called constants.
- A variable's value can be set through initialization and changed through assignment.
- The page compares printing a literal with printing a variable: a literal's value is placed directly in the executable, while a variable's value must be fetched from the memory the variable represents.
- The page explains that a literal is constant because its value is in the executable, which cannot change after it is created; a variable's value is in memory, which can change while the program runs.
- An operation takes zero or more input values (operands) and produces a new value. The symbol that denotes the operation is the operator.
- The output value of an operation is often called a return value.
- The number of operands an operator takes is its arity: unary (one operand, e.g. unary minus), binary (two operands, e.g. +, <<, >>), ternary (three; the conditional operator, covered later), and nullary (zero; the throw operator, covered later).
- Some operators have more than one meaning depending on use. For example, the minus operator is unary when it negates a number and binary when it subtracts.
- Operators can be chained, and arithmetic operators follow the same order as standard mathematics (parentheses, exponents, multiplication and division, addition and subtraction). The page says this is sometimes abbreviated PEMDAS; it defers the full order-of-operations discussion to lesson 6.1.
- Most operators only compute a return value. An operator or function with an observable effect beyond its return value has a side effect. Examples on the page: x = 5 changes x, and std::cout << 5 prints to the console.
- Some operators are written as keywords rather than symbols (e.g. new, delete, throw).
- Quiz: std::cout << 2 + 3 * 4 prints 14 because multiplication is evaluated before addition.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << 5 << '\n'; // print the value of a literal

    int x { 5 };
    std::cout << x << '\n'; // print the value of a variable
    return 0;
}
```

### Best practice / Warnings
- Key insight: Literals are values inserted directly into the source code and usually appear directly in the executable code (unless optimized out). Objects and variables represent memory locations that hold values, which can be fetched on demand.

## 1.10 Introduction to expressions
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-expressions/ -->

### Key points
- An expression is a non-empty sequence of literals, variables, operators, and function calls that calculates a value.
- Executing an expression is called evaluation, and the value produced is the result of the expression (also sometimes called the return value).
- During evaluation, each term in the expression is evaluated until a single value remains.
- Evaluation of each kind of term: a literal evaluates to its own value; a variable evaluates to the value it holds; an operator uses its operands to produce another value; a function call evaluates to the function's return value.
- The page says that for this lesson it assumes expressions are evaluated to produce values. Advanced readers are told an expression's result can also be an object or function, or nothing (for calls to void functions made for their side effects).
- Expressions do not end in a semicolon and cannot be compiled by themselves; they are always evaluated as part of a statement.
- The page gives the syntax of a variable definition as: type identifier { expression };
- An expression statement is an expression followed by a semicolon. Any result the expression produces is discarded (e.g. the return value of operator= in x = 5;).
- Expression statements such as 2 * 3; compile but are useless; the page says gcc and Clang may warn about them.
- A subexpression is an expression used as an operand; a full expression is one that is not a subexpression; a compound expression contains two or more uses of operators (x = 4 + 5 is compound).
- Quiz: a statement is used when the program should perform an action, and an expression is used when the program should calculate a value.
- Quiz: x = 5; is an expression statement, int x = 5; is a statement that contains an expression, and int x; is a statement with no expression.

### Code examples
Fragment from the page (the page's full example also defines `int five()` returning 5):
```cpp
int main()
{
    int a{ 2 };             // initialize variable a with literal value 2
    int b{ 2 + 3 };         // initialize variable b with computed value 5
    int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d{ b };             // initialize variable d with variable value 5
    int e{ five() };        // initialize variable e with function return value 5

    return 0;
}
```

### Best practice / Warnings
- Key insight: Wherever a single value is expected in C++, a value-producing expression can be used, and it is evaluated to produce a single value.

## 6.1 Operator precedence and associativity
<!-- 來源：https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/ -->

### Key points
- The chapter introduction reviews that an operation takes operands and an operator, and that 2 + 3 has operands 2 and 3 and operator +.
- To evaluate a compound expression, the compiler must (1) at compile time, parse it and group operands with operators using precedence and associativity rules, and (2) evaluate operands and execute operations at compile time or runtime.
- Precedence: every operator has a precedence level, and operators with higher precedence are grouped with their operands first. Multiplication and division (level 5) are grouped before addition and subtraction (level 6), so 4 + 2 * 3 is grouped as 4 + (2 * 3).
- In the page's table, precedence level 1 is the highest and level 17 is the lowest.
- Associativity: when adjacent operators have the same precedence, associativity decides grouping. Operators are grouped left to right or right to left (the page's table marks each level L->R or R->L). For example, 7 - 4 - 1 is grouped as (7 - 4) - 1.
- Parentheses have one of the highest precedence levels and can be used to set grouping explicitly, as in (4 + 2) * 3.
- The page recommends parenthesizing non-trivial compound expressions so intent is clear without consulting the table.
- "Value computation" means executing operators to produce a value, and precedence and associativity determine its order. "Evaluation" refers to operands.
- The page says the order in which operands and function arguments are evaluated is mostly unspecified, so the compiler may evaluate them in any order. Precedence does not control this order.
- Example from the page: calling printCalculation(getValue(), getValue(), getValue()) is ambiguous because the order in which the getValue() calls run is not fixed. Splitting the calls into separate statements makes it unambiguous.
- C++ has no exponent operator; ^ is bitwise XOR. Exponentiation is covered in lesson 6.3.
- operator<< and operator>> are shift and insertion/extraction operators; the compiler picks which based on operand types.
- Quiz sample: x = 2 + 3 % 4 is grouped as x = (2 + (3 % 4)), since % has higher precedence than + and =.

### Code examples
Fragment from the page; the complete program also defines `int getValue()` (reads an int from std::cin) and `void printCalculation(int x, int y, int z)`, which prints `x + (y * z)`:
```cpp
int main()
{
    printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous

    return 0;
}
```
The unambiguous version (same helper functions):
```cpp
int main()
{
    int a{ getValue() }; // will execute first
    int b{ getValue() }; // will execute second
    int c{ getValue() }; // will execute third

    printCalculation(a, b, c); // this line is now unambiguous

    return 0;
}
```

### Best practice / Warnings
- Best practice: Use parentheses to make it clear how a non-trivial compound expression should evaluate, even if they are technically unnecessary. A good rule of thumb: parenthesize everything except addition, subtraction, multiplication, and division.
- Best practice: An expression with a single assignment operator (and no comma operator) does not need the right operand of the assignment wrapped in parentheses. For example, x = y + z + w; is fine.
- Key insight: Operands, function arguments, and subexpressions may be evaluated in any order. Precedence and associativity do not determine order of evaluation; they only determine grouping and the order of value computation.
- Warning: Make sure expressions (or function calls) you write do not depend on operand or argument evaluation order.
- Tip: The page says the Clang compiler evaluates arguments left to right and the GCC compiler evaluates them right to left.

## 6.2 Arithmetic operators
<!-- 來源：https://www.learncpp.com/cpp-tutorial/arithmetic-operators/ -->

### Key points
- The two unary arithmetic operators are unary plus (+x) and unary minus (-x). Unary minus returns the operand multiplied by -1; unary plus returns the operand's value and is largely redundant.
- Unary operators should be written immediately before the operand (-x, not - x).
- Do not confuse unary minus with binary subtraction; in x = 5 - -3;, the first minus is subtraction and the second is unary minus.
- There are five binary arithmetic operators: + (addition), - (subtraction), * (multiplication), / (division), and % (remainder, covered in lesson 6.3).
- Integer and floating point division: if either or both operands are floating point, the division operator performs floating point division and keeps the fraction (7.0 / 4 = 1.75).
- If both operands are integers, the division operator performs integer division, which drops any fraction (7 / 4 = 1; -7 / 4 = -1). Quote: "Integer division drops any fractions and returns an integer value."
- To divide two integers without losing the fraction, convert an operand with static_cast<> (e.g. static_cast<double>(x) / y).
- Integer division by 0 causes undefined behavior; the page says the program will likely crash.
- Dividing by floating point 0.0 is implementation-defined. On IEEE754 architectures the result is NaN or Inf; on others it is likely undefined behavior (see lesson 4.8).
- Compound assignment operators: +=, -=, *=, /=, and %=. For example, x += 4; is the same as x = x + 4;.
- Modifying operators change their left operand: the assignment operators (including the arithmetic and bitwise assignment operators) and the increment and decrement operators (covered in 6.4). Relational operators ==, !=, <=, and >= are non-modifying.
- Advanced note: overloaded operators can behave differently from the built-in versions; the page's example is operator<< for output, which modifies its left operand (the stream).

### Code examples
```cpp
#include <iostream>

int main()
{
    constexpr int x{ 7 };
    constexpr int y{ 4 };

    std::cout << "int / int = " << x / y << '\n';
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
    std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';

    return 0;
}
```
Output shown on page:
```text
int / int = 1
double / int = 1.75
int / double = 1.75
double / double = 1.75
```

```cpp
#include <iostream>

int main()
{
    constexpr int apples { 12 };
    std::cout << "You have " << apples << " apples. Enter how many servings of apples you want: ";

    double d {};
    std::cin >> d;

    std::cout << "Each serving is " << apples / d << " apples.\n"; // d is double, so this is floating point division

    return 0;
}
```

### Best practice / Warnings
- Warning-style note on the page: integer division with a divisor of 0 causes undefined behavior (the page says the program will likely crash when 0 is entered).
- No formal Best practice boxes on this page.

## 6.3 Remainder and Exponentiation
<!-- 來源：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/ -->

### Key points
- The remainder operator % (also called modulo or modulus) returns the remainder after integer division: 7 / 4 is 1 remainder 3, so 7 % 4 is 3; 25 % 7 is 4.
- The remainder operator works only with integer operands.
- It is most useful for testing even divisibility: if x % y evaluates to 0, x is evenly divisible by y.
- When the second number is larger than the first, the remainder is the first number (2 % 4 is 2), because the second number divides the first 0 times.
- With negative operands, x % y always returns a result with the sign of x (e.g. -6 % 4 is -2; 6 % -4 is 2).
- The page prefers the name "remainder" over "modulo" because mathematical modulo differs for negatives (-21 modulo 4 = 3, but -21 remainder 4 = -1).
- Pitfall: a function that tests (x % 2) == 1 to detect odd numbers fails for negative odd numbers such as -5, because -5 % 2 is -1.
- Best practice: compare the result of % against 0 when possible; the page's fix is return (x % 2) != 0; (or simply return (x % 2)).
- C++ has no exponent operator. The ^ symbol is bitwise XOR in C++.
- To compute powers, #include <cmath> and use std::pow(). Its parameters and return value are double, and results may be imprecise due to floating point rounding even with whole-number inputs.
- For integer exponentiation, the page provides its own function (powint, using exponentiation by squaring) and says you do not need to understand it to call it.
- Warning: in the vast majority of cases, integer exponentiation overflows the integral type. The page provides powint_safe, which checks for overflow and returns the maximum std::int64_t value on overflow.
- Quiz: 6 + 5 * 4 % 3 evaluates to 8, because * and % (same level, left to right) are evaluated before +.
- Quiz exercise: write a constexpr isEven() using the remainder operator that works for both positive and negative integers.

### Code examples
Fragment from the page: the corrected odd-number check.
```cpp
bool isOdd(int x)
{
    return (x % 2) != 0; // could also write return (x % 2)
}
```
Fragment from the page: using std::pow (requires #include <cmath>).
```cpp
#include <cmath>

double x{ std::pow(3.0, 4.0) }; // 3 to the 4th power
```

### Best practice / Warnings
- Best practice: Prefer to compare the result of the remainder operator (operator%) against 0 if possible.
- Warning: In the vast majority of cases, integer exponentiation will overflow the integral type; the page says this is likely why such a function was not included in the standard library.

## 6.4 Increment/decrement operators, and side effects
<!-- 來源：https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/ -->

### Key points
- There are four operators: prefix increment (++x), prefix decrement (--x), postfix increment (x++), and postfix decrement (x--).
- Prefix: the operand is changed first, then the expression evaluates to the (new) value of the operand. In int y { ++x }; with x = 5, x becomes 6 and y becomes 6.
- Postfix: a copy of the operand is made, the operand (not the copy) is changed, and the copy is what the expression evaluates to. In int y { x++ }; with x = 5, x becomes 6 and y becomes 5.
- The postfix version takes more steps and may be less performant than the prefix version.
- For a standalone statement, ++x; and x++; have the same effect (both increment x). The difference matters only when the value is used inside a larger expression.
- Side effect: a function or expression has a side effect if it has an observable effect beyond producing a return value, such as changing an object's value, doing input or output, or updating a GUI.
- Assignment, ++, and std::cout << x all have side effects in the page's examples.
- Key insight: The assignment operators, the prefix operator, and the postfix operator have side effects that permanently change an object's value. Arithmetic operators return a value and do not modify their operands.
- Order of evaluation can matter: in add(x, ++x) with x = 5, the result is 11 or 12 depending on whether the left or right argument is evaluated first, and the page says this is undefined behavior.
- Sequencing: the page says x + ++x is unspecified; it reports Visual Studio and GCC evaluate it as 2 + 2 and Clang as 1 + 2 when x starts at 1.
- Quote: "C++ does not define the order of evaluation for function arguments or the operands of operators."

### Code examples
```cpp
#include <iostream>

int main()
{
    int x { 5 };
    int y { 5 };
    std::cout << x << ' ' << y << '\n';
    std::cout << ++x << ' ' << --y << '\n'; // prefix
    std::cout << x << ' ' << y << '\n';
    std::cout << x++ << ' ' << y-- << '\n'; // postfix
    std::cout << x << ' ' << y << '\n';

    return 0;
}
```
Output shown on page:
```text
5 5
6 4
6 4
6 4
7 3
```

```cpp
#include <iostream>

int main()
{
    int x { 5 };
    int y { ++x }; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y << '\n';
    return 0;
}
```
Output shown on page:
```text
6 6
```

### Best practice / Warnings
- Best practice: Favor the prefix versions, as they are more performant and less likely to cause surprises. Use the postfix versions when they produce significantly more concise or understandable code than the prefix equivalent.
- Warning: C++ does not define the order of evaluation for function arguments or the operands of operators.
- Warning: Do not use a variable that has a side effect applied to it more than once in a given statement, as the result may be undefined. The one exception the page gives is a simple assignment such as x = x + y (essentially x += y).

## 6.7 Relational operators and floating point comparisons
<!-- 來源：https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/ -->

### Key points
- Relational (comparison) operators compare two values: > (greater than), < (less than), >= (greater than or equals), <= (less than or equals), == (equality), and != (inequality).
- Each relational operator evaluates to a Boolean value, true or false.
- Relational operators are straightforward to use with integers.
- Conditions in an if statement or conditional operator (and a few other places) evaluate as Boolean values by default.
- Redundant style: if (b1 == true) can be written as if (b1); if (b1 == false) can be written as if (!b1).
- Best practice: do not add unnecessary == or != to conditions.
- Calculated floating point values can compare unexpectedly. The page's example: 100.0 - 99.99 and 10.0 - 9.99 should both equal 0.01, but the program prints "d1 > d2" because of rounding errors. Quote: "Comparing floating point values using any of the relational operators can be dangerous."
- For floating point values, <, >, <=, and >= are reliable in most cases when the operands are not similar, but may be unreliable when the operands are nearly identical. Whether this is acceptable is an application-specific decision (the page gives a game collision example).
- The equality operators == and != are riskier with floating point values because even tiny rounding errors make values unequal. The page's example: 0.3 == 0.2 + 0.1 gives false.
- Exception: it is safe to compare a floating point literal with a same-type variable initialized with a same-type literal, if the literals' significant digits do not exceed the type's minimum precision (float: 6 digits; double: 15 digits). Examples: if (someFcn() == 0.0) when the function returns the literal 0.0; constexpr double gravity { 9.8 }; if (gravity == 9.8).
- Comparing floating point literals of different types (e.g. 9.8f and 9.8) is mostly not safe; the page says it returns false.
- Advanced/optional: the page covers "close enough" comparisons using an epsilon value (absolute, relative per Knuth, and a combined absAbsRel approach), and notes that std::abs is constexpr only in C++23.

### Code examples
```cpp
#include <iostream>

int main()
{
    constexpr double d1{ 100.0 - 99.99 }; // should equal 0.01 mathematically
    constexpr double d2{ 10.0 - 9.99 }; // should equal 0.01 mathematically

    if (d1 == d2)
        std::cout << "d1 == d2" << '\n';
    else if (d1 > d2)
        std::cout << "d1 > d2" << '\n';
    else if (d1 < d2)
        std::cout << "d1 < d2" << '\n';
    return 0;
}
```
Output shown on page:
```text
d1 > d2
```

```cpp
#include <iostream>

int main()
{
    std::cout << std::boolalpha << (0.3 == 0.2 + 0.1); // prints false

    return 0;
}
```

### Best practice / Warnings
- Best practice: Don't add unnecessary == or != to conditions. It makes them harder to read without offering any additional value.
- Warning: Avoid using operator== and operator!= to compare floating point values if there is any chance those values have been calculated.
- Tip: Comparing a floating point literal with a same-type variable initialized with a same-type literal is safe as long as the significant digits do not exceed the type's minimum precision (float 6, double 15). Generally it is not safe to compare floating point literals of different types.

## 6.8 Logical operators
<!-- 來源：https://www.learncpp.com/cpp-tutorial/logical-operators/ -->

### Key points
- Relational operators test one condition at a time; logical operators let you test multiple conditions together.
- C++ has three logical operators: ! (logical NOT, true if its operand is false), && (logical AND, true only if both operands are true), and || (logical OR, true if either or both operands are true).
- Logical NOT flips a Boolean value. It is often used as if (!tooLarge).
- Logical NOT has very high precedence. The page's example: !x > y is evaluated as (!x) > y, so the output is wrong; the fix is !(x > y).
- Logical OR is used to test whether either of two conditions is true; the page's example checks if (value == 0 || value == 1).
- Logical AND is used to test whether both conditions are true; the page's example checks if (value > 10 && value < 20).
- Conditions can be chained with && or || (e.g. value > 10 && value < 20 && value != 16).
- Short-circuit evaluation: && returns false immediately if its left operand is false, and || returns true immediately if its left operand is true, so the right operand is not evaluated. The page says this is done primarily for optimization.
- Do not confuse logical operators with bitwise operators: || with |, and && with &.
- && has higher precedence than ||, so value1 || value2 && value3 is evaluated as value1 || (value2 && value3).
- De Morgan's laws: !(x && y) is equivalent to !x || !y, and !(x || y) is equivalent to !x && !y. Distributing NOT also flips AND and OR.
- C++ has no logical XOR operator. The page says != on bool operands gives the same result as logical XOR (advanced/optional).
- C++ supports keyword alternatives: and (&&), or (||), not (!). The page recommends learning the symbolic names because they are common in existing code.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int value {};
    std::cin >> value;

    if (value > 10 && value < 20)
        std::cout << "Your value is between 10 and 20\n";
    else
        std::cout << "Your value is not between 10 and 20\n";
    return 0;
}
```

```cpp
#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!x > y)
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}
```
Output shown on page:
```text
5 is greater than 7
```

### Best practice / Warnings
- Best practice: If logical NOT is intended to operate on the result of other operators, enclose the other operators and their operands in parentheses. Simple uses such as if (!value) do not need them.
- Warning: Writing if (value == 0 || 1) is incorrect, because 1 implicitly converts to bool true, so the condition is always true. Compare the variable multiple times instead: if (value == 0 || value == 1).
- Warning: Short-circuit evaluation may cause Logical OR and Logical AND to not evaluate the right operand. Avoid expressions with side effects together with these operators; the page's example is if (x == 1 && ++y == 2), where y is incremented only when x is 1.
- Key insight: && and || are an exception to the rule that operands may evaluate in any order, because the standard requires the left operand to be evaluated first.
- Best practice: When mixing logical AND and logical OR in one expression, explicitly parenthesize each operation, e.g. (value1 && value2) || (value3 && value4).
- Tip: Do not confuse the logical operators with bitwise operators (| and &).
