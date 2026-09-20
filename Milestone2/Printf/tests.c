/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 22:13:15 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/19 23:49:51 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

// Variadic function to print given arguments
void print(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)
        printf("%d ", va_arg(args, int));
    printf("\n");
    va_end(args);
}
/*int main() {

  	// Calling function print() with different number
  	// of arguments
    print(3, 1, 2, 3);
    print(5, 1, 2, 3, 4, 5);

#include <stdio.h>*/
#include <limits.h>

/* Each line: inner printf prints the value between |...|,
** outer printf then prints its return value. */

int	main(void)
{
	int		x = 42;
	void	*ptr = &x;
	void	*null_ptr = NULL;
	char	*null_str = NULL;

	/* ---------- %c ---------- */
	printf(" -> %d\n", printf("|%c|", 'A'));
	printf(" -> %d\n", printf("|%c|", '0'));
	printf(" -> %d\n", printf("|%c|", 0));
	printf(" -> %d\n", printf("|%c%c%c|", '4', '2', '!'));
	printf(" -> %d\n", printf("|%c|", 255));

	/* ---------- %s ---------- */
	printf(" -> %d\n", printf("|%s|", "hello"));
	printf(" -> %d\n", printf("|%s|", ""));
	printf(" -> %d\n", printf("|%s|", null_str));
	printf(" -> %d\n", printf("|%s %s|", "hello", "world"));

	/* ---------- %p ---------- */
	printf(" -> %d\n", printf("|%p|", (void *)0x1));
	printf(" -> %d\n", printf("|%p|", ptr));
	printf(" -> %d\n", printf("|%p|", (void *)ULONG_MAX));
	printf(" -> %d\n", printf("|%p|", null_ptr));
	printf(" -> %d\n", printf("|%p %p|", ptr, null_ptr));

	/* ---------- %d ---------- */
	printf(" -> %d\n", printf("|%d|", 0));
	printf(" -> %d\n", printf("|%d|", 42));
	printf(" -> %d\n", printf("|%d|", -42));
	printf(" -> %d\n", printf("|%d|", INT_MAX));
	printf(" -> %d\n", printf("|%d|", INT_MIN));

	/* ---------- %i ---------- */
	printf(" -> %d\n", printf("|%i|", 0));
	printf(" -> %d\n", printf("|%i|", -1));
	printf(" -> %d\n", printf("|%i|", INT_MAX));
	printf(" -> %d\n", printf("|%i|", INT_MIN));

	/* ---------- %u ---------- */
	printf(" -> %d\n", printf("|%u|", 0));
	printf(" -> %d\n", printf("|%u|", 42));
	printf(" -> %d\n", printf("|%u|", UINT_MAX));
	printf(" -> %d\n", printf("|%u|", (unsigned int)-1));
	printf(" -> %d\n", printf("|%u|", (unsigned int)INT_MIN));

	/* ---------- %x ---------- */
	printf(" -> %d\n", printf("|%x|", 0));
	printf(" -> %d\n", printf("|%x|", 255));
	printf(" -> %d\n", printf("|%x|", 0xdeadbeef));
	printf(" -> %d\n", printf("|%x|", UINT_MAX));
	printf(" -> %d\n", printf("|%x|", (unsigned int)INT_MIN));

	/* ---------- %X ---------- */
	printf(" -> %d\n", printf("|%X|", 0));
	printf(" -> %d\n", printf("|%X|", 255));
	printf(" -> %d\n", printf("|%X|", 0xdeadbeef));
	printf(" -> %d\n", printf("|%X|", UINT_MAX));
	printf(" -> %d\n", printf("|%X|", (unsigned int)INT_MIN));

	/* ---------- %% ---------- */
	printf(" -> %d\n", printf("|%%|"));
	printf(" -> %d\n", printf("|100%%|"));
	printf(" -> %d\n", printf("|%%%%|"));
	printf(" -> %d\n", printf("|%%c|"));

	/* ---------- mixed ---------- */
	printf(" -> %d\n", printf("|%d%%%s%c|", 5, "ok", '!'));
	printf(" -> %d\n", printf("|%d|%s|", INT_MIN, null_str));
	printf(" -> %d\n", printf("|no specifiers|"));
	printf(" -> %d\n", printf("|%c%s%p%d%i%u%x%X%%|",
			'a', "b", ptr, 1, -2, 3u, 255, 255));
	printf(" -> %d\n", printf(""));
    return 0;
}
