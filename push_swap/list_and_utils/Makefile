# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 21:51:15 by gyeon             #+#    #+#              #
#    Updated: 2021/08/03 00:01:39 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
DIR_HEADER = ../header
SRC = set_list.c \
	utils.c \
	utils2.c
OBJS = $(SRC:.c=.o)

all : $(OBJS)
%.o : %.c
	$(GCC) $(GCCFLAGS) -c $? -I $(DIR_HEADER)
.PHONY : all