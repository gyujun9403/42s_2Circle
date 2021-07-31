GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
DIR_HEADER = ../header
SRC = sort_quick.c \
	sort_three.c \
	sort_simple.c \
	sort_five.c

all : $(SRC)
	$(GCC) $(GCCFLAGS) -c $? -I $(DIR_HEADER)
.PHONY : all