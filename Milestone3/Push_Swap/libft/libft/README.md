*This activity has been created as part of the 42 curriculum by hal-omar.*
 
# libft
 
## Description
 
**libft** is a personal implementation of a C standard library, recreated from scratch as part of the 42 curriculum. The goal of this project is to get comfortable with the C programming language by re-implementing common libc functions, while also building a personal toolbox of helper functions (string manipulation, memory management, and linked lists) that will be reused in later 42 projects.
 
The library is split into three mandatory parts:
- **Part 1 – Libc functions**: re-implementations of standard C library functions (`ft_strlen`, `ft_memcpy`, `ft_atoi`, etc.).
- **Part 2 – Additional functions**: original utility functions not part of the standard C library, mainly for string processing (`ft_split`, `ft_itoa`, `ft_strtrim`, etc.).
- **Part 3 – Linked list functions**: a set of functions to create and manipulate singly linked lists (`t_list`), used to manage dynamic, chained data structures.
## Instructions
 
### Compilation
 
The project is compiled using the provided `Makefile`, which follows the standard rules required at 42:
 
| Rule | Description |
|------|-------------|
| `make` / `make all` | Compiles all source files and generates the `libft.a` static library |
| `make clean` | Removes the object files (`.o`) |
| `make fclean` | Removes the object files and the `libft.a` library |
| `make re` | Re-compiles the library from scratch (`fclean` + `all`) |
 
Compilation is done with `cc` and the flags `-Wall -Wextra -Werror`, and the archive is built with `ar rcs`.
 
### Usage
 
To use the library in your own project:
 
1. Copy the `libft` folder into your project (or add it as a submodule).
2. Compile the library:
```bash
   make -C libft
```
3. Include the header in your source files:
```c
   #include "libft.h"
```
4. Compile your project by linking against the library:
```bash
   cc your_files.c -Llibft -lft -o your_program
```
 
## Resources
 
- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) — reference book for C fundamentals.
- [man7.org — Linux man-pages](https://man7.org/linux/man-pages/) — used to check the exact behavior/prototype of the original libc functions being reimplemented (`memcpy`, `strlcpy`, `atoi`, etc.).
- [42 Norm](https://github.com/42School/norminette) — coding style standard enforced on all functions.
**AI usage**: AI assistance was used to help review the coherence and completeness of function implementations against their libc reference behavior. No AI-generated code was used for the function implementations themselves.
 
## Library description
 
| Category | Functions |
|----------|-----------|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Conversion / allocation | `ft_atoi`, `ft_calloc`, `ft_strdup` |
| Additional string functions | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri` |
| File-descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| Part 3 – Linked lists (`t_list`) | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |
 
