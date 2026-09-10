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
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char s[] = "Hello World";
    char *result;

    result = ft_memchr(s, 'W', 11);

    if (result)
        printf("Found: %s\n", result);
    else
        printf("Not found\n");

    return (0);
}
