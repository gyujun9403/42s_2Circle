MAKE = make
GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
TARGET = ./push_swap
SUB_DIRS = ./commands ./list_and_utils ./sort
MAIN = ./main.c
DIR_HEADER = ./header
OBJECTS = $(addsuffix *.o, $(SUB_DIRS))

all : $(TARGET)
$(TARGET) : make_sub make_main $(OBJECTS)
	$(GCC) $(GCCFLAGS) -o $@ $?
make_main :
	$(GCC) $(GCCFLAGS) -c $(MAIN) -I $(DIR_HEADER)
	@mv $(MAIN:.c=.o) $(DIR_OBJECTS)
make_sub : 
	@for dir in $(SUB_DIRS); do \
		$(MAKE) -C $$dir all; \
		if [ $$? != 0 ]; then exit 1; fi; \
	done
clean : 
	rm -f $(OBJECTS)
fclean : 
	rm -rf $(TARGET)
re : clean fclean all
.PHONY : all clean fclean re make_main make_sub make_objs