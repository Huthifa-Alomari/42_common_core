# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/02 01:54:53 by hal-omar          #+#    #+#              #
#    Updated: 2026/10/08 21:30:18 by hal-omar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I. -Ilibft -Ift_printf
RM			= rm -f

LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a

SRCS		= srcs/main.c \
			  srcs/parsing/parse_args.c \
			  srcs/parsing/parse_flags.c \
			  srcs/parsing/parse_number.c \
			  srcs/parsing/parse_validate.c \
			  srcs/parsing/error.c \
			  srcs/stack/stack_init.c \
			  srcs/stack/stack_utils.c \
			  srcs/analysis/disorder.c \
			  srcs/analysis/ranks.c \
			  srcs/ops/ops_swap.c \
			  srcs/ops/ops_push.c \
			  srcs/ops/ops_rotate.c \
			  srcs/ops/ops_reverse.c \
			  srcs/sort/strategy.c \
			  srcs/sort/sort_simple.c \
			  srcs/sort/sort_medium.c \
			  srcs/sort/sort_complex.c \
			  srcs/sort/sort_utils.c \
			  srcs/bench/bench.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
