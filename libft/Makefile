# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wollio <wollio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 10:29:33 by wollio            #+#    #+#              #
#    Updated: 2021/10/06 12:47:00 by wollio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = libft.a

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_memmove.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_striteri.c \
		ft_split.c \
		ft_strtrim.c \
		ft_atol.c \
		ft_free1.c \
		ft_free2.c

all:	$(NAME)

$(NAME): *.c
		$(CC) $(FLAGS) -c $(SRC)
		ar rc $(NAME) *.o

clean:
		rm -f *.o

fclean: clean
		 rm -f $(NAME)

re:		fclean all