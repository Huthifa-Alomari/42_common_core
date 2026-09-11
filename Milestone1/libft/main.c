/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 20:31:10 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/10 13:59:40 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("--- ft_isalpha ---\n");
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('9'));

	printf("--- ft_isdigit ---\n");
	printf("%d\n", ft_isdigit('5'));
	printf("%d\n", ft_isdigit('a'));

	printf("--- ft_isalnum ---\n");
	printf("%d\n", ft_isalnum('z'));
	printf("%d\n", ft_isalnum('%'));

	printf("--- ft_isascii ---\n");
	printf("%d\n", ft_isascii(65));
	printf("%d\n", ft_isascii(200));

	printf("--- ft_isprint ---\n");
	printf("%d\n", ft_isprint('A'));
	printf("%d\n", ft_isprint('\n'));

	printf("--- ft_toupper ---\n");
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('A'));

	printf("--- ft_tolower ---\n");
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('a'));

	printf("--- ft_strlen ---\n");
	printf("%zu\n", ft_strlen("Hello World"));
	printf("%zu\n", ft_strlen(""));

	printf("--- ft_memset ---\n");
	char ms[6] = "Hello";
	ft_memset(ms, 'x', 5);
	printf("%s\n", ms);

	printf("--- ft_bzero ---\n");
	char bz[6] = "Hello";
	ft_bzero(bz, 5);
	printf("%s\n", bz);

	printf("--- ft_memcpy ---\n");
	char mcsrc[] = "42School";
	char mcdst[10] = {0};
	ft_memcpy(mcdst, mcsrc, 8);
	printf("%s\n", mcdst);

	printf("--- ft_memmove ---\n");
	char mv[] = "123456789";
	ft_memmove(mv + 2, mv, 5);
	printf("%s\n", mv);

	printf("--- ft_strchr ---\n");
	printf("%s\n", ft_strchr("Hello World", 'W'));
	printf("%p\n", (void *)ft_strchr("Hello", 'z'));

	printf("--- ft_strrchr ---\n");
	printf("%s\n", ft_strrchr("Hello World", 'o'));
	printf("%p\n", (void *)ft_strrchr("Hello", 'z'));

	printf("--- ft_strncmp ---\n");
	printf("%d\n", ft_strncmp("abc", "abd", 3));
	printf("%d\n", ft_strncmp("abc", "abc", 3));

	printf("--- ft_memchr ---\n");
	printf("%s\n", (char *)ft_memchr("Hello World", 'W', 11));

	printf("--- ft_memcmp ---\n");
	printf("%d\n", ft_memcmp("abc", "abd", 3));
	printf("%d\n", ft_memcmp("abc", "abc", 3));

	printf("--- ft_strnstr ---\n");
	printf("%s\n", ft_strnstr("Hello World", "World", 11));
	printf("%p\n", (void *)ft_strnstr("Hello World", "Cat", 11));

	printf("--- ft_atoi ---\n");
	printf("%d\n", ft_atoi("   -123abc"));
	printf("%d\n", ft_atoi("42"));

	printf("--- ft_calloc ---\n");
	int *cal = ft_calloc(3, sizeof(int));
	printf("%d %d %d\n", cal[0], cal[1], cal[2]);
	free(cal);

	printf("--- ft_strdup ---\n");
	char *dup = ft_strdup("Hello");
	printf("%s\n", dup);
	free(dup);

	printf("--- ft_strlcpy ---\n");
	char lc1[10];
	printf("%zu\n", ft_strlcpy(lc1, "Hello", 10));
	printf("%s\n", lc1);

	printf("--- ft_strlcat ---\n");
	char lca[8] = "42";
	printf("%zu\n", ft_strlcat(lca, "Network", 8));
	printf("%s\n", lca);

	return (0);
}
