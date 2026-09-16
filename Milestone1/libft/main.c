/* test_main.c - comprehensive libft tester
 *
 * Compile (from the libft folder, after `make`):
 *   cc -Wall -Wextra -Werror test_main.c libft.a -o test_libft
 * Run:
 *   ./test_libft
 *
 * Every single check prints BOTH your result ("got") and the
 * reference result ("expected"), so you can see exactly what
 * mismatched. A [OK]/[KO] tag is printed for each one, and a
 * total score at the end.
 */

#define _GNU_SOURCE
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static int	g_total = 0;
static int	g_passed = 0;

/* ---------- generic "got vs expected" printers ---------- */

static void	check_int(const char *label, long long got, long long expected)
{
	int	ok;

	ok = (got == expected);
	g_total++;
	g_passed += ok;
	printf("[%s] %-32s got=%lld  expected=%lld\n",
		ok ? "OK" : "KO", label, got, expected);
}

static void	check_size(const char *label, size_t got, size_t expected)
{
	int	ok;

	ok = (got == expected);
	g_total++;
	g_passed += ok;
	printf("[%s] %-32s got=%zu  expected=%zu\n",
		ok ? "OK" : "KO", label, got, expected);
}

static void	check_char(const char *label, int got, int expected)
{
	int	ok;

	ok = (got == expected);
	g_total++;
	g_passed += ok;
	printf("[%s] %-32s got='%c'(%d)  expected='%c'(%d)\n",
		ok ? "OK" : "KO", label, (char)got, got, (char)expected, expected);
}

/* compares only the SIGN of got vs a libc reference value: this is
 * the only correct way to test memcmp/strncmp, since the exact
 * magnitude returned is implementation-defined. Both raw numbers
 * are still printed so you can see the actual values. */
static void	check_sign(const char *label, int got, int libc_ref)
{
	int	gs;
	int	rs;
	int	ok;

	gs = (got > 0) - (got < 0);
	rs = (libc_ref > 0) - (libc_ref < 0);
	ok = (gs == rs);
	g_total++;
	g_passed += ok;
	printf("[%s] %-32s got=%d(sign %d)  libc=%d(sign %d)\n",
		ok ? "OK" : "KO", label, got, gs, libc_ref, rs);
}

static void	check_str(const char *label, char *got, const char *expected)
{
	int	ok;

	if (got == NULL && expected == NULL)
		ok = 1;
	else if (got == NULL || expected == NULL)
		ok = 0;
	else
		ok = (strcmp(got, expected) == 0);
	g_total++;
	g_passed += ok;
	printf("[%s] %-32s got=\"%s\"  expected=\"%s\"\n",
		ok ? "OK" : "KO", label,
		got ? got : "(null)", expected ? expected : "(null)");
}

static void	check_ptr_null(const char *label, void *got, int expect_null)
{
	int	ok;

	ok = expect_null ? (got == NULL) : (got != NULL);
	g_total++;
	g_passed += ok;
	printf("[%s] %-32s got=%s  expected=%s\n",
		ok ? "OK" : "KO", label,
		got ? "non-NULL" : "NULL", expect_null ? "NULL" : "non-NULL");
}

/* renders raw bytes as space separated hex, for comparing buffers
 * produced by memset/bzero/calloc etc. */
static char	*bytes_to_str(void *buf, size_t n, char *out, size_t outsize)
{
	unsigned char	*b;
	size_t			i;
	size_t			pos;

	b = (unsigned char *)buf;
	i = 0;
	pos = 0;
	out[0] = '\0';
	while (i < n && pos + 3 < outsize)
	{
		pos += (size_t)snprintf(out + pos, outsize - pos, "%02X ", b[i]);
		i++;
	}
	return (out);
}

/* ---------- Part 1: libc functions ---------- */

static void	test_ctype(void)
{
	printf("\n=== Character classification ===\n");
	check_int("ft_isalpha('a')", ft_isalpha('a'), 1);
	check_int("ft_isalpha('9')", ft_isalpha('9'), 0);
	check_int("ft_isdigit('5')", ft_isdigit('5'), 1);
	check_int("ft_isdigit('a')", ft_isdigit('a'), 0);
	check_int("ft_isalnum('z')", ft_isalnum('z'), 1);
	check_int("ft_isalnum('%')", ft_isalnum('%'), 0);
	check_int("ft_isascii(65)", ft_isascii(65), 1);
	check_int("ft_isascii(200)", ft_isascii(200), 0);
	check_int("ft_isprint('A')", ft_isprint('A'), 1);
	check_int("ft_isprint('\\n')", ft_isprint('\n'), 0);
	check_char("ft_toupper('a')", ft_toupper('a'), 'A');
	check_char("ft_toupper('A')", ft_toupper('A'), 'A');
	check_char("ft_tolower('A')", ft_tolower('A'), 'a');
	check_char("ft_tolower('a')", ft_tolower('a'), 'a');
}

static void	test_strlen(void)
{
	printf("\n=== ft_strlen ===\n");
	check_size("empty string", ft_strlen(""), strlen(""));
	check_size("\"Hello World\"", ft_strlen("Hello World"),
		strlen("Hello World"));
}

static void	test_mem(void)
{
	char	ref[10];
	char	got[10];
	char	gotbuf[64];
	char	refbuf[64];

	printf("\n=== Memory functions ===\n");

	memset(ref, 'x', 10);
	ft_memset(got, 'x', 10);
	check_str("ft_memset",
		bytes_to_str(got, 10, gotbuf, sizeof(gotbuf)),
		bytes_to_str(ref, 10, refbuf, sizeof(refbuf)));

	memset(ref, 'z', 10);
	memset(got, 'z', 10);
	bzero(ref + 2, 4);
	ft_bzero(got + 2, 4);
	check_str("ft_bzero",
		bytes_to_str(got, 10, gotbuf, sizeof(gotbuf)),
		bytes_to_str(ref, 10, refbuf, sizeof(refbuf)));

	{
		char	src[] = "42School";
		char	dst[10];

		memset(dst, 0, 10);
		ft_memcpy(dst, src, 9);
		check_str("ft_memcpy", dst, "42School");
	}
	{
		char	m1[] = "123456789";
		char	m2[] = "123456789";

		memmove(m1 + 2, m1, 5);
		ft_memmove(m2 + 2, m2, 5);
		check_str("ft_memmove (overlap)", m2, m1);
	}
	{
		void	*g;
		void	*r;

		g = ft_memchr("hello", 'l', 5);
		r = memchr("hello", 'l', 5);
		check_str("ft_memchr found",
			g ? (char *)g : "(null)", r ? (char *)r : "(null)");
	}
	check_ptr_null("ft_memchr not found", ft_memchr("hello", 'z', 5), 1);

	check_sign("ft_memcmp equal", ft_memcmp("abc", "abc", 3),
		memcmp("abc", "abc", 3));
	check_sign("ft_memcmp diff", ft_memcmp("abd", "abc", 3),
		memcmp("abd", "abc", 3));
}

static void	test_str(void)
{
	printf("\n=== String functions ===\n");

	{
		char	*g;
		char	*r;

		g = ft_strchr("Hello", 'e');
		r = strchr("Hello", 'e');
		check_str("ft_strchr found", g ? g : "(null)", r ? r : "(null)");
	}
	check_ptr_null("ft_strchr('\\0') not NULL", ft_strchr("Hello", '\0'), 0);
	check_ptr_null("ft_strchr not found", ft_strchr("Hello", 'z'), 1);

	{
		char	*g;
		char	*r;

		g = ft_strrchr("Hello", 'l');
		r = strrchr("Hello", 'l');
		check_str("ft_strrchr found", g ? g : "(null)", r ? r : "(null)");
	}
	check_ptr_null("ft_strrchr not found", ft_strrchr("Hello", 'z'), 1);

	check_sign("ft_strncmp equal", ft_strncmp("Hello", "Hello", 5),
		strncmp("Hello", "Hello", 5));
	check_sign("ft_strncmp diff", ft_strncmp("Hello", "World", 5),
		strncmp("Hello", "World", 5));
	check_int("ft_strncmp n=0", ft_strncmp("abc", "xyz", 0), 0);

	{
		char	d1[20];
		char	d2[20];
		size_t	r1;
		size_t	r2;

		memset(d1, 0, 20);
		memset(d2, 0, 20);
		r1 = strlcpy(d1, "Hello, World!", 6);
		r2 = ft_strlcpy(d2, "Hello, World!", 6);
		check_str("ft_strlcpy content", d2, d1);
		check_size("ft_strlcpy return", r2, r1);
	}
	{
		char	d1[10] = "Hi ";
		char	d2[10] = "Hi ";
		size_t	r1;
		size_t	r2;

		r1 = strlcat(d1, "there!!", sizeof(d1));
		r2 = ft_strlcat(d2, "there!!", sizeof(d2));
		check_str("ft_strlcat content", d2, d1);
		check_size("ft_strlcat return", r2, r1);
	}
	check_str("ft_strnstr found",
		ft_strnstr("hello world", "world", 11), "world");
	check_ptr_null("ft_strnstr not found",
		ft_strnstr("hello world", "xyz", 11), 1);
	check_str("ft_strnstr empty needle",
		ft_strnstr("hello", "", 5), "hello");
	check_str("ft_strnstr len limits search",
		ft_strnstr("hello world", "world", 7), NULL);

	check_int("ft_atoi positive", ft_atoi("42"), 42);
	check_int("ft_atoi negative", ft_atoi("-42"), -42);
	check_int("ft_atoi spaces", ft_atoi("   123"), 123);
	check_int("ft_atoi sign+digits", ft_atoi("+123abc"), 123);
}

static void	test_alloc(void)
{
	int		*cal;
	char	*dup;

	printf("\n=== calloc / strdup ===\n");

	cal = ft_calloc(5, sizeof(int));
	check_ptr_null("ft_calloc not NULL", cal, 0);
	if (cal)
	{
		int		zero[5];
		char	gotbuf[64];
		char	expbuf[64];

		memset(zero, 0, sizeof(zero));
		check_str("ft_calloc zeroed",
			bytes_to_str(cal, sizeof(zero), gotbuf, sizeof(gotbuf)),
			bytes_to_str(zero, sizeof(zero), expbuf, sizeof(expbuf)));
		free(cal);
	}
	cal = ft_calloc(0, 10);
	check_ptr_null("ft_calloc(0, n) not NULL", cal, 0);
	free(cal);

	dup = ft_strdup("42School");
	check_str("ft_strdup", dup, "42School");
	free(dup);
}

/* ---------- Part 2: additional functions ---------- */

static void	test_substr(void)
{
	char	*s;

	printf("\n=== ft_substr ===\n");
	s = ft_substr("Hello, World!", 7, 5);
	check_str("basic", s, "World");
	free(s);
	s = ft_substr("Hello", 0, 100);
	check_str("len > strlen", s, "Hello");
	free(s);
	s = ft_substr("Hello", 10, 5);
	check_str("start > strlen", s, "");
	free(s);
}

static void	test_strjoin(void)
{
	char	*s;

	printf("\n=== ft_strjoin ===\n");
	s = ft_strjoin("Hello, ", "World!");
	check_str("basic", s, "Hello, World!");
	free(s);
	s = ft_strjoin("", "World!");
	check_str("empty s1", s, "World!");
	free(s);
}

static void	test_strtrim(void)
{
	char	*s;

	printf("\n=== ft_strtrim ===\n");
	s = ft_strtrim("   Hello, World!   ", " ");
	check_str("basic", s, "Hello, World!");
	free(s);
	s = ft_strtrim("xxHelloxx", "x");
	check_str("custom set", s, "Hello");
	free(s);
	s = ft_strtrim("xxxx", "x");
	check_str("all trimmed", s, "");
	free(s);
}

static void	test_split(void)
{
	char	**arr;
	size_t	i;

	printf("\n=== ft_split ===\n");
	arr = ft_split("Hello, World, 42!", ',');
	check_ptr_null("ft_split not NULL", arr, 0);
	if (arr)
	{
		check_str("word 0", arr[0], "Hello");
		check_str("word 1", arr[1], " World");
		check_str("word 2", arr[2], " 42!");
		check_ptr_null("NULL terminated", arr[3], 1);
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	arr = ft_split(",,a,,b,,", ',');
	check_ptr_null("skip-empty split not NULL", arr, 0);
	if (arr)
	{
		check_str("skip empty 0", arr[0], "a");
		check_str("skip empty 1", arr[1], "b");
		check_ptr_null("skip empty terminated", arr[2], 1);
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

static void	test_itoa(void)
{
	char	*s;

	printf("\n=== ft_itoa ===\n");
	s = ft_itoa(42);
	check_str("positive", s, "42");
	free(s);
	s = ft_itoa(-42);
	check_str("negative", s, "-42");
	free(s);
	s = ft_itoa(0);
	check_str("zero", s, "0");
	free(s);
	s = ft_itoa(-2147483648);
	check_str("INT_MIN", s, "-2147483648");
	free(s);
	s = ft_itoa(2147483647);
	check_str("INT_MAX", s, "2147483647");
	free(s);
}

static char	rot_char(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return ('a' + (c - 'a' + 1) % 26);
	return (c);
}

static void	test_strmapi(void)
{
	char	*s;

	printf("\n=== ft_strmapi ===\n");
	s = ft_strmapi("abz", rot_char);
	check_str("rot1", s, "bca");
	free(s);
	s = ft_strmapi("", rot_char);
	check_str("empty", s, "");
	free(s);
}

static void	upper_at(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
}

static void	test_striteri(void)
{
	char	s[] = "hello world";

	printf("\n=== ft_striteri ===\n");
	ft_striteri(s, upper_at);
	check_str("uppercase even idx", s, "HeLlO WoRlD");
}

static void	test_put_fd(void)
{
	printf("\n=== put*_fd (visual check, not scored) ===\n");
	printf("ft_putchar_fd expected 'X'      -> got: ");
	ft_putchar_fd('X', 1);
	printf("\n");
	printf("ft_putstr_fd  expected \"Hello!\" -> got: ");
	ft_putstr_fd("Hello!", 1);
	printf("\n");
	printf("ft_putendl_fd expected \"Hi\\n\"   -> got: ");
	ft_putendl_fd("Hi", 1);
	printf("ft_putnbr_fd  expected -42        -> got: ");
	ft_putnbr_fd(-42, 1);
	printf("\n");
	printf("ft_putnbr_fd  expected -2147483648-> got: ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
}

/* ---------- Part 3: linked list ---------- */

static void	del_int(void *content)
{
	free(content);
}

static void	*dup_int_times2(void *content)
{
	int	*n;
	int	*res;

	n = (int *)content;
	res = malloc(sizeof(int));
	if (res)
		*res = (*n) * 2;
	return (res);
}

static void	print_int(void *content)
{
	printf("%d ", *(int *)content);
}

static int	*make_int(int v)
{
	int	*p;

	p = malloc(sizeof(int));
	*p = v;
	return (p);
}

static void	test_list(void)
{
	t_list	*lst;
	t_list	*node;
	t_list	*mapped;

	printf("\n=== Linked list functions ===\n");

	lst = ft_lstnew(make_int(1));
	check_int("ft_lstnew content", *(int *)lst->content, 1);
	check_ptr_null("ft_lstnew next is NULL", lst->next, 1);

	node = ft_lstnew(make_int(2));
	ft_lstadd_back(&lst, node);
	node = ft_lstnew(make_int(3));
	ft_lstadd_back(&lst, node);
	check_int("size after add_back", (long long)ft_lstsize(lst), 3);
	check_int("order[0]", *(int *)lst->content, 1);
	check_int("order[1]", *(int *)lst->next->content, 2);
	check_int("order[2]", *(int *)lst->next->next->content, 3);

	node = ft_lstnew(make_int(0));
	ft_lstadd_front(&lst, node);
	check_int("ft_lstadd_front content", *(int *)lst->content, 0);
	check_int("size after add_front", (long long)ft_lstsize(lst), 4);

	check_int("ft_lstlast content", *(int *)ft_lstlast(lst)->content, 3);

	printf("ft_lstiter  expected \"0 1 2 3\" -> got: ");
	ft_lstiter(lst, print_int);
	printf("\n");

	mapped = ft_lstmap(lst, dup_int_times2, del_int);
	check_ptr_null("ft_lstmap not NULL", mapped, 0);
	if (mapped)
	{
		printf("ft_lstmap   expected \"0 2 4 6\" -> got: ");
		ft_lstiter(mapped, print_int);
		printf("\n");
		check_int("ft_lstmap first value", *(int *)mapped->content, 0);
		check_int("ft_lstmap last value",
			*(int *)ft_lstlast(mapped)->content, 6);
		ft_lstclear(&mapped, del_int);
		check_ptr_null("ft_lstclear sets NULL", mapped, 1);
	}
	ft_lstclear(&lst, del_int);
	check_ptr_null("ft_lstclear (original) sets NULL", lst, 1);
}

int	main(void)
{
	setbuf(stdout, NULL);
	test_ctype();
	test_strlen();
	test_mem();
	test_str();
	test_alloc();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_put_fd();
	test_list();

	printf("\n========================================\n");
	printf("RESULT: %d / %d tests passed\n", g_passed, g_total);
	printf("========================================\n");
	return (g_passed != g_total);
}