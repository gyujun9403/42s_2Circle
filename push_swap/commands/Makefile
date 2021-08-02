# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 21:50:34 by gyeon             #+#    #+#              #
#    Updated: 2021/08/03 00:54:03 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
DIR_HEADER = ../header
SRC = commands_push.c \
	commands_rotate.c \
	commands_rrotate.c \
	commands_swap.c

all : $(SRC)
	$(GCC) $(GCCFLAGS) -c $? -I $(DIR_HEADER)
.PHONY : all