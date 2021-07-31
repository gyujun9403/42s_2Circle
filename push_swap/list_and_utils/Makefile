GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
DIR_HEADER = ../header
SRC = set_list.c \
	utils.c \
	utils2.c

all : $(SRC)
	$(GCC) $(GCCFLAGS) -c $? -I $(DIR_HEADER)
.PHONY : all