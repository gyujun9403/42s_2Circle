# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 22:39:13 by gyeon             #+#    #+#              #
#    Updated: 2021/09/25 15:00:44 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = pipex
DIR_SRC = ./srcs/
DIR_SRC_BONUS = ./srcs_bonus/
DIR_header = ./header
DIR_header_BONUS = ./header_bonus
DIR_LIBFT = ./libft/
SRC = handle_cmds1.c \
	handle_cmds2.c \
	handle_error.c \
	handle_files_and_env.c \
	handle_process.c \
	utils.c \
	main.c
SRC_BONUS = handle_cmds1_bonus.c \
	handle_cmds2_bonus.c \
	handle_error_bonus.c \
	handle_files_and_env_bonus.c \
	handle_process_bonus.c \
	utils_bonus.c \
	main_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBFT = libft.a

all : $(TARGET)
$(TARGET) : $(addprefix $(DIR_SRC), $(OBJ)) $(addprefix $(DIR_LIBFT), $(LIBFT))
	$(GCC) -o $@ $^
bonus : $(addprefix $(DIR_SRC_BONUS), $(OBJ_BONUS)) $(addprefix $(DIR_LIBFT), $(LIBFT))
	$(GCC) -o $(TARGET) $^
%_bonus.o : %_bonus.c
	$(GCC) $(FLAGS) -c $< -o $@ -I $(DIR_header_BONUS)
%.o : %.c
	$(GCC) $(FLAGS) -c $< -o $@ -I $(DIR_header)
$(addprefix $(DIR_LIBFT), $(LIBFT)) : 
	@make -C $(DIR_LIBFT) all;
clean : 
	@rm -f $(addprefix $(DIR_SRC), $(OBJ)) $(addprefix $(DIR_LIBFT), *.o) $(addprefix $(DIR_SRC_BONUS), $(OBJ_BONUS))
fclean : 
	@rm -f $(TARGET) $(addprefix $(DIR_LIBFT), $(LIBFT))
re : clean fclean all
.PHONY : all bonus clean fclean re