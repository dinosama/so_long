# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 21:45:10 by aaapatou          #+#    #+#              #
#    Updated: 2021/09/15 00:32:13 by aaapatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

SRC = ft_isdigit.c \
ft_atoi.c ft_isprint.c \
ft_itoa.c ft_strdup.c \
ft_putchar_fd.c ft_isalnum.c \
ft_isalpha.c ft_bzero.c \
ft_putnbr_fd.c ft_isascii.c \
ft_putstr_fd.c ft_strlen.c ft_calloc.c \
ft_putchar.c ft_putstr.c \
ft_strchr.c \
ft_substr.c \

OBJ = $(SRC:.c=.o)

SRC_BONUS =

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(OBJ) :
	$(CC) $(CCFLAGS) -c $(SRC)

$(OBJ_BONUS) :
	$(CC) $(CCFLAGS) -c $(SRC) $(SRC_BONUS)

bonus: $(OBJ_BONUS)
	ar cr $(NAME) $(OBJ) $(OBJ_BONUS)
	ranlib $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
