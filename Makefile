# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 11:07:01 by bmbarga           #+#    #+#              #
#    Updated: 2014/11/08 16:51:45 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c check_errors.c fun_err_01.c

SRCDIR = ./srcs/

OBJS = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCDIR), $(SRC))

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB42 = -L /usr/X11/lib

LIBHOME = -L ./

LIBFT = -L ./libft/

LIBS = -lmlx -lX11 -lXext -lm -lft

INCLUDES = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(LIB42) $(LIBFT) -o $(NAME) $(OBJS) $(LIBS)

$(OBJS): $(SRCS) 
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS) 

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/

re: fclean all
