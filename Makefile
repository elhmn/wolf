# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 11:07:01 by bmbarga           #+#    #+#              #
#    Updated: 2014/11/06 17:06:00 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c

SRCDIR = ./srcs/

OBJS = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCDIR), $(SRC))

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB42 = -L /usr/X11/lib

LIBHOME = -L ./

LIBS = -lmlx -lX11 -lXext -lm

INCLUDES = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(LIB42) -o $(NAME) $(OBJS) $(LIBS)

$(OBJS): 
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)  

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
