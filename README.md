# 42 Common Core

My projects from the 42 Common Core curriculum.

| Milestone | Project | Description | Status |
|-----------|---------|-------------|--------|
| 1 | [libft](milestone_1/libft) | My own C library: libc functions, string helpers, linked lists | ✅ Done |
| 2 | [ft_printf](milestone_2/ft_printf) | Recreation of `printf` (`%c %s %p %d %i %u %x %X %%`) | ✅ Done |
| 2 | [get_next_line](milestone_2/get_next_line) | Read a file descriptor one line at a time | ✅ Done |
| 3 | [push_swap](milestone_3/push_swap) | Sort a stack of integers with a limited set of operations | 🚧 In progress |

## Structure

Each project folder is self-contained and can be copied as-is into its
submission repository. Test files live in a `tests/` folder inside each project.

```
milestone_N/<project>/
├── Makefile
├── *.c / *.h
├── README.md
└── tests/
```

## Build

```sh
cd milestone_1/libft && make
```
