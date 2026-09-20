# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 20:00:10 by hal-omar          #+#    #+#              #
#    Updated: 2026/09/20 20:00:13 by hal-omar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

SRCS        = ft_printf.c ft_putchar.c ft_puthex.c ft_strlen.c \
              ft_putmem.c ft_putnbr.c ft_putstr.c ft_putunsigned.c

OBJS        = $(SRCS:.c=.o)

CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -rf
AR          = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
