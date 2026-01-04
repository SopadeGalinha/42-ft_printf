# ft_printf

*This project has been created as part of the 42 curriculum by jhogonca.*

---

## Description

The `ft_printf` project is a comprehensive implementation of the C standard library's `printf` function. The goal is to recreate the functionality of `printf` from scratch, supporting all mandatory format specifiers and implementing bonus flags for advanced formatting capabilities.

**Project Goal:**
- Understand the mechanics of variadic functions and variable argument handling
- Master format string parsing and conversion logic
- Implement proper flag handling and output formatting
- Return exact byte counts matching the standard `printf` function

**Key Features:**
- **Mandatory Format Specifiers:** `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- **Bonus Format Specifiers:** `%o` (octal), `%b` (binary)
- **Bonus Flags:** `0` (zero-padding), `-` (left-align), `+` (plus sign), ` ` (space), `#` (hash prefix)
- **Advanced Features:** Width, precision, and dynamic width/precision with `*` flag
- **100% Compatibility:** Output and return values match standard `printf` exactly

---

## Instructions

### Compilation

To compile the library:

```bash
make
```

This generates `libftprintf.a`, a static library containing the `ft_printf` function.

To compile and run the comprehensive test suite (548 tests):

```bash
make test
```

To run only mandatory tests (380 tests):

```bash
make test-mandatory
```

To run only bonus and edge case tests (168 tests):

```bash
make test-bonus
```

To view available make targets:

```bash
make help
```

### Installation

1. Clone or copy the repository to your project directory
2. Include the header file in your code:

```c
#include "ft_printf.h"
```

3. Link against the library when compiling:

```bash
gcc your_main.c -L. -lftprintf -o your_program
```

### Usage Examples

Use `ft_printf` exactly like the standard `printf`:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d, Hex: %x\n", 42, 255);
    ft_printf("%+08.3d\n", 42);  // Bonus flags: +, 0, width, precision
    ft_printf("%-15s %#x\n", "left-aligned", 255);
    return (0);
}
```

### Supported Format Specifiers

| Specifier | Description | Type |
|-----------|-------------|------|
| `%c` | Single character | Mandatory |
| `%s` | String | Mandatory |
| `%p` | Pointer (hex) | Mandatory |
| `%d` | Decimal integer | Mandatory |
| `%i` | Integer | Mandatory |
| `%u` | Unsigned integer | Mandatory |
| `%x` | Hex lowercase | Mandatory |
| `%X` | Hex uppercase | Mandatory |
| `%%` | Literal percent | Mandatory |
| `%o` | Octal | Bonus |
| `%b` | Binary | Bonus |

### Supported Flags

| Flag | Description | Example |
|------|-------------|---------|
| `-` | Left-align output | `%-10d` |
| `0` | Zero-pad numbers | `%08d` |
| `+` | Show sign for positive | `%+d` |
| ` ` | Space for positive | `% d` |
| `#` | Alternate form (0x, 0) | `%#x` |
| `*` | Dynamic width | `%*d` |
| `.` | Precision | `%.5s` |

---

## Algorithm & Data Structure Explanation

### Parsing Strategy

The implementation uses a **two-pass finite state machine** approach:

1. **First Pass - Format String Parsing:**
   - Scans the format string character by character
   - Identifies format specifiers starting with `%`
   - Extracts flags, width, precision, and conversion specifier
   - Handles dynamic width/precision by consuming variadic arguments in order

   **Structure:** `t_flags` struct stores:
   - Individual flag fields (minus, zero, plus, space, hash)
   - Width and precision (stored as integers, -1 = not specified)
   - Conversion character

2. **Second Pass - Conversion & Output:**
   - Routes each conversion type to appropriate handler function
   - Applies flags and formatting rules
   - Outputs formatted data to stdout via `write()`
   - Maintains total byte count for return value

### Key Design Decisions

**1. Output via `write()` instead of `printf()`:**
- Avoids circular dependency
- Direct system call gives precise control
- Maintains accurate byte counting

**2. Flags Implementation:**
- Uses individual integer fields in `t_flags` struct for each flag (minus, zero, plus, space, hash)
- Flag precedence handled during conversion (e.g., `+` overrides ` `)
- Left-align (`-`) disables zero-padding

**3. Precision Behavior:**
- For integers: minimum number of digits (zero-pads with digits, not spaces)
- For strings: maximum number of characters to print
- For floats: digits after decimal (not implemented for simplicity)

**4. Width & Precision Parsing:**
- Supports literal numbers: `%10d`, `%.5s`
- Supports dynamic via `*`: `%*d`, `%.*s`, `%*.*d`
- Negative width triggers implicit left-align

**5. Modular Architecture:**
```
ft_printf.c          → Entry point, main dispatcher
parsing.c            → Format string tokenization
conversions_*.c      → Individual conversion handlers
flags_utils.c        → Flag processing and application
print_utils.c        → Output formatting and writing
utils.c              → Helper functions
```

### Handling Edge Cases

- **INT_MAX/INT_MIN:** Proper sign handling with flags
- **UINT_MAX:** Correct conversion without overflow
- **NULL pointers:** Display "(nil)" or format address
- **Empty strings:** Handle gracefully
- **Conflicting flags:** Apply correct precedence
- **Percent signs:** `%%` produces single `%`
- **Multiple specifiers:** Process left-to-right with variadic args

---

## Resources

### C Standard References
- [C99 Standard - printf specification](https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html)
- [man 3 printf - Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [format specification reference](https://cplusplus.com/reference/cstdio/printf/)

### Learning Materials
- "The C Programming Language" (Kernighan & Ritchie) - Chapters on I/O and variadic functions
- [Variadic Functions in C](https://en.wikipedia.org/wiki/Variadic_function)
- [Format String Vulnerability](https://owasp.org/www-community/attacks/Format_string_attack) - Understanding format strings for security

### 42 School Resources
- 42 Intra project specification: ft_printf
- Norm documentation: https://github.com/42School/norminette

---

## AI Usage

### Where AI Was Used

**AI assistance was utilized for:**

1. **Test Suite Development** (40% of project time)
   - Generated comprehensive test cases covering all format specifiers
   - Created edge case scenarios (INT_MAX, INT_MIN, UINT_MAX, negative width, precision edge cases)
   - Built test framework infrastructure with organized test grouping
   - Generated 548 total test cases with multiple test groups per specifier

2. **Code Organization & Best Practices** (10% of project time)
   - Suggested modular file structure (separating by conversion type)
   - Recommended clear flag handling approach with dedicated struct fields
   - Provided naming conventions and code organization patterns

3. **Documentation** (5% of project time)
   - Generated this README following 42 requirements
   - Created make help target documentation
   - Provided algorithm explanation template and structure

### Tasks Completed Independently

**Core implementation (85% of project):**
- Format string parser implementation
- All conversion handlers (c, s, p, d, i, u, x, X, %, o, b)
- Flag parsing and application logic
- Precision and width calculation algorithms
- Dynamic width/precision parsing with * flag
- Edge cases with zero values and special formatting
- Memory management and output buffering
- Return value tracking and accuracy

**Quality Assurance:**
- Manual testing against standard printf
- Edge case identification and handling
- Flag precedence implementation
- Performance optimization

---

## Compilation & Build Info

- **Compiler:** gcc (with -Wall -Wextra -Werror)
- **C Standard:** C99
- **Library Type:** Static archive (.a)
- **Dependencies:** Only standard C library (unistd.h, stdarg.h, limits.h, stdbool.h)
- **Code Size:** 716 lines of implementation code

## Testing

The project includes a comprehensive automated test suite:

```bash
make test           # Run all 548 tests
make test-mandatory # Run 380 mandatory tests
make test-bonus     # Run 168 bonus/edge case tests
make help           # Show available commands
```

All tests verify:
- ✅ Output content matches standard printf exactly
- ✅ Return values (byte count) match standard printf
- ✅ Flag interactions and precedence
- ✅ Edge cases and boundary values
- ✅ Dynamic width/precision with * flag

---

## Contact & Support

For questions or issues related to this implementation, refer to the 42 Intra platform or contact the project author through the 42 School network.
