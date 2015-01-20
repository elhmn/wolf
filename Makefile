# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 11:07:01 by bmbarga           #+#    #+#              #
#    Updated: 2015/01/20 01:19:43 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c check_errors.c fun_err_01.c init_var_01.c init_var_02.c \
	  debug_01.c raycaster.c ray_len.c draw.c get_map.c event_handle.c \
	  color.c event_handle_02.c

SRCDIR = ./srcs/

OBJDIR = ./objs/

OBJ = $(SRC:.c=.o)

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(OBJ))

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB42 = -L /usr/X11/lib

LIBHOME = -L /usr/lib64/X11/

LIBFT = -L ./libft/

LIBS = -lmlx -lX11 -lXext -lm -lft

INCLUDES = -I includes/ -I /usr/X11/include/X11

INCHOME = -I includes/ -I /usr/include/X11

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(LIB42) $(LIBFT) -o $(NAME) $(OBJS) $(LIBS)

home: obj
	make -C libft/
	$(CC) $(FLAGS) $(LIBHOME) $(LIBFT) -o $(NAME) $(OBJS) $(LIBS)
	
obj: $(SRCS)
	$(CC) $(FLAGS) $(INCHOME) -c $(SRCS) 

$(OBJS): $(SRCS) 
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

clean:
	rm -rf $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/

re: fclean all
