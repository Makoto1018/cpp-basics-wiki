---
title: learncpp — 程式骨架
site: https://www.learncpp.com/
retrieved: 2026-11-20
format: 摘錄筆記（非全文；由 Claude Code 以 web-fetch 逐篇讀取原頁後擷取，程式碼為原頁原文）
lessons:
  - id: "0.4"
    title: Introduction to C++ development
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-cpp-development/
  - id: "0.5"
    title: Introduction to the compiler, linker, and libraries
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/
  - id: "0.7"
    title: Compiling your first program
    url: https://www.learncpp.com/cpp-tutorial/compiling-your-first-program/
  - id: "0.8"
    title: A few common C++ problems
    url: https://www.learncpp.com/cpp-tutorial/a-few-common-cpp-problems/
  - id: "1.1"
    title: Statements and the structure of a program
    url: https://www.learncpp.com/cpp-tutorial/statements-and-the-structure-of-a-program/
  - id: "1.2"
    title: Comments
    url: https://www.learncpp.com/cpp-tutorial/comments/
  - id: "1.5"
    title: "Introduction to iostream: cout, cin, and endl"
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/
  - id: "3.1"
    title: Syntax and semantic errors
    url: https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
---

> 收錄 lesson：0.4、0.5、0.7、0.8、1.1、1.2、1.5、3.1
> 這是**摘錄筆記**，不是全文轉載：重點為忠實改述（保留原站英文用語），引號內為原文短句，程式碼區塊為原頁原文。
> 本檔為唯讀原始資料，ingest 時不可修改。

## 0.4 Introduction to C++ development
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-cpp-development/ -->

### Key points
- The page gives a simplified development process. Step 1 is the "what" step: define the problem to solve, with examples such as a program that averages entered numbers.
- Step 2 is the "how" step: decide how to solve the problem. The page says this step is the most neglected in software development.
- Good solutions are straightforward, well documented (especially assumptions and limitations), built modularly so parts can change without affecting other parts, and can recover gracefully or give useful error messages.
- Coding immediately tends to produce fragile programs that are hard to change or extend, or that have many bugs.
- A bug is any kind of programming error that prevents the program from operating correctly.
- The page cites studies saying only about 10-40% of programmer time on complex systems goes to writing the initial program; 60-90% goes to maintenance (debugging, environment updates, enhancements, internal improvements).
- Step 3 is writing the program. The typed instructions are the program's source code, and any text editor can be used, though the page strongly recommends a code editor.
- Code editor features listed: line numbering (helps locate compiler-reported line numbers), syntax highlighting and coloring, and an unambiguous fixed-width (monospace) font.
- Simple programs may have one source file; complex programs can have hundreds or thousands.
- C++ has no file-naming requirement, but the de facto standard is to name the primary source file main.cpp. Names like calculator.cpp, and extensions .cc or .cxx, are also seen.
- The page notes that ≠ is not in ASCII, so C++ uses != for inequality; some fonts (e.g., Fira Code) display it as a ligature (advanced readers note).
- Steps 4-7 (compiling, linking, testing, debugging) are deferred to the next lesson.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << "Here is some text.";
    return 0;
}
```

### Best practice / Warnings
- Best practice: Name the first/primary source code file in each program main.cpp, so it is easy to tell which file is the primary one.
- Tip: The page links coding-font comparison tools (Coding Font, Programming Fonts).

## 0.5 Introduction to the compiler, linker, and libraries
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/ -->

### Key points
- Continues the development process diagram from 0.4, covering steps 4-7.
- Step 4 (compiling): the compiler goes through each .cpp file, checks that it follows C++ language rules, and reports errors with line numbers. Compilation is aborted until errors are fixed.
- The compiler also translates valid code into machine language stored in an intermediate object file, which holds data needed by the linker and by debugging.
- Object files are named name.o or name.obj, where name matches the .cpp file; a program with 3 .cpp files produces 3 object files.
- Step 5 (linking): the linker combines object files and library files to produce the output, typically an executable. If linking fails, it reports an error and aborts.
- Linker tasks: it validates each object file, resolves cross-file dependencies (a thing defined in one .cpp and used in another), links library files (precompiled, packaged code for reuse), and writes the output file.
- If a reference cannot be connected to its definition, the linker gives a linker error.
- The C++ Standard Library is extensive; its iostream part handles printing text and getting keyboard input. Most linkers link the standard library by default.
- Third-party libraries are created by independent entities, not as part of the C++ standard; the page gives sound-playing as an example.
- "Building" means the full process of converting source files into an executable; the resulting executable is sometimes called a "build".
- Steps 6-7: testing (assessing whether software works, e.g., by trying different inputs) and debugging (finding and fixing programming errors).
- Steps 3, 4, 5, and 7 use software that must be installed (editor, compiler, linker, debugger). An IDE bundles these features together.

### Code examples
(none on page)

### Best practice / Warnings
(none)

## 0.7 Compiling your first program
<!-- 來源：https://www.learncpp.com/cpp-tutorial/compiling-your-first-program/ -->

### Key points
- A project is a container for all source files, images, data files, etc. needed to produce an executable. It also saves IDE, compiler, and linker settings; compiling a project compiles and links all of its .cpp files.
- Each project corresponds to one program. Project files are IDE-specific.
- Console projects produce programs run from the Windows, Linux, or Mac console: no GUI, they print text, read keyboard input, and compile to stand-alone executables.
- A workspace/solution holds one or more related projects. The page recommends a new workspace/solution for each program while learning.
- Visual Studio (2019 or newer): create a project named HelloWorld, set Application type to Console Application (.exe), and uncheck Precompiled Header. The page explains precompiled headers help only large projects.
- Visual Studio: F7 (or Ctrl-Shift-B) builds; Ctrl-F5 runs without debugging.
- Code::Blocks: choose Console application, then edit main.cpp; Ctrl-F9 builds; Ctrl-F10 runs.
- VS Code: create a HelloWorld folder and main.cpp, run "g++ build and debug active file" (macOS users choose clang++), and check the TERMINAL tab for the text "Hello, world!".
- Command line: compile with g++ -o HelloWorld HelloWorld.cpp, then run HelloWorld (or ./HelloWorld).
- IDE terms: Build compiles only modified files and links them; Clean removes cached objects and executables; Rebuild is clean followed by build; Compile recompiles one file without linking; Run executes the prior executable (Visual Studio builds first).
- A cache is storage for frequently used data; IDEs cache object files so unmodified files need not be recompiled.
- If compiling fails: read the error message, check the reported line and its neighbors for typos, do not include line numbers in code, and check lesson 0.8 and the comments below the lesson.
- If the console flashes and closes, lesson 0.8 gives a pause solution.
- The page says not to worry if the Hello World lines are not yet understood; they are explained at the start of the next chapter.

### Code examples
```cpp
#include <iostream>

int main()
{
	std::cout << "Hello, world!";
	return 0;
}
```

### Best practice / Warnings
- Best practice: Create a new project for each new program you write.
- Tip: If you use anti-virus or anti-malware, consider excluding your project directory from scans, since compiling and debugging may cause false positives.

## 0.8 A few common C++ problems
<!-- 來源：https://www.learncpp.com/cpp-tutorial/a-few-common-cpp-problems/ -->

### Key points
- The page is a practical, non-comprehensive Q&A list of basic problems new programmers hit.
- Console closes immediately: add #include <iostream> and #include <limits> near the top, then add three lines at the end of main() just before return, so the program waits for a key press.
- The page says the common system("pause") approach may only work on some operating systems and should be avoided.
- Older Visual Studio may not pause in "Start With Debugging (F5)" mode; try "Start Without Debugging (Ctrl-F5)".
- A window with no output may be caused by virus scanner or anti-malware blocking execution; try disabling it temporarily.
- If a program compiles but misbehaves, debug it (chapter 3 covers this).
- "Unresolved external symbol _main or _WinMain@16" means the compiler cannot find main(); check the spelling, that the file containing main is compiled, and that the project is a console project.
- "main is already defined" or multiple definitions of main: a C++ program may have only one function named main.
- If C++11/14/17 features do not work, the compiler may be old or defaulting to an older standard (see lesson 0.12).
- "Cannot open the .exe for writing": usually the running .exe is locked; close it, check antivirus, or reboot. In Visual Studio this is error LNK1168.
- "cin, cout, or endl is an undeclared identifier": include <iostream> and prefix each use with std::.
- Lowercase L in endl is easily confused with the number 1; use a font that distinguishes them.
- Visual Studio C1010 error (precompiled headers): turn off precompiled headers, or add #include "pch.h" (or "stdafx.h" in older versions) as the first line of every code file.
- LNK2022 with _WinMain@16: the project was created as a Windows application instead of a Console application; recreate it.
- "Cannot find or open the PDB file" is a warning; the page suggests enabling "Microsoft Symbol Server" in Visual Studio options.
- For other problems, the page suggests searching the web, asking an AI (starting the question with "In C++,"), or asking on a Q&A board such as Stack Overflow.

### Code examples
```cpp
std::cin.clear(); // reset any error flags
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
std::cin.get(); // get one more char from the user
```

### Best practice / Warnings
(none)

## 1.1 Statements and the structure of a program
<!-- 來源：https://www.learncpp.com/cpp-tutorial/statements-and-the-structure-of-a-program/ -->

### Key points
- A computer program is a sequence of instructions. A statement is an instruction that causes the program to perform some action.
- Statements are the most common instruction type and the smallest independent unit of computation, much like sentences in natural language.
- Most (but not all) statements end in a semicolon; a line ending in a semicolon is probably a statement.
- One high-level statement may compile into many machine language instructions.
- Advanced-reader list of statement kinds: declaration, jump, expression, compound, selection (conditionals), iteration (loops), and try blocks.
- A function is a collection of statements executed sequentially, top to bottom.
- Every C++ program must have a function named main (all lowercase). Statements in main run in sequential order, and the program usually terminates after the last statement in main runs.
- Functions are named for a specific job (examples: max, calculateGrade, printEmployee).
- Shorthand: main() or doSomething() means the function named main or doSomething. The name of a function, object, type, template, etc. is its identifier.
- A character is a written symbol (letter, digit, punctuation, math symbol). A sequence of characters is text, also called a string in programming. C++ programs are written as plain text.
- Hello world walkthrough: line 1 is the #include preprocessor directive for iostream (needed for std::cout); line 3 defines main, which produces an int; the braces on lines 4 and 7 mark the function body; line 5 is the first statement and prints the text; line 6 is return 0, meaning the program ran successfully and is the last statement executed.
- Syntax is the set of rules for valid arrangement of program elements. The compiler halts with a syntax error when the program breaks them; compilation completes only after all syntax errors are fixed.
- Missing semicolon example: Clang reports line 5 at column 31, while Visual Studio reports line 6 (at return). The page explains each compiler's reasoning.

### Code examples
```cpp
#include <iostream>

int main()
{
   std::cout << "Hello world!";
   return 0;
}
```
Output shown on page:
```text
Hello world!
```

### Best practice / Warnings
- Rule: Every C++ program must have a special function named main (all lower case letters). A program without main will fail to link.
- Key insight: Compilers sometimes report an error on the line after the one where the fix conventionally belongs. If the error is not on the reported line, check the prior line.

## 1.2 Comments
<!-- 來源：https://www.learncpp.com/cpp-tutorial/comments/ -->

### Key points
- A comment is a programmer-readable note inserted in source code. The compiler ignores comments; they are for programmers.
- C++ has two comment styles: single-line // (ignores everything from // to the end of the line) and multi-line /* */ (C-style; everything between the symbols is ignored).
- Single-line comments may be aligned to the right of short lines of code; for long lines, the page places the comment above the line.
- Multi-line comments cannot be nested. The first */ ends the comment, so text after it is compiled and usually causes a compile error.
- Single-line comments may be placed inside a multi-line comment without problems.
- The page says comments should do three things: at library/program/function level describe what it does (at the top of a file or before a function); inside it describe how it works; at statement level describe why the code does something.
- A bad statement comment repeats what the code does; if a statement needs a comment explaining what it does, rewrite the statement instead.
- Good comments can record why a decision was made (e.g., choosing a linked list over an array).
- Write comments as if for someone with no idea what the code does; the page says it is not obvious and memory fades quickly.
- Commenting out code means turning lines into comments to exclude them temporarily; reasons listed include code that does not compile yet, broken code, isolating a bug, and keeping old code while testing replacements.
- IDE shortcuts given: Visual Studio (Edit > Advanced > Comment Selection), Code::Blocks (Edit > Comment, or Toggle comment), VS Code (ctrl-/).
- The page's tip: if you document code with multi-line comments, commenting out code with multi-line comments conflicts; #if 0 is an alternative (see lesson 2.10).
- Summary: at the library, program, or function level use comments for what; inside it for how; at the statement level for why.

### Code examples
```cpp
#include <iostream>

int main()
{
    // Replace this line with the snippet(s) of code you'd like to compile

    return 0;
}
```

```cpp
/* This is a multi-line /* comment */ this is not inside the comment */
// The above comment ends at the first */, not the second */
```

```cpp
// The player just drank a potion of blindness and can not see anything
sight = 0;
```

### Best practice / Warnings
- Best practice: Comment your code liberally, and write your comments as if speaking to someone who has no idea what the code does. Do not assume you will remember why you made specific choices.
- Warning: Do not use multi-line comments inside other multi-line comments. Wrapping single-line comments inside a multi-line comment is okay.
- Tip: If you always use single-line comments for normal comments, multi-line comments can safely comment out code.

## 1.5 Introduction to iostream: cout, cin, and endl
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/ -->

### Key points
- The io library (part of iostream) is the part of the C++ standard library for basic input and output. Include <iostream> in any file that uses it.
- std::cout ("character output") sends data to the console; the insertion operator << sends the data. It can print text, numbers, and variable values.
- Multiple << operators in one statement join several pieces of output on one line.
- Separate output statements do not produce separate lines; to end a line, output a newline. std::endl outputs a newline; without it, "Hi!" and "My name is Alex." print on one line.
- Output is buffered: it is stored in a buffer and flushed later. If the program crashes or is paused before a flush, buffered output may not display.
- std::endl both outputs a newline and flushes the buffer, which the page says is often inefficient. '\n' outputs a newline without flushing; the page prefers it.
- The page calls '\n' a single line-feed character, written with a backslash.
- std::cin ("character input") reads keyboard input with the extraction operator >>. The program waits for input at that statement.
- Multiple values can be read on one line if separated by whitespace.
- Input is buffered. Extraction skips leading whitespace, extracts characters until a newline or an invalid character, and stops at spaces for ints. Leftover input is used by later extractions.
- Extraction failure (e.g., typing "b" into an int) sets the variable to 0 (C++11 and later), and later extractions fail until std::cin is cleared (see lesson 9.5).
- Quiz results: letters entered into an int give 0; 3.2 gives 3 (fraction dropped, not rounded); "5a" gives 5; very large values give the largest int value on the page's system (2147483647 likely).
- Mnemonic: std::cin and std::cout go on the left of the operator; << shows data moving to std::cout, >> shows data moving into std::cin.

### Code examples
```cpp
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{};       // define variable x to hold user input (and value-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}
```
Output shown on page:
```text
Enter a number: 4
You entered 4
```

```cpp
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter two numbers separated by a space: ";

    int x{}; // define variable x to hold user input (and value-initialize it)
    int y{}; // define variable y to hold user input (and value-initialize it)
    std::cin >> x >> y; // get two numbers and store in variable x and y respectively

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;
}
```
Output shown on page:
```text
Enter two numbers separated by a space: 5 6
You entered 5 and 6
```

```cpp
#include <iostream> // for std::cout

int main()
{
    int x{ 5 };
    std::cout << "x is equal to: " << x << '\n'; // single quoted (by itself) (conventional)
    std::cout << "Yep." << "\n";                 // double quoted (by itself) (unconventional but okay)
    std::cout << "And that's all, folks!\n";     // between double quotes in existing text (conventional)
    return 0;
}
```
Output shown on page:
```text
x is equal to: 5
Yep.
And that's all, folks!
```

### Best practice / Warnings
- Best practice: Output a newline whenever a line of output is complete.
- Best practice: Prefer \n over std::endl when outputting text to the console.
- Warning: '\n' uses a backslash, not a forward slash. Writing '/n' or multiple characters inside single quotes gives unexpected behavior; the page says std::cout << '/n'; often prints 12142.
- Key insight: Buffered output is processed first in, first out. Buffering batches output to reduce slow transfers to the output device.
- Key insight: Each line of input in the input buffer is terminated by a '\n' character. Initialize a variable before reading user input into it (best practice per the page).
- Tip: Imagine << (and >>) as a conveyor belt moving data in the indicated direction.
- Tip: No need to output '\n' when accepting input, because the user pressing enter moves the cursor to the next line.

## 3.1 Syntax and semantic errors
<!-- 來源：https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/ -->

### Key points
- Errors generally fall into two categories: syntax errors and semantic errors (logic errors).
- A syntax error is a statement that is not valid under C++ grammar, such as missing semicolons or mismatched parentheses or braces. The compiler detects these and issues a warning or error.
- After syntax errors are fixed, the program is compiled again until no errors remain.
- A semantic error is an error in meaning: the statement is syntactically valid but violates other language rules or does not do what the programmer intended.
- Some semantic errors are caught by the compiler, e.g., using an undeclared variable or type mismatches (the page's examples: assigning to a literal 5, returning "hello" from an int function).
- Other semantic errors appear only at runtime: they may crash the program (the page's example is division by zero) or produce wrong values or behavior (uninitialized variable use; a function using the wrong operator; code after a return that never executes).
- In non-trivial programs runtime semantic errors are hard to find by inspection; the page says debugging techniques help (covered in chapter 3).
- The page notes that debugging tools are not part of the C++ standard, but finding and removing bugs is an important skill.

### Code examples
```cpp
#include <iostream>

int main( // missing closing brace
{
    int 1x; // variable name can't start with number
    std::cout << "Hi there"; << x +++ << '\n'; // extraneous semicolon, operator+++ does not exist
    return 0 // missing semicolon at end of statement
}
```

```cpp
#include <iostream>

int main()
{
    int a { 10 };
    int b { 0 };
    std::cout << a << " / " << b << " = " << a / b << '\n'; // division by 0 is undefined in mathematics
    return 0;
}
```

```cpp
#include <iostream>

int add(int x, int y) // this function is supposed to perform addition
{
    return x - y; // but it doesn't due to the wrong operator being used
}

int main()
{
    std::cout << "5 + 3 = " << add(5, 3) << '\n'; // should produce 8, but produces 2

    return 0;
}
```

### Best practice / Warnings
(none)
