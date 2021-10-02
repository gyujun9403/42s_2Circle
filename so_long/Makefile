# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 14:08:10 by gyeon             #+#    #+#              #
#    Updated: 2021/10/02 15:36:15 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L $(DIR_MLX) -lz -framework OpenGL -framework Appkit
TARGET = so_long
DIR_MLX = ./minilibx_opengl_20191021/
DIR_SRCS = ./srcs/
DIR_HEARDER = ./header
DIR_LIBFT = ./libft/
DIR_GNL = ./get-next-line/
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft.a
MLX = libmlx.a
GNL = gnl.a

all : $(TARGET)
$(TARGET) : $(addprefix $(DIR_SRCS), $(OBJS)) \
$(addprefix $(DIR_LIBFT), $(LIBFT)) \
$(addprefix $(DIR_MLX), $(MLX)) \
$(addprefix $(DIR_GNL), $(GNL))
	$(GCC) $(FLAGS_MLX) -o $@ $^
%.o : %.c
	$(GCC) $(FLAGS) -c -o $@ $^ -I $(DIR_HEARDER)
$(addprefix $(DIR_LIBFT), $(LIBFT)) : 
	@make -C $(DIR_LIBFT) all;
	@make -C $(DIR_LIBFT) bonus;
$(addprefix $(DIR_MLX), $(MLX)) : 
	@make -C $(DIR_MLX) all;
$(addprefix $(DIR_GNL), $(GNL)) : 
	@make -C $(DIR_GNL) all;
fclean : 
	@rm -rf $(TARGET);
	@make -C $(DIR_LIBFT) fclean;
	@make -C $(DIR_GNL) fclean;
clean : 
	@rm -rf $(addprefix $(DIR_SRCS), $(OBJS));
	@make -C $(DIR_LIBFT) clean;
	@make -C $(DIR_MLX) clean;
	@make -C $(DIR_GNL) clean;
re : clean fclean all
PHONY : all fclean clean re