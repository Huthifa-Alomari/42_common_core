*This activity has been created as part of the 42 curriculum by hal-omar.*

# get_next_line

## Description

`get_next_line` is a function that reads a file descriptor one line at a time, returning each line — including its trailing `\n` when one exists — on successive calls, without ever re-reading data already consumed.

The core difficulty the project is built around: `read()` only ever hands you raw bytes in fixed-size chunks (`BUFFER_SIZE`), with no concept of "lines." A single chunk can contain zero, one, or several line breaks, and a single line can span several chunks. The function has to buffer whatever's left over after each call and remember it for the next one — which is why the project doubles as an introduction to `static` variables: they're the only way to preserve state between calls without a global variable (forbidden by the subject) or changing the fixed `char *get_next_line(int fd)` prototype.

```
char *get_next_line(int fd);
```

- **Parameter:** `fd` — the file descriptor to read from.
- **Return value:** the next line (including `\n` if present), or `NULL` if there's nothing left to read or an error occurred.

## Instructions

### Compilation

The project has no standalone binary target — it's compiled directly into whatever `.c` file uses it:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```

`BUFFER_SIZE` can be overridden to any value (it also compiles and runs correctly **without** the `-D` flag, falling back to a default of `42`).

### Usage

```c
#include "get_next_line.h"

int main(void)
{
    int   fd;
    char *line;

    fd = open("some_file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Works identically whether `fd` points to a regular file, standard input, or a pipe.

### Tests

`tests/main.c` prints every line of `tests/text.txt`. Run it from the `tests/` folder, ideally with different buffer sizes and under Valgrind:

```sh
cd tests
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 ../get_next_line.c ../get_next_line_utils.c main.c
valgrind --leak-check=full ./a.out
```

### Known limitation

A single `static char *stash` is shared across every call. Reading two different file descriptors in an interleaved loop (`get_next_line(fd1)`, `get_next_line(fd2)`, `get_next_line(fd1)` again) will corrupt state between them — this is an accepted limitation of the mandatory part, addressed in the bonus part (not implemented here) by keeping one stash per fd.

## Technical choices — algorithm justification

The implementation keeps **one accumulated string per read stream** (the "stash") rather than a linked list of raw read-chunks. Each call does three things, in order:

1. **`fill_stash`** — reads into the stash, one `BUFFER_SIZE` chunk at a time, stopping as soon as the stash contains a `\n`, or as soon as `read()` returns `0` (EOF) or `-1` (error). This is the only step that touches the kernel; everything after it is pure string manipulation.
2. **`extract_line`** — copies out everything from the start of the stash up to and including the first `\n` (or the whole stash, if `read()` hit EOF before finding one).
3. **`update_stash`** — copies out whatever remains *after* that `\n` into a fresh block, frees the old stash, and stores the fresh block as the new stash for the next call — or stores `NULL` if there was no `\n` at all, signalling the stream is exhausted.

**Why a flat string instead of a list of chunks:** a linked list of raw `BUFFER_SIZE`-sized nodes was an earlier design considered for this project. It worked, but required re-walking the whole chain on every call just to check for a `\n`, to measure a line's length, and to copy it out — three full traversals per line, plus a struct and four extra list-management functions. Collapsing that into a single `char *` cuts the allocations and traversals roughly in half and removes an entire data structure the subject doesn't otherwise require. The tradeoff is that `gnl_strjoin` reallocates the whole accumulated string on every `read()` call, which is O(n²) over a single very long line — an acceptable cost for a school project's scale, and the same tradeoff most straightforward `get_next_line` implementations make.

**Correctness invariant relied on throughout:** whenever `fill_stash`'s loop exits *because a `\n` was found* (not because of EOF), that `\n` is guaranteed to be inside the most recently read chunk — the loop is checked immediately after each `read()`, so it can never read past the first line boundary it encounters.

## Resources

- `man 2 read`, `man 2 open` — syscall semantics, short reads, return value meanings.
- *CS:APP* (Bryant & O'Hallaron), ch. 10 — buffered I/O, the same tradeoffs this project's stash design is built around.
- 42's own "static variable" documentation, linked from the subject PDF.

### AI usage disclosure

Claude (Anthropic) was used throughout development as a Socratic tutor, not as a code generator:

- **Design guidance:** proposed the single-stash architecture (vs. an initial linked-list design I had written myself) and explained the tradeoffs, without providing a working implementation to copy.
- **Debugging:** identified specific bugs I introduced myself while implementing the design — a `NULL`-dereference crash in `gnl_strjoin` on the first-ever call, the same class of bug in `fill_stash`'s loop condition, and a Norm line-count violation in `gnl_strjoin` — by asking me to trace the logic rather than supplying fixes directly. I wrote the actual fixes.
- **Skeleton with gaps:** for `get_next_line.c`, was given a function skeleton with the control-flow structure but with 3 specific pieces of logic (a loop condition and two pointer-arithmetic expressions) deliberately left as comments for me to write myself.
- **Verification:** compiled and ran my code under `-fsanitize=address,leak` across multiple `BUFFER_SIZE` values, an empty file, invalid/closed file descriptors, stdin via a pipe, and a directory fd, reporting results back to me rather than pre-emptively "fixing" anything that passed.
- **Explanation/defense prep:** traced execution call-by-call against a test file (byte offsets, heap block contents, syscall behavior) after I asked, and was pushed for a full set of interview-style questions covering every code path, to prepare for peer evaluation.

No AI-generated code from this process was pasted directly into the submitted files without being written or fixed by me first.

**After evaluation (public version):** Claude reviewed the code again before this repository was made public and fixed three edge cases directly:

- When a file ended with `\n`, the call after the last line returned an empty string `""` instead of `NULL`. `update_stash` now frees the stash when nothing is left after the newline.
- A `read()` error in the middle of a file (`-1`) now frees the stash and returns `NULL`, instead of returning the old buffered data.
- If `malloc` fails inside `gnl_strjoin` or `fill_stash`, the existing stash is now freed instead of leaked.
