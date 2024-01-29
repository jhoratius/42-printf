# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoratiu <jhoratiu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:22:14 by jhoratiu          #+#    #+#              #
#    Updated: 2023/11/30 15:38:27 by jhoratiu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = printf_main.c printf_verifs.c printf_verifs2.c additionnal_functions.c \

OBJS = $(FILES:.c=.o)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re