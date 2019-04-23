
# CFLAGS =  -Wall -Wextra -Werror 
NAME = ft_printf
SRC = ft_printf.c struct_specifier.c is_it_something.c read_flags.c
OBJS = ft_printf.o struct_specifier.o is_it_something.o read_flags.o

all: $(NAME)
$(NAME):
	make -C libft/ re
	gcc -o $(NAME) $(SRC) -I libft/includes/ -L libft/ -lft
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)
fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
re: fclean all