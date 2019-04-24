
# CFLAGS =  -Wall -Wextra -Werror 
NAME = ft_printf
SRC = ft_printf.c struct_specifier.c is_it_something.c read_flags.c print_int.c print_arg.c print_diu.c ft_itoa_base.c print_char.c print_dl_dll.c
OBJS = ft_printf.o struct_specifier.o is_it_something.o read_flags.o print_int.o print_arg.o print_diu.o ft_itoa_base.o print_char.o print_dl_dll.o

all: $(NAME)
$(NAME):
	make -C libft/ re
	gcc -g -o $(NAME) $(SRC) -I libft/includes/ -L libft/ -lft
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)
fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
re: fclean all