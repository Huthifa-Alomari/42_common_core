*This activity has been created as part of the 42 curriculum by hal-omar.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library's `printf` function. The goal is to learn how **variadic functions** work in C (`va_start`, `va_arg`, `va_end`) and how to turn different data types into text written to standard output.

The result is a static library, `libftprintf.a`, that can be linked into any C project.

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, just like the real `printf`.

### Supported conversions

| Conversion | Prints |
|------------|--------|
| `%c` | A single character |
| `%s` | A string (`(null)` if the pointer is `NULL`) |
| `%p` | A pointer address in hexadecimal, prefixed with `0x` (`(nil)` if `NULL`) |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` / `%X` | An unsigned integer in lowercase / uppercase hexadecimal |
| `%%` | A literal percent sign |

## Instructions

### Compilation

```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # rebuilds everything
```

Everything is compiled with `cc -Wall -Wextra -Werror`.

### Usage

```c
#include "ft_printf.h"

int main(void)
{
	int	n;

	n = ft_printf("Hello %s, you are %d years old (%x in hex)\n", "Ali", 21, 21);
	ft_printf("That line was %d characters long\n", n);
	return (0);
}
```

```sh
cc main.c libftprintf.a -o demo && ./demo
```

### Tests

`tests/test.c` compares the output and return value of `ft_printf` against the real `printf` for every conversion, including edge cases (`INT_MIN`, `UINT_MAX`, `NULL` strings and pointers, trailing `%`):

```sh
make && cc tests/test.c libftprintf.a -o test && ./test
```

The test file intentionally uses unusual format strings, so compile it without `-Werror`.

## Algorithm and structure

`ft_printf` walks through the format string one character at a time:

1. A normal character is written directly with `write`.
2. When it finds `%`, it looks at the next character (the *specifier*) and hands it to `ft_format`.
3. `ft_format` pulls the next argument from the `va_list` with the right type and sends it to a small helper that prints it and returns how many characters it wrote.
4. Every helper's return value is added to a running total, which `ft_printf` returns at the end.

| File | Role |
|------|------|
| `ft_printf.c` | Main loop over the format string |
| `ft_format.c` | Dispatches each specifier to the right helper |
| `ft_putchar.c`, `ft_putstr.c` | Characters and strings |
| `ft_putnbr.c`, `ft_putunsigned.c` | Signed and unsigned decimal numbers (recursive) |
| `ft_puthex.c` | Hexadecimal, lowercase or uppercase |
| `ft_putptr.c` | Pointer addresses (`unsigned long` in hex with `0x` prefix) |

Numbers are printed **recursively**: the function prints `n / base` first, then the last digit `n % base`. This prints digits in the right order without needing a buffer. `ft_putnbr` converts to `long` before negating, so `INT_MIN` is handled without overflow.

## Resources

- `man 3 printf` and `man 3 stdarg` — expected behavior and variadic argument macros.
- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic) — how `va_list` works.
- [42 Norm](https://github.com/42School/norminette) — coding style standard.

### AI usage

The implementation was written by me. After the project was evaluated, Claude (Anthropic) was used to fix Norm formatting issues in the header files, compare the output against the real `printf`, and help write this README.
