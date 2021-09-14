# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 22:39:13 by gyeon             #+#    #+#              #
#    Updated: 2021/09/14 00:07:12 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = pipex
DIR_SRC = ./srcs/
DIR_header = ./header
DIR_LIBFT = ./libft/
SRC = handle_cmds.c \
	handle_error.c \
	handle_files_and_env.c \
	handle_process.c \
	utils.c \
	main.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a

all : $(TARGET)
$(TARGET) : $(addprefix $(DIR_SRC), $(OBJ)) $(addprefix $(DIR_LIBFT), $(LIBFT))
	$(GCC) -o $@ $^
%.o : %.c
	$(GCC) $(FLAGS) -c $< -o $@ -I $(DIR_header)
$(addprefix $(DIR_LIBFT), $(LIBFT)) : 
	@make -C $(DIR_LIBFT) all;
clean : 
	@rm -f $(addprefix $(DIR_SRC), $(OBJ)) $(addprefix $(DIR_LIBFT), $(LIBFT))
fclean : 
	@rm -f $(TARGET)
re : clean fclean all
.PHONY : all clean fclean re