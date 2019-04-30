
NAME = libftprintf.a
LIBFTLIB = libft/libft.a
SRC = ft_printf.c struct_specifier.c is_it_something.c read_flags.c print_int.c print_arg.c print_diu.c ft_itoa_base.c print_char.c print_dl_dll.c
OBJS = ft_printf.o struct_specifier.o is_it_something.o read_flags.o print_int.o print_arg.o print_diu.o ft_itoa_base.o print_char.o print_dl_dll.o libft/ft_*.o

all: $(NAME)
$(NAME):
	make -C libft/ re
	gcc -g -c $(SRC) -I libft/includes/
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	gcc -o ft_printf $(NAME)
clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)
fclean: clean
	make -C libft/ fclean
	/bin/rm -f ft_printf $(NAME)
re: fclean all