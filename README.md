# FT_PRINTF - Custom printf Implementation

A 42 Common Core project that recreates the behavior of the standard C library printf function using variadic functions and format specifiers.

## Overview

The ft_printf project challenges students to implement their own version of the famous printf function from scratch. This project deepens understanding of variadic functions, format string parsing, and low-level output operations while adhering to strict coding standards and memory management practices.

The implementation handles multiple format specifiers and manages different data types, providing a solid foundation for understanding how formatted output works at a fundamental level.

## Quick Start

### Installation
```bash
git clone https://github.com/BeAzarym/ft_printf.git
cd ft_printf
make
```

### Basic Usage
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

### Compilation with your project
```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lftprintf
```

## Format Specifiers

The ft_printf function supports the following format specifiers:

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | Pointer address (hexadecimal) | `ft_printf("%p", ptr)` → `0x7fff5fbff710` |
| `%d` | Signed decimal integer | `ft_printf("%d", -42)` → `-42` |
| `%i` | Signed decimal integer | `ft_printf("%i", 42)` → `42` |
| `%u` | Unsigned decimal integer | `ft_printf("%u", 42u)` → `42` |
| `%x` | Hexadecimal (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%%` | Literal percent sign | `ft_printf("%%")` → `%` |

## Example Usage

### Basic Examples
```c
// Character and string handling
ft_printf("Character: %c\n", 'A');                    // Character: A
ft_printf("String: %s\n", "Hello World");             // String: Hello World
ft_printf("NULL string: %s\n", NULL);                 // NULL string: (null)

// Integer formatting
ft_printf("Decimal: %d\n", 42);                       // Decimal: 42
ft_printf("Negative: %d\n", -42);                     // Negative: -42
ft_printf("Unsigned: %u\n", 4294967295u);             // Unsigned: 4294967295

// Hexadecimal formatting
ft_printf("Lowercase hex: %x\n", 255);                // Lowercase hex: ff
ft_printf("Uppercase hex: %X\n", 255);                // Uppercase hex: FF

// Pointer addresses
int x = 42;
ft_printf("Address of x: %p\n", &x);                  // Address of x: 0x7fff5fbff71c

// Mixed formats
ft_printf("User %s has %d points (0x%x)\n", "Alice", 1000, 1000);
// Output: User Alice has 1000 points (0x3e8)
```

### Advanced Examples
```c
// Multiple format specifiers
ft_printf("%s: %c=%d, hex=%x, ptr=%p\n", 
          "Debug info", 'X', 42, 42, &main);

// Edge cases
ft_printf("Zero: %d %u %x %X\n", 0, 0, 0, 0);         // Zero: 0 0 0 0
ft_printf("Max int: %d\n", 2147483647);               // Max int: 2147483647
ft_printf("Min int: %d\n", -2147483648);              // Min int: -2147483648
```

## Testing

### Basic Functionality Tests
```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;
    
    // Test return values
    ret1 = ft_printf("ft_printf: %d\n", 42);
    ret2 = printf("printf: %d\n", 42);
    printf("Return values - ft_printf: %d, printf: %d\n", ret1, ret2);
    
    // Test all format specifiers
    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Test");
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Decimal: %d\n", -42);
    ft_printf("Integer: %i\n", 42);
    ft_printf("Unsigned: %u\n", 42u);
    ft_printf("Hex lower: %x\n", 255);
    ft_printf("Hex upper: %X\n", 255);
    ft_printf("Percent: %%\n");
    
    return (0);
}
```

### Edge Case Tests
```c
// Test NULL string handling
ft_printf("NULL string: %s\n", NULL);                 // Should print: (null)

// Test extreme values
ft_printf("INT_MAX: %d\n", 2147483647);
ft_printf("INT_MIN: %d\n", -2147483648);
ft_printf("UINT_MAX: %u\n", 4294967295u);

// Test zero values
ft_printf("Zero pointer: %p\n", NULL);                // Should print: 0x0
ft_printf("Zero values: %d %u %x %X\n", 0, 0, 0, 0);

// Test single character
ft_printf("%c", 'A');                                 // No newline
```

### Performance Comparison
```c
#include <time.h>

void performance_test(void)
{
    clock_t start, end;
    int i;
    
    // Test ft_printf performance
    start = clock();
    for (i = 0; i < 10000; i++)
        ft_printf("Test %d: %s %c %x\n", i, "benchmark", 'X', i);
    end = clock();
    printf("ft_printf time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Test standard printf performance
    start = clock();
    for (i = 0; i < 10000; i++)
        printf("Test %d: %s %c %x\n", i, "benchmark", 'X', i);
    end = clock();
    printf("printf time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}
```

## Project Structure

```
ft_printf/
├── ft_printf.c           # Main printf function implementation
├── ft_printf_utils.c     # Format conversion and utility functions
├── ft_printf.h           # Header with function prototypes
├── Makefile              # Build configuration
├── libft/                # Personal C library (dependency)
│   ├── [libft files...]
│   ├── libft.h
│   └── Makefile
└── README.md
```

## Technical Implementation

### Key Functions

#### Core Function
```c
int ft_printf(const char *format, ...);
```
- **Purpose**: Main printf function that processes format string and variadic arguments
- **Return**: Number of characters printed
- **Parameters**: Format string and variable number of arguments

#### Utility Functions
```c
size_t ft_convert(char type, va_list ap);          // Format specifier handler
int    ft_print_char(char c);                      // Character output
int    ft_print_str(char *str);                    // String output
size_t ft_print_nbr(long int n);                   // Decimal number output
size_t ft_print_nbr_base(unsigned long int n, const char *base);  // Base conversion
```

### Key Concepts Implemented

**Variadic Functions**: Using `va_list`, `va_start`, `va_arg`, and `va_end` to handle variable arguments
**Format String Parsing**: Character-by-character analysis of format strings
**Type Conversion**: Converting different data types to string representations
**Base Conversion**: Converting numbers to different bases (decimal, hexadecimal)
**Memory Safety**: Proper handling of NULL pointers and edge cases
**Return Value Management**: Tracking and returning the number of characters printed

### Algorithm Overview

1. **Initialization**: Set up variadic argument list
2. **String Parsing**: Iterate through format string character by character
3. **Format Detection**: Identify '%' characters and following specifiers
4. **Type Conversion**: Convert arguments based on format specifiers
5. **Output**: Write characters to standard output
6. **Length Tracking**: Count and return total characters written

### Memory Management

- **Stack-based**: Uses stack allocation for temporary variables
- **No Dynamic Allocation**: Avoids malloc/free for simplicity and safety
- **Write System Call**: Direct use of write() for output operations
- **Buffer Management**: Immediate output without internal buffering

## Build Commands

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Full rebuild
```

The Makefile creates `libftprintf.a` which can be linked with your projects.

## Dependencies

- **libft**: Custom C library with basic functions (strlen, etc.)
- **System Libraries**: `<unistd.h>` for write(), `<stdarg.h>` for variadic functions