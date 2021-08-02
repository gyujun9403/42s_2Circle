MAKE = make
GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
TARGET = ./push_swap
SUB_DIRS = ./commands ./list_and_utils ./sort
MAIN = ./main.c
DIR_HEADER = ./header
OBJECTS = $(addsuffix /*.o, $(SUB_DIRS))

all : $(TARGET)
$(TARGET) : $(OBJECTS) $(MAIN:.c=.o)
	$(GCC) $(GCCFLAGS) -o $@ $^
$(OBJECTS) : 
	@$(MAKE) -C $(@:*.o=) all;
$(MAIN:.c=.o) : 
	$(GCC) $(GCCFLAGS) -c $(MAIN) -I $(DIR_HEADER)
clean : 
	rm -f $(OBJECTS)
fclean : 
	rm -rf $(TARGET)
re : clean fclean all
.PHONY : all clean fclean re make_main make_sub make_objs