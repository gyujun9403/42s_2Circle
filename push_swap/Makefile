MAKE = make
GCC = gcc
GCCFLAGS = -Wall -Wextra -Werror
TARGET = ./push_swap
SUB_DIRS = ./commands ./list_and_utils ./sort
MAIN = ./main.c
DIR_HEADER = ./header
DIR_OBJECTS = ./obj/
OBJECTS = *.o

all : $(TARGET)
$(TARGET) : $(addprefix $(DIR_OBJECTS), $(OBJECTS))
	$(GCC) $(GCCFLAGS) -o $@ $?
$(DIR_OBJECTS)*.o : $(MAIN)
	@mkdir -p obj
	$(GCC) $(GCCFLAGS) -c $? -I $(DIR_HEADER)
	@mv $(MAIN:.c=.o) $(DIR_OBJECTS)
	@for dir in $(SUB_DIRS); do \
		$(MAKE) -C $$dir all; \
		mv $$dir/*.o $(DIR_OBJECTS); \
		if [ $$? != 0 ]; then exit 1; fi; \
	done
clean : 
	rm -rf $(DIR_OBJECTS)
fclean : 
	rm -rf $(TARGET)
re : clean fclean all
.PHONY : all clean fclean re