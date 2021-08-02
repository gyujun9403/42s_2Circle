# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 21:57:49 by gyeon             #+#    #+#              #
#    Updated: 2021/08/02 22:22:04 by gyeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
DIR_HEADER = ../header
SRC = sort_quick_a.c \
	sort_quick_b.c \
	sort_simple.c \
	sort_three.c \
	sort_four.c \
	sort_five.c

all : $(SRC)
	$(GCC) $(GCCFLAGS) -c $? -I $(DIR_HEADER)
.PHONY : all