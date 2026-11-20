---
title: learncpp — 變數
site: https://www.learncpp.com/
retrieved: 2026-11-20
format: 摘錄筆記（非全文；由 Claude Code 以 web-fetch 逐篇讀取原頁後擷取，程式碼為原頁原文）
lessons:
  - id: "1.3"
    title: Introduction to objects and variables
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-objects-and-variables/
  - id: "1.4"
    title: Variable assignment and initialization
    url: https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
  - id: "1.6"
    title: Uninitialized variables and undefined behavior
    url: https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/
  - id: "1.7"
    title: Keywords and naming identifiers
    url: https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/
---

> 收錄 lesson：1.3、1.4、1.6、1.7
> 這是**摘錄筆記**，不是全文轉載：重點為忠實改述（保留原站英文用語），引號內為原文短句，程式碼區塊為原頁原文。
> 本檔為唯讀原始資料，ingest 時不可修改。

## 1.3 Introduction to objects and variables
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-objects-and-variables/ -->

### Key points
- Data is any information that a computer can move, process, or store. Programs are collections of instructions that manipulate data to produce a desired result.
- A program can get data from a file or database, over a network, from user keyboard input, or from literals placed directly in the source code (the "Hello world!" text in the earlier program).
- A single piece of data is called a value. Examples given are numbers (5, -6.7), characters in single quotes ('H', only one symbol), and text in double quotes ("Hello", 0 or more characters).
- Values placed directly in source code are called literals. Literals are read-only, so their values cannot be modified; storing data needs another mechanism.
- A character or text value that is not properly quoted is read by the compiler as C++ code, which almost always causes a compilation error.
- Main memory is called RAM. The operating system loads the program into RAM and reserves extra RAM for the program to use while running (user input, file or network data, calculated values).
- C++ discourages direct memory access. Memory is accessed indirectly through an object, which is a region of storage (typically RAM or a CPU register) that can hold a value.
- A variable is an object that has a name (identifier). Naming lets the program refer to the object later.
- In C++, the term "object" has a narrower meaning than in general programming and excludes functions.
- A definition statement (for example `int x;`) tells the compiler that the program wants a variable with a given name and data type. For now, variables should be defined inside functions such as `main()`.
- At runtime, reserving storage for an object is called allocation. The object is "created" once storage has been reserved and can then be used.
- A data type determines what kind of value an object stores. In C++ the type must be known at compile-time and cannot change without recompiling, so an `int` variable holds only integer values.
- Several variables of the same type can be defined in one statement separated by commas, but new programmers commonly give each variable a type again or mix types in one statement; both are compiler errors.

### Code examples
```cpp
#include <iostream> // for std::cout

int main()
{
    std::cout << 5;       // print the literal number `5`
    std::cout << -6.7;    // print the literal number `-6.7`
    std::cout << 'H';     // print the literal character `H`
    std::cout << "Hello"; // print the literal text `Hello`

    return 0;
}
```

```cpp
int main()
{
    int x; // definition of variable x

    return 0;
}
```

### Best practice / Warnings
- Key insight: values in single quotes are interpreted as character values, values in double quotes as text values, and numeric values are not quoted.
- Key insight: an object is used to store a value in memory; a variable is an object that has a name (identifier).
- Key insight: a definition statement can be used to tell the compiler that a variable is to be used in the program.
- Key insight: the data type of an object must be known at compile-time, so the compiler knows how much memory the object requires.
- Key insight: an object is "created" once actual storage has been reserved for the object's use.
- Best practice: although the language allows it, avoid defining multiple variables of the same type in a single statement. Define each variable on its own line with a single-line comment describing its use.

## 1.4 Variable assignment and initialization
<!-- 來源：https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/ -->

### Key points
- After a variable is defined, a value can be given to it in a separate statement using the `=` operator, called the assignment operator. This is called assignment.
- By default, assignment copies the value on the right-hand side of `=` into the variable on the left; the page calls this copy-assignment.
- A normal variable can hold only one value at a time. A later assignment overwrites the earlier value.
- Warning: a very common beginner mistake is confusing assignment (`=`) with the equality operator (`==`), which tests whether two operands are equal.
- Initialization gives an object an initial value at the point it is defined. The syntax is an initializer, and the value is the initial value. Initialization combines the define and assign steps into one statement.
- Default-initialization (no initializer, e.g. `int a;`) usually leaves the variable with an indeterminate ("garbage") value.
- Copy-initialization (`int b = 5;`) is inherited from C. Direct-initialization (`int c ( 6 );`) uses parentheses. Direct-list-initialization (`int d { 7 };`) uses braces and is preferred. Value-initialization (`int e {};`) uses empty braces and usually zero-initializes.
- As of C++17, copy-, direct-, and direct-list-initialization behave identically in most cases.
- List-initialization disallows narrowing conversions: `int w1 { 4.5 };` is a compile error, while `int w2 = 4.5;` and `int w3 (4.5);` compile and silently drop the .5 to give 4.
- The narrowing restriction applies only to list-initialization, not to later assignment; `w1 = 4.5;` is allowed and converts to 4.
- The page describes list-initialization (including value-initialization) as generally preferred in modern C++ because it works in most cases, is consistent, and disallows narrowing.
- Instantiation is the term for a variable being created (allocated) and initialized, including default initialization. An instantiated object is called an instance.
- In `int a, b = 5;`, only `b` gets an initializer and `a` is left uninitialized. Each variable needs its own initializer, as in `int a = 5, b = 5;`.
- Modern compilers usually warn about initialized but unused variables. With "treat warnings as errors" enabled, GCC fails the build. Fixes are to remove the variable, use it, or apply `[[maybe_unused]]` (C++17) when the unused variable is intentional.

### Code examples
```cpp
#include <iostream>

int main()
{
	int width; // define a variable named width
	width = 5; // copy assignment of value 5 into variable width

	std::cout << width; // prints 5

	width = 7; // change value stored in variable width to 7

	std::cout << width; // prints 7

	return 0;
}
```
Output shown on page:
```text
57
```

```cpp
int a;         // default-initialization (no initializer)

// Traditional initialization forms:
int b = 5;     // copy-initialization (initial value after equals sign)
int c ( 6 );   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d { 7 };   // direct-list-initialization (initial value in braces)
int e {};      // value-initialization (empty braces)
```

### Best practice / Warnings
- Warning: confusing the assignment operator (`=`) with the equality operator (`==`) is one of the most common mistakes new programmers make.
- Key insight: "Initialization provides an initial value for a variable." The page adds the mnemonic "Think initial-ization."
- Key insight: when we see curly braces, we know we are list-initializing an object.
- Best practice: prefer direct-list-initialization or value-initialization to initialize variables.
- Best practice: initialize your variables upon creation. The page allows deliberate exceptions (e.g. performance-critical code) if the choice is made on purpose.

## 1.6 Uninitialized variables and undefined behavior
<!-- 來源：https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/ -->

### Key points
- Unlike some languages, C and C++ do not automatically initialize most variables to a value such as zero. The value of an uninitialized variable is whatever garbage value already sits in that memory.
- An uninitialized variable is one that has not been given a known value through initialization or assignment.
- Terminology: "initialized" means given a known value at the point of definition; "assignment" means given a known value after the definition; "uninitialized" means no known value has been given yet. A variable that is later assigned a value is no longer uninitialized.
- In `int x;`, default-initialization performs no actual initialization in most cases, so `x` is uninitialized.
- The lack of automatic initialization is a performance optimization inherited from C. The page recommends always initializing variables for now, because the cost is minuscule compared with the benefit.
- Using the value of an uninitialized variable gives unpredictable results. In the example program, the printed value may change between runs; the author saw 7177728 and 5277592 in Visual Studio.
- Some compilers (such as Visual Studio) fill memory with a preset value in debug builds (the page shows -858993460), but not in release builds.
- Most modern compilers try to detect use of uninitialized variables and usually issue a compile-time warning or error. The page shows Visual Studio warning C4700.
- Using an uninitialized variable is the first example of undefined behavior (UB): the language has no rules for what happens, so the result can be anything.
- Possible UB symptoms listed: different results each run, consistently wrong results, inconsistent behavior, apparently working then failing later, crashes, working on some compilers but not others, and breaking when unrelated code changes. The code may also happen to produce the correct result.
- Implementation-defined behavior is defined by the implementation (compiler plus standard library), must be documented, and must be consistent. The page's example is `sizeof(int)`, which may print 4 or 2 depending on platform.
- Unspecified behavior is similar, but the implementation is not required to document it.
- The page says to generally avoid implementation-defined and unspecified behavior because the program may fail on another compiler or after a project-setting change.

### Code examples
```cpp
#include <iostream>

int main()
{
    // define an integer variable named x
    int x; // this variable is uninitialized because we haven't given it a value
    
    // print the value of x to the screen
    std::cout << x << '\n'; // who knows what we'll get, because x is uninitialized

    return 0;
}
```

```cpp
#include <iostream>

int main()
{
	std::cout << sizeof(int) << '\n'; // print how many bytes of memory an int value takes

	return 0;
}
```

### Best practice / Warnings
- Warning: some compilers (e.g. Visual Studio) initialize memory to preset values in debug builds, so to see the "who knows" behavior the page advises using a release build configuration.
- Rule: take care to avoid all situations that result in undefined behavior, such as using uninitialized variables.
- Best practice: avoid implementation-defined and unspecified behavior whenever possible, as they may cause the program to malfunction on other implementations.
- Prose note (not a box): the page calls avoiding uninitialized variables the primary reason for the "always initialize your variables" best practice.

## 1.7 Keywords and naming identifiers
<!-- 來源：https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/ -->

### Key points
- C++ reserves a set of keywords (reserved words) for its own use. The page says there are 92 as of C++23, each with a special meaning. Examples on the page include `int`, `return`, `if`, `else`, `for`, `void`, and `while`.
- Keywords marked "(since C++20)" may not work if the compiler is not C++20-compliant or has that functionality turned off.
- The special identifiers `override`, `final`, `import`, and `module` have specific meaning only in certain contexts and are not reserved otherwise.
- An identifier is the name of a variable, function, type, or other item.
- Identifier rules: it cannot be a keyword; it may contain only letters, numbers, and underscores (no other symbols and no whitespace); it must begin with a letter or underscore, not a number; and C++ is case sensitive (`nvalue`, `nValue`, and `NVALUE` are different).
- Convention: variable names begin with a lowercase letter. A single-word or acronym name is written entirely in lowercase.
- Function names usually also start lowercase. Names starting with a capital letter are typically used for user-defined types such as structs, classes, and enumerations.
- Multi-word names use either underscores (snake_case) or intercapping (camelCase). The page's tutorial uses intercapped names; the C++ standard library uses underscores.
- Names starting with an underscore are syntactically legal but should be avoided, since they are typically reserved for OS, library, and compiler use.
- Names should make the meaning clear. Name length should be proportional to how specific and accessible the identifier is. Abbreviations should be avoided unless common and unambiguous (e.g. `num`, `cm`, `idx`).
- A comment on or above a declaration can explain what a variable is for, instead of a very long name (example: `int numChars {};` with a comment about counting characters including whitespace and punctuation).
- When working in someone else's program, match that program's style even if it does not follow modern conventions.

### Code examples
```cpp
int my_variable_name;   // conventional (separated by underscores/snake_case)
int my_function_name(); // conventional (separated by underscores/snake_case)

int myVariableName;     // conventional (intercapped/camelCase)
int myFunctionName();   // conventional (intercapped/camelCase)
```

```cpp
// a count of the number of chars in a piece of text, including whitespace and punctuation
int numChars {};
```

### Best practice / Warnings
- Best practice: when working in an existing program, use that program's conventions, even if they do not follow modern best practices. Use modern best practices when writing new programs.
- Key insight: code is read more often than it is written, so time saved while writing is time every reader will spend reading. The page suggests using the editor's auto-complete to write faster.
- Rule of thumb (numbered guidance, not a box): avoid abbreviations except common, unambiguous ones.
