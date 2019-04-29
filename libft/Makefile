# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 19:26:56 by yquaro            #+#    #+#              #
#    Updated: 2019/04/27 13:26:21 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CFLAGS =  -Wall -Wextra -Werror 
NAME = libft.a
SRC = ft_*.c
OBJ = *.o

all: $(NAME)
$(NAME): $(SRC)
	gcc -c -g $(SRC) -I includes/
	ar rcs $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
