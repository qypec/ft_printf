
# CFLAGS =  -Wall -Wextra -Werror 
NAME = ft_printf
SRC = ft_printf.c print_int.c print_arg.c
OBJS = ft_printf.o

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