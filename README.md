# 42 Common Core



![Language: C](https://img.shields.io/badge/language-C-00599C?logo=c&logoColor=white)




![Norminette](https://img.shields.io/badge/norminette-passing-success)



![License: MIT](https://img.shields.io/badge/license-MIT-blue)

(LICENSE)

My projects from the **Common Core** curriculum at [42](https://42.fr), written in C.

Every project follows the 42 rules: code must pass the [Norm](https://github.com/42School/norminette) (strict style: max 25 lines per function, max 5 functions per file, no `for` loops…), compile with `-Wall -Wextra -Werror`, have no memory leaks, and use only the functions allowed by the subject.

## Projects

| Milestone | Projects | Status |
|:---------:|----------|:------:|
| 1 | [**libft**](milestone_1/libft): my own C library: libc functions (`strlen`, `memcpy`, `atoi`…), string helpers (`split`, `itoa`…) and linked lists | ✅ |
| 2 | [**ft_printf**](milestone_2/ft_printf): a re-implementation of `printf` using variadic arguments<br>[**get_next_line**](milestone_2/get_next_line): reads a file descriptor one line at a time using a `static` buffer | ✅ |
| 3 | [**push_swap**](milestone_3/push_swap): sorts numbers using two stacks and a limited set of operations | 🚧 In progress |

Each project has its own README explaining how it works and how to use it.

## Repository structure

```
42_common_core/
├── milestone_1/
│   └── libft/
├── milestone_2/
│   ├── ft_printf/
│   └── get_next_line/
└── milestone_3/
    └── push_swap/
```

Each project folder is self-contained, with its own `Makefile`, sources, header and README. Test programs live in a `tests/` folder inside each project and are not part of the build.

## Build and test

```sh
git clone https://github.com/Huthifa-Alomari/42_common_core.git
cd 42_common_core/milestone_1/libft
make
```

Every `Makefile` has the standard rules: `make`, `make clean`, `make fclean` and `make re`.

To check the Norm yourself:

```sh
pip install norminette
norminette milestone_1/libft/*.[ch] milestone_2/*/*.[ch]
```

## License

This repository is released under the [MIT License](LICENSE).

## Author

**Huthifa Alomari** (`hal-omar`), student at 42.

> If you are a 42 student: feel free to read the code to learn, but write your own. Copying will not help you in the evaluations or the exams.
