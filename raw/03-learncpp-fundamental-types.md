---
title: learncpp — 基本型別
site: https://www.learncpp.com/
retrieved: 2026-11-20
format: 摘錄筆記（非全文；由 Claude Code 以 web-fetch 逐篇讀取原頁後擷取，程式碼為原頁原文）
lessons:
  - id: "4.1"
    title: Introduction to fundamental data types
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-fundamental-data-types/
  - id: "4.4"
    title: Signed integers
    url: https://www.learncpp.com/cpp-tutorial/signed-integers/
  - id: "4.8"
    title: Floating point numbers
    url: https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
  - id: "4.9"
    title: Boolean values
    url: https://www.learncpp.com/cpp-tutorial/boolean-values/
  - id: "4.11"
    title: Chars
    url: https://www.learncpp.com/cpp-tutorial/chars/
  - id: "4.12"
    title: Introduction to type conversion and static_cast
    url: https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
---

> 收錄 lesson：4.1、4.4、4.8、4.9、4.11、4.12
> 這是**摘錄筆記**，不是全文轉載：重點為忠實改述（保留原站英文用語），引號內為原文短句，程式碼區塊為原頁原文。
> 本檔為唯讀原始資料，ingest 時不可修改。

## 4.1 Introduction to fundamental data types
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-fundamental-data-types/ -->

### Key points
- A variable is a name for a piece of memory. Defining a variable sets aside a piece of RAM for it.
- A bit is the smallest unit of memory and holds 0 or 1. The page compares it to a light switch.
- Each memory address holds 1 byte, not 1 bit. A byte is a group of bits operated on as a unit. The modern standard is 8 bits per byte, and the tutorials assume 8.
- All data is a sequence of bits, so a data type tells the compiler how to interpret the bits in memory. The page's example: the value 65 is stored as `0100 0001` and reconstituted as 65.
- The compiler and CPU handle the encoding and decoding. The programmer's job is to pick a data type that matches the intended use.
- Fundamental types (also called "basic types" or "primitive types") include floating point (`float`, `double`, `long double`), `bool`, the char types, the standard integer types, `std::nullptr_t` (C++11, covered with pointers), and `void`.
- "Integral" in C++ means "like an integer." The integral types are `bool`, the char types, and the standard integer types.
- The standard integer types are `short`, `int`, `long`, and `long long`, including their signed and unsigned variants.
- All integral types are stored as integer values, but only the standard integer types display as integers when output. `enum` and `enum class` are not integral types, even though they are stored as integers.
- The page describes three sets of types: fundamental types and compound types (built into the language, no header needed), and types from the standard library (which require the appropriate header).
- The page says "built-in type" is not well-defined and recommends avoiding the term.
- Strings are not a fundamental type. They are part of the standard library and are introduced in lesson 5.7.
- A `_t` suffix usually means "type," but the convention is not applied consistently.

### Code examples
(none on page)

### Best practice / Warnings
- Key insight: in C++, we typically work with "byte-sized" chunks of data.
- No Best practice, Warning, Tip, or Rule boxes appear on this page.

## 4.4 Signed integers
<!-- 來源：https://www.learncpp.com/cpp-tutorial/signed-integers/ -->

### Key points
- An integer is an integral type that holds positive and negative whole numbers, including 0.
- C++ has four primary fundamental integer types: `short int`, `int`, `long int`, and `long long int`, with minimum sizes of 16, 16, 32, and 64 bits. `int` is typically 32 bits on modern architectures.
- C++ guarantees only minimum sizes, not exact sizes. The page points to lesson 4.3 for finding each type's size on a given machine.
- Integers are signed by default, so the sign is stored as part of the value and the type can hold positive, negative, and zero values.
- Preferred names are `short`, `int`, `long`, and `long long`. The page prefers these over the forms with the `int` suffix.
- The optional `signed` keyword is redundant because integers are already signed, and the page says it should not be used.
- The range of an integer depends on its size in bits and whether it is signed. Signed ranges given: 8-bit is -128 to 127, 16-bit is -32,768 to 32,767, 32-bit is -2,147,483,648 to 2,147,483,647, and 64-bit is -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807.
- An n-bit signed variable has a range of -(2^(n-1)) to (2^(n-1))-1.
- Overflow happens when a value is outside the range of its type. For signed integers, overflow (including integer overflow from arithmetic) causes undefined behavior.
- Assigning 140 to an 8-bit signed integer is an example of overflow.
- Integer division always produces an integer result. The fractional part is dropped, not rounded: `8 / 5` gives 1, and `-8 / 5` gives -1.
- The page notes that the results of integer division are predictable, so it is safe to use when a whole-number result is what you want.
- The page says overflow generally loses information, which is almost never desirable. Use a type with a larger range if there is any suspicion a value could exceed the range.

### Code examples
```cpp
#include <iostream>

int main()
{
	std::cout << 8 / 5 << '\n';
	return 0;
}
```
Output shown on page:
```text
1
```

```cpp
#include <iostream>

int main()
{
    // assume 4 byte integers
    int x { 2'147'483'647 }; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    std::cout << x << '\n';

    return 0;
}
```
Output shown on page (the page notes the second value is undefined behavior and may vary by machine):
```text
2147483647
-2147483648
```

### Best practice / Warnings
- Best practice: prefer the shorthand integer type names that do not use the `int` suffix or the `signed` prefix (for example, `long long` rather than `long long int`).
- Warning: integer division loses any fractional part of the quotient. It is safe when that truncated result is what you want.
- Key point from the overflow section (not a labeled box): signed overflow is undefined behavior, as the page explains.

## 4.8 Floating point numbers
<!-- 來源：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/ -->

### Key points
- A floating point variable holds a number with a fractional component, such as 4320.0, -3.33, or 0.01226. The decimal point can "float," so the number of digits before and after it can vary.
- Floating point types are always signed.
- C++ has three fundamental floating point types: `float` (single precision), `double` (double precision), and `long double` (extended precision). Typical sizes are 4 bytes for `float`, 8 bytes for `double`, and 8, 12, or 16 bytes for `long double`.
- On modern architectures, `float` is almost always 4 bytes and `double` is almost always 8 bytes, using IEEE 754 formats.
- The page recommends avoiding `long double`, because its size and format vary by platform.
- Floating point literals without a suffix are of type `double`. The `f` suffix makes a `float` literal. A literal with a decimal point, such as `5.0`, is floating point even when the fractional part is 0.
- The decimal separator in code must be a decimal point (Tip).
- `std::cout` does not print the fractional part of a value whose fractional part is 0, so `5.0` prints as `5`. Large values may print in scientific notation.
- Precision is the number of significant digits a type can represent without information loss. A `float` has 6 to 9 digits of precision (typically 7). A `double` has 15 to 18 digits (typically 16).
- By default, `std::cout` shows 6 digits of precision. `std::setprecision()` (from the `<iomanip>` header) overrides this.
- A rounding error occurs when a number cannot be stored precisely. The page shows that the decimal 0.1 has no exact binary representation.
- Rounding errors grow with repeated mathematical operations. Adding 0.1 ten times gives a result that is not exactly 1.0.
- Comparing floating point numbers can give unexpected results. The page defers the solutions to lesson 6.7.
- IEEE 754 formats also support Inf (positive and negative infinity), NaN ("Not a Number"), and signed zero. Non-IEEE 754 formats may not support these values.

### Code examples
```cpp
#include <iostream>

int main()
{
	std::cout << 5.0 << '\n';
	std::cout << 6.7f << '\n';
	std::cout << 9876543.21 << '\n';

	return 0;
}
```
Output shown on page:
```text
5
6.7
9.87654e+06
```

```cpp
#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
	std::cout << std::setprecision(17);

	double d1{ 1.0 };
	std::cout << d1 << '\n';

	double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0
	std::cout << d2 << '\n';

	return 0;
}
```
Output shown on page:
```text
1
0.99999999999999989
```

### Best practice / Warnings
- Best practice: make sure the type of a literal matches the type of the variable it initializes or is assigned to. Otherwise an unnecessary conversion occurs, possibly losing precision.
- Best practice: favor `double` over `float` unless space is at a premium, because `float`'s lack of precision often causes inaccuracies.
- Best practice: avoid division by `0.0`, even if the compiler supports it.
- Tip: this tutorial series assumes an IEEE 754 compatible format for `float` and `double`.
- Tip: output manipulators such as `std::setprecision` stay set once applied. The exception is `std::setw`, which some IO operations reset, so it should be used every time it is needed.
- Key insight: rounding errors are the norm, not the exception. Never assume floating point numbers are exact.
- Key insight (corollary): be wary of using floating point numbers for financial or currency data.

## 4.9 Boolean values
<!-- 來源：https://www.learncpp.com/cpp-tutorial/boolean-values/ -->

### Key points
- A Boolean variable can have only two values, `true` and `false`. It is declared with the keyword `bool`.
- `true` and `false` are the keywords used to initialize or assign Boolean values. `bool b3 {};` default-initializes to `false`.
- The logical NOT operator (`!`) flips a Boolean value.
- Booleans are stored as integers: `true` is stored as 1 and `false` as 0. They evaluate to 1 and 0, so `bool` is an integral type.
- By default, `std::cout` prints `1` for `true` and `0` for `false`. Outputting `std::boolalpha` makes it print `true` and `false`. `std::noboolalpha` turns this off.
- With braces, the integer literals `0` and `1` can initialize a `bool`. Other integer literals cause a compilation error because they are narrowing conversions.
- With copy initialization (and any context where an integer converts to `bool`), `0` becomes `false` and any other integer becomes `true`. The page notes that `bool b1 = 4;` may generate a warning.
- By default, `std::cin` accepts only numeric input for a `bool`: `0` is read as `false`, and `1` as `true`. Other numbers are read as `true` and put `std::cin` into failure mode. Non-numeric input is read as `false` and also causes failure mode.
- Entering `true` into a `bool` using default `std::cin` therefore results in `false` (printed as 0), and the page says this is a common trip-up for new programmers.
- `std::cin >> std::boolalpha;` allows the words `false` and `true` as input. This is independent of the output setting.
- Functions that return a Boolean are typically named starting with `is` (for example `isEqual`) or `has` (for example `hasCommonDivisor`).
- The page says you will use Boolean values more than all the other fundamental types put together.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';
    return 0;
}
```
Output shown on page:
```text
1
0
true
false
```

```cpp
#include <iostream>

int main()
{
	std::cout << std::boolalpha; // print bools as true or false

	bool b1 = 4 ; // copy initialization allows implicit conversion from int to bool
	std::cout << b1 << '\n';

	bool b2 = 0 ; // copy initialization allows implicit conversion from int to bool
	std::cout << b2 << '\n';

	return 0;
}
```
Output shown on page:
```text
true
false
```

### Best practice / Warnings
- Warning: enabling `std::boolalpha` for input accepts only lowercase `false` or `true`. Capitalized variants are rejected, and `0` and `1` are no longer accepted.
- The page notes that `std::cin` input for `bool` can leave the stream in failure mode, and refers to lesson 9.5 for how to recover.

## 4.11 Chars
<!-- 來源：https://www.learncpp.com/cpp-tutorial/chars/ -->

### Key points
- The `char` type holds a single character, which can be a letter, number, symbol, or whitespace.
- `char` is an integral type. The stored integer is interpreted as an ASCII character.
- ASCII (American Standard Code for Information Interchange) maps English characters and some symbols to numbers from 0 to 127, called ASCII codes or code points. For example, code 97 is `'a'`.
- Character literals go between single quotes, such as `'g'`, `'1'`, and `' '`.
- Codes 0 to 31 and 127 are "unprintable" control codes, mostly obsolete. Codes 32 to 126 are the printable characters.
- A `char` initialized with a character literal (`char ch2{ 'a' };`) is the preferred form. Initializing with an integer (`char ch1{ 97 };`) is not preferred.
- Be careful not to confuse character numbers with integers. `char ch{5};` stores the integer 5, while `char ch{'5'};` stores code 53.
- When `std::cout` prints a `char`, it outputs the ASCII character, not the number.
- `std::cin >> ch` extracts one character, skips leading whitespace, and leaves the rest of the input in the buffer for later extraction.
- `std::cin.get(ch)` does not skip leading whitespace, so it can read a space.
- `char` is always 1 byte. Its signedness is implementation-dependent, though usually signed. A signed `char` holds -128 to 127, and an unsigned `char` holds 0 to 255.
- Escape sequences start with a backslash. The page lists `\n`, `\t`, `\'`, `\"`, and `\\` among others, and the `\x` hex form and octal form.
- Single quotes denote a `char` literal, and double quotes denote a C-style string literal.
- Multicharacter literals such as `'56'` have implementation-defined values and should be avoided.
- `char8_t`, `char16_t`, and `char32_t` are for Unicode. `wchar_t` should be avoided except when interfacing with the Windows API. The page says to use only ASCII characters for these tutorials.

### Code examples
```cpp
#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

    char ch{};
    std::cin.get(ch); // extracts a, leaves " b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    std::cin.get(ch); // extracts space, leaves "b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    return 0;
}
```
Output shown on page (the second "You entered:" line ends with a space character):
```text
Input a keyboard character: a b
You entered: a
You entered: 
```

```cpp
#include <iostream>

int add(int x, int y)
{
	return x + y;
}

int main()
{
	std::cout << add(1, 2) << '/n'; // we used a forward slash instead of a backslash here

	return 0;
}
```
Output shown on page (the page says this is the author's machine's output; the value of the multicharacter literal is implementation-defined):
```text
312142
```

### Best practice / Warnings
- Warning: escape sequences start with a backslash (`\`), not a forward slash (`/`). A forward slash may still compile but will not give the desired result.
- Warning: make sure newlines use the escape sequence `'\n'`, not the multicharacter literal `'/n'`.
- Best practice: single characters should usually be single-quoted (for example `'t'` or `'\n'`, not `"t"`). The page notes an exception for output, where double-quoting everything can be preferred for consistency.
- Best practice: avoid multicharacter literals (for example `'56'`).
- Key insight: printing character literals in double quotes (for example `"/n"`) either makes such mistakes easier to find or avoids them.

## 4.12 Introduction to type conversion and static_cast
<!-- 來源：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/ -->

### Key points
- Type conversion is the process of converting a value from one fundamental type to another. When the compiler does this without an explicit request, it is called implicit type conversion. The page's example: passing the `int` 5 to a `double` parameter converts it to 5.0.
- Type conversion does not modify the source value or object. It takes the value as input and produces a new (temporary) converted value. The page compares this to a function call whose return type is the target type.
- Passing a `double` value to an `int` parameter causes an implicit conversion that drops the fractional part. The page's example prints 5 for the argument 5.5.
- Compilers generate a warning for implicit floating point to integer conversions, even when no value is lost (such as 5.0 to 5). With "treat warnings as errors" enabled, the compilation is aborted.
- Some conversions preserve value (such as `char` to `int`). Others, such as `double` to `int`, can change the value.
- Brace initialization prevents unsafe implicit conversions. `double d { 5 };` is allowed, but `int x { 5.5 };` is an error. The page says this is one of the primary reasons brace initialization is preferred.
- Explicit type conversion lets the programmer state the conversion and take responsibility for it. The compiler does not warn about loss of value in that case.
- The `static_cast` syntax is `static_cast<new_type>(expression)`. It takes the value of the expression and returns it converted to `new_type`.
- Using `static_cast` on a `char` to get its integer value leaves the variable itself unchanged.
- `static_cast` can convert between signed and unsigned integers. If the value fits in the destination type, only the type changes.
- If an unsigned destination cannot represent the value, the result is modulo wrapped. If a signed destination cannot represent it, the result is implementation-defined before C++20 and modulo wrapped as of C++20.
- `std::int8_t` and `std::uint8_t` are usually treated like `signed char` and `unsigned char`, so `std::cout` prints `A` for 65 on most systems. Converting with `static_cast<int>` prints 65.
- Console input into `std::int8_t` reads characters, so entering `35` stores 51 (the code for `'3'`) on most systems.

### Code examples
```cpp
#include <iostream>

void print(int x)
{
	std::cout << x << '\n';
}

int main()
{
	print( static_cast<int>(5.5) ); // explicitly convert double value 5.5 to an int

	return 0;
}
```
(The page does not show output for this program.)

```cpp
#include <iostream>

int main()
{
    char ch{ 97 }; // 97 is ASCII code for 'a'
    // print value of variable ch as an int
    std::cout << ch << " has value " << static_cast<int>(ch) << '\n';

    return 0;
}
```
Output shown on page:
```text
a has value 97
```

```cpp
#include <iostream>

int main()
{
    int s { -1 };
    std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295 

    unsigned int u { 4294967295 }; // largest 32-bit unsigned int
    std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20
    
    return 0;
}
```
Output shown on page (the page says "As of C++20, this produces the result"):
```text
4294967295
-1
```

### Best practice / Warnings
- Warning: converting an unsigned integral value to a signed integral value gives implementation-defined behavior before C++20 if the value cannot be represented in the signed type.
- Tip: disabling "treat warnings as errors" temporarily is needed to compile the page's implicit-conversion example. Lesson 0.11 covers this setting.
- Key insight: angle brackets in C++ syntax (outside the preprocessor) usually enclose a type, as in `static_cast<new_type>`.
- Key insight: prefer explicit conversions and brace initialization to keep unsafe conversions visible. The page notes that quiz answers showing implicit conversion are for testing understanding, not for real programs.
