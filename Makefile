# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 16:16:54 by yquaro            #+#    #+#              #
#    Updated: 2019/05/20 16:47:38 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# Adds a character index to the archive

FLAGS = -Wall -Wextra -Werror
SOURCE = ft_printf.c color.c print_arg.c buffer_output.c add_in_glbuffer.c \
	bust.c print_date.c parse.c struct_spec.c is_it_something.c read_flags.c \
	print_diu.c ft_itoa_base.c print_char.c print_dl_dll.c parse.c print_int.c \
	print_float.c display_int.c
OBJS = *.o
OBJDIR = .obj
NAME = libftprintf.a

all: $(NAME)
$(NAME):
	make -C libft/ re
	gcc -c $(FLAGS) $(SOURCE)  # не забыть про ФЛАГИ!!!!!
	mkdir $(OBJDIR)
	mv $(OBJS) $(OBJDIR)
	ar rc $(NAME) $(OBJDIR)/$(OBJS) libft/$(OBJDIR)/*.o
	ranlib $(NAME)
	gcc main.c -L. -lftprintf -o ft_printf # убрать

clean:
	make -C libft/ clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
