#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:10:53 by ysihetii          #+#    #+#              #
#    Updated: 2017/11/08 17:10:57 by ysihetii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc -Wall -Wextra -Werror -c -I libft/includes

#FLAGS=-Wall -Wextra -Werror

NAME=libftprintf.a

CUSTOM_FT=parsing.o parsing2.o

OBJ_PART1=print_s.o print_i.o ft_atoi.o ox.o print_o.o print_u.o print_cc.o print_p.o print_sss.o fun.o fun2.o fun3.o 



OBJ=$(CUSTOM_FT) $(OBJ_PART1)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft all
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

#Custom
parsing.o: parsing.c
	$(CC) parsing.c
parsing2.o: parsing2.c
	$(CC) parsing2.c


#Part 1
print_s.o: print_s.c
	$(CC) print_s.c
print_i.o: print_i.c
	$(CC) print_i.c
ft_atoi.o: ft_atoi.c
	$(CC) ft_atoi.c
ox.o: ox.c
	$(CC) ox.c
print_o.o: print_o.c
	$(CC) print_o.c
print_u.o: print_u.c
	$(CC) print_u.c
print_cc.o: print_cc.c
	$(CC) print_cc.c
print_p.o: print_p.c
	$(CC) print_p.c
print_sss.o: print_sss.c
	$(CC) print_sss.c
fun.o: fun.c
	$(CC) fun.c
fun2.o: fun2.c
	$(CC) fun2.c
fun3.o: fun3.c
	$(CC) fun3.c

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	rm libft/libft.a
	rm $(NAME)

re: fclean all