# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 14:34:23 by gyeon             #+#    #+#              #
#    Updated: 2021/08/03 15:18:47 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
TARGET = ./push_swap
DIR_COMMANDS = ./commands/
DIR_LIST = ./list_and_utils/
DIR_UTILS = ./list_and_utils/
DIR_SORT = ./sort/
COMMANDS = commands_push.c commands_rotate.c \
	commands_rrotate.c commands_swap.c
LIST = set_list.c
UTILS = utils.c utils2.c
SORT = sort_simple.c sort_three.c sort_four.c \
	sort_five.c sort_quick_a.c sort_quick_b.c
MAIN = ./main.c
DIR_HEADER = ./header
OBJECTS = $(addprefix $(DIR_COMMANDS), $(COMMANDS:.c=.o)) \
	$(addprefix $(DIR_LIST), $(LIST:.c=.o)) \
	$(addprefix $(DIR_UTILS), $(UTILS:.c=.o)) \
	$(addprefix $(DIR_SORT), $(SORT:.c=.o)) $(MAIN:.c=.o)

all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(GCC) $(GCCFLAGS) -o $@ $^
%.o : %.c
	$(GCC) $(GCCFLAGS) -o $@ -c $< -I $(DIR_HEADER)
clean : 
	rm -f $(OBJECTS)
fclean : 
	rm -rf $(TARGET)
re : clean fclean all
.PHONY : all clean fclean re

