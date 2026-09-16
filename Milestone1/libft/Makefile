# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hal-omar <hal-omar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/16 00:10:55 by hal-omar          #+#    #+#              #
#    Updated: 2026/09/16 14:13:40 by hal-omar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
HEADER	= libft.h

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c \
	   	  ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   	  ft_isdigit.c ft_isprint.c ft_itoa.c \
	   	  ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   	  ft_memmove.c ft_memset.c ft_putchar_fd.c \
	   	  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	   	  ft_split.c ft_strchr.c ft_strdup.c \
	   	  ft_striteri.c ft_strjoin.c ft_strlcat.c \
	   	  ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	   	  ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	   	  ft_strtrim.c ft_substr.c ft_tolower.c \
	   	  ft_toupper.c ft_lstnew.c ft_lstadd_front.c \
	   	  ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \
	   	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	   	  ft_lstmap.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony : all fclean clean re
