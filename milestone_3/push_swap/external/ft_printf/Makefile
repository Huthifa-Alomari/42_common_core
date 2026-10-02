# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 20:00:10 by hal-omar          #+#    #+#              #
#    Updated: 2026/10/02 19:34:47 by hal-omar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
RM      = rm -rf
AR      = ar rcs

SRCS    = ft_printf.c \
            ft_format.c \
            ft_putchar.c \
            ft_putstr.c \
            ft_putnbr.c \
            ft_putunsigned.c \
            ft_puthex.c \
            ft_putptr.c \
            ft_putdouble

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
