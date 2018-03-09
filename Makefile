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

CC=gcc -Wall -Wextra -Werror -c

#FLAGS=-Wall -Wextra -Werror

NAME=libftprintf.a

CUSTOM_FT=parsing.o

OBJ_PART1=print_s.o print_i.o ft_atoi.o ox.o print_o.o print_u.o print_c.o print_p.o print_Ss.o fun.o



OBJ=$(CUSTOM_FT) $(OBJ_PART1)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ); ranlib $(NAME)

#Custom
parsing.o: parsing.c
	$(CC) parsing.c




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
print_c.o: print_c.c
	$(CC) print_c.c
print_p.o: print_p.c
	$(CC) print_p.c
print_Ss.o: print_Ss.c
	$(CC) print_Ss.c
fun.o: fun.c
	$(CC) fun.c

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all