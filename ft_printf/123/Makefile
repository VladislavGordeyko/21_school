# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 10:47:07 by chemelin          #+#    #+#              #
#    Updated: 2020/05/22 20:37:12 by chemelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_memcpy.c ft_strlen.c ft_atoi.c ft_toupper.c ft_strjoin.c\
ft_printf.c ft_printf_utils.c ft_strdup.c ft_memmove.c ft_substr.c ft_strlcpy.c\
ft_utils.c  ft_alignement.c ft_parameter.c ft_work_utils.c\
ft_flags.c ft_formats.c ft_print_format.c
OBJECTS = $(SRCS:.c=.o)
CC = clang
FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus: all

%.o: %.c $(HEADER)
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
