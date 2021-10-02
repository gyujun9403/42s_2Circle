# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 14:08:10 by gyeon             #+#    #+#              #
#    Updated: 2021/10/01 15:39:53 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L $(DIR_MLX) -Lmlx -lmlx -framework OpenGL -framework Appkit
DIR_MLX = ./minilibx_opengl_20191021
TARGET = so_long
DIR_SRCS = ./srcs/
DIR_HEARDER = ./header
DIR_LIBFT = ./libft/
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft.a

all : $(TARGET)
$(TARGET) : $(addprefix $(DIR_SRCS), $(OBJS)) $(addprefix $(DIR_LIBFT), $(LIBFT))
	$(GCC) $(FLAGS_MLX) -o $@ $^
%.o : %.c
	$(GCC) $(FLAGS) -c -o $@ $^ -I $(DIR_HEARDER)
$(addprefix $(DIR_LIBFT), $(LIBFT)) : 
	@make -C $(DIR_LIBFT) all;
fclean : 
	rm -rf $(TARGET);
	@make -C $(DIR_LIBFT) fclean;
clean : 
	rm -rf $(addprefix $(DIR_SRCS), $(OBJS));
	@make -C $(DIR_LIBFT) clean;
re : clean fclean all
PHONY : all fclean clean re