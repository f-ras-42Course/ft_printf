# ft_printf

A custom implementation of the standard C library function `printf`, developed during my journey at **42 School**. This project was an exciting deep dive into variadic functions, formatted output, and low-level handling of variable arguments. It challenged me to explore the depths of C programming and refine my problem-solving skills.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
  - [Supported Conversions](#supported-conversions)
  - [Code Architecture](#code-architecture)
  - [Jump Table Implementation](#jump-table-implementation)
  - [Personal Touches](#personal-touches)
- [Testing](#testing)
- [Conclusion](#conclusion)
- [Acknowledgments](#acknowledgments)

## Overview

The `ft_printf` project aims to recreate the functionality of the standard `printf` function in C. By handling various format specifiers and flags, I gained a deeper understanding of how formatted output works under the hood. This project emphasized clean code practices, efficient algorithm design, and robust error handling.

## Features

- **Multiple Format Specifiers**: Supports characters, strings, pointers, integers, unsigned integers, and hexadecimal numbers.
- **Width and Precision Handling**: Implements width and precision modifiers for flexible formatting.
- **Optimized Performance**: Utilizes a custom buffer and a jump table for efficient execution.
- **Robust Error Handling**: Manages invalid inputs and unexpected scenarios gracefully.

## Installation

Clone the repository:

```bash
git clone https://github.com/f-ras-42Course/ft_printf.git
```

Navigate to the project directory and compile:

```bash
cd ft_printf
make
```

## Usage

Include the `ft_printf.h` header in your source files:

```c
#include "ft_printf.h"
```

Link the compiled library when building your program:

```bash
gcc your_program.c -L. -lftprintf -o your_program
```

Example:

```c
int main(void)
{
    ft_printf("Hello, %s! The number is %d.\n", "world", 42);
    return 0;
}
```

## Implementation Details

Developed in C, `ft_printf` uses variadic functions to handle an indefinite number of arguments. The core functionality revolves around parsing the format string and processing each specifier accordingly.

### Supported Conversions

- **Characters**: `%c`
- **Strings**: `%s`
- **Pointers**: `%p`
- **Decimal Integers**: `%d` and `%i`
- **Unsigned Integers**: `%u`
- **Hexadecimal Numbers**: `%x` and `%X`
- **Percent Sign**: `%%`

### Code Architecture

To enhance readability and maintainability, I structured the code into distinct modules:

- **Parser**: Analyzes the format string and identifies format specifiers.
- **Handlers**: Contains functions to process each type of specifier.
- **Utilities**: Includes helper functions for conversions, buffer management, and formatting.

### Jump Table Implementation

One of the key optimizations in my implementation was the use of a **jump table** to dispatch handler functions for each format specifier. Instead of using lengthy if-else chains or switch statements, the jump table maps specifiers directly to their corresponding handler functions. This approach improves execution speed and makes the code cleaner and more scalable.

Here's an excerpt from my actual code demonstrating the jump table:

```c
int print_conversion(va_list ap, const char index)
{
    static const t_Jump_index convert[] = {
        ['c'] = &pfhelper_putchar,
        ['s'] = &pfhelper_putstr,
        ['i'] = &pfhelper_putnbr,
        ['d'] = &pfhelper_putnbr,
        ['u'] = &pfhelper_putnbr_unsigned,
        ['x'] = &pfhelper_puthex_lowercase,
        ['X'] = &pfhelper_puthex_uppercase,
        ['p'] = &pfhelper_putpointeraddress,
    };

    return (convert[(unsigned int)index](ap));
}
```

In this code:

- **Jump Table (`convert`)**: An array of function pointers that maps format specifiers to their corresponding handler functions.
- **`print_conversion` Function**: Uses the jump table to call the appropriate handler based on the specifier.
- **`conversions` Function**: Checks if the given character is a valid conversion specifier.

This implementation allows for O(1) lookup times for handler functions and makes adding new specifiers straightforward.

### Personal Touches

Implementing the jump table was a personal highlight, showcasing my interest in efficient coding practices and data structures. By avoiding long conditional statements, the code became more readable and maintainable. I also focused on writing clean and well-documented code, adhering to consistent coding standards throughout the project.

## Testing

To ensure that `ft_printf` behaves like the standard `printf`, I wrote extensive test cases covering:

- All supported specifiers and combinations.
- Edge cases like maximum and minimum integer values.
- Null pointers and empty strings.
- Mixed format strings with multiple specifiers.

I compared the output and return values of `ft_printf` with those of `printf`, ensuring consistency and reliability.

## Conclusion

Working on `ft_printf` was a significant learning experience. Implementing a function as widely used and complex as `printf` challenged me to think critically about software design and optimization. The use of a jump table was particularly satisfying, as it improved both the performance and readability of the code.

I'm proud of the personal touches I added to the project, especially in optimizing performance and ensuring code clarity. This project not only enhanced my technical skills but also reinforced the importance of writing efficient and maintainable code.

## Acknowledgments

- **42 School**: For providing an intensive and hands-on learning environment.
- **Peers and Instructors**: For their support, code reviews, and collaborative problem-solving.
- **Open-source Community**: For resources and inspirations that guided my implementation choices.

---

Feel free to explore, use, and modify this project. Contributions and feedback are welcome!

