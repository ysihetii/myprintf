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

CC=gcc -Wall -Wextra -Werror -c -I includes/

#FLAGS=-Wall -Wextra -Werror

NAME=libft.a

CUSTOM_FT=mod.o

OBJ_PART1=ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o \
ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o \
ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o \
ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o

OBJ_PART2=ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o \
ft_strequ.o ft_strnequ.o ft_strsub.o ft_strsub.o ft_strjoin.o \
ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o \
ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o

OBJ_PART3=ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o

OBJ=$(CUSTOM_FT) $(OBJ_PART2) $(OBJ_PART1) $(OBJ_PART3)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ); ranlib $(NAME)

#Custom
mod.o: mod.c
	$(CC) mod.c




#Part 1
ft_memset.o: ft_memset.c
	$(CC) ft_memset.c
ft_bzero.o: ft_bzero.c
	$(CC) ft_bzero.c
ft_memcpy.o: ft_memcpy.c
	$(CC) ft_memcpy.c
ft_memccpy.o: ft_memccpy.c
	$(CC) ft_memccpy.c
ft_memmove.o: ft_memmove.c
	$(CC) ft_memmove.c
ft_memchr.o: ft_memchr.c
	$(CC) ft_memchr.c
ft_memcmp.o: ft_memcmp.c
	$(CC) ft_memcmp.c
ft_strlen.o: ft_strlen.c
	$(CC) ft_strlen.c
ft_strdup.o: ft_strdup.c
	$(CC) ft_strdup.c
ft_strcpy.o: ft_strcpy.c
	$(CC) ft_strcpy.c
ft_strncpy.o: ft_strncpy.c
	$(CC) ft_strncpy.c
ft_strcat.o: ft_strcat.c
	$(CC) ft_strcat.c
ft_strncat.o: ft_strncat.c
	$(CC) ft_strncat.c
ft_strlcat.o: ft_strlcat.c
	$(CC) ft_strlcat.c
ft_strchr.o: ft_strchr.c
	$(CC) ft_strchr.c
ft_strrchr.o: ft_strrchr.c
	$(CC) ft_strrchr.c
ft_strstr.o: ft_strstr.c
	$(CC) ft_strstr.c
ft_strnstr.o: ft_strnstr.c
	$(CC) ft_strnstr.c
ft_strcmp.o: ft_strcmp.c
	$(CC) ft_strcmp.c
ft_strncmp.o: ft_strncmp.c
	$(CC) ft_strncmp.c
ft_atoi.o: ft_atoi.c
	$(CC) ft_atoi.c
ft_isalpha.o: ft_isalpha.c
	$(CC) ft_isalpha.c
ft_isdigit.o: ft_isdigit.c
	$(CC) ft_isdigit.c
ft_isalnum.o: ft_isalnum.c
	$(CC) ft_isalnum.c
ft_isascii.o: ft_isascii.c
	$(CC) ft_isascii.c
ft_isprint.o: ft_isprint.c
	$(CC) ft_isprint.c
ft_toupper.o: ft_toupper.c
	$(CC) ft_toupper.c
ft_tolower.o: ft_tolower.c
	$(CC) ft_tolower.c

#Part 2
ft_memalloc.o: ft_memalloc.c
	$(CC) ft_memalloc.c
ft_memdel.o: ft_memdel.c
	$(CC) ft_memdel.c
ft_strnew.o: ft_strnew.c
	$(CC) ft_strnew.c
ft_strdel.o: ft_strdel.c
	$(CC) ft_strdel.c
ft_strclr.o: ft_strclr.c
	$(CC) ft_strclr.c
ft_striter.o: ft_striter.c
	$(CC) ft_striter.c
ft_striteri.o: ft_striteri.c
	$(CC) ft_striteri.c
ft_strmap.o: ft_strmap.c
	$(CC) ft_strmap.c
ft_strmapi.o: ft_strmapi.c
	$(CC) ft_strmapi.c
ft_strequ.o: ft_strequ.c
	$(CC) ft_strequ.c
ft_strnequ.o: ft_strnequ.c
	$(CC) ft_strnequ.c
ft_strsub.o: ft_strsub.c
	$(CC) ft_strsub.c
ft_strjoin.o: ft_strjoin.c
	$(CC) ft_strjoin.c
ft_strtrim.o: ft_strtrim.c
	$(CC) ft_strtrim.c
ft_strsplit.o: ft_strsplit.c
	$(CC) ft_strsplit.c
ft_itoa.o: ft_itoa.c
	$(CC) ft_itoa.c
ft_putchar.o: ft_putchar.c
	$(CC) ft_putchar.c
ft_putstr.o: ft_putstr.c
	$(CC) ft_putstr.c
ft_putendl.o: ft_putendl.c
	$(CC) ft_putendl.c
ft_putnbr.o: ft_putnbr.c
	$(CC) ft_putnbr.c
ft_putchar_fd.o: ft_putchar_fd.c
	$(CC) ft_putchar_fd.c
ft_putstr_fd.o: ft_putstr_fd.c
	$(CC) ft_putstr_fd.c
ft_putendl_fd.o: ft_putendl_fd.c
	$(CC) ft_putendl_fd.c
ft_putnbr_fd.o: ft_putnbr_fd.c
	$(CC) ft_putnbr_fd.c

#Part 3
ft_lstnew.o: ft_lstnew.c
	$(CC) ft_lstnew.c
ft_lstdelone.o: ft_lstdelone.c
	$(CC) ft_lstdelone.c
ft_lstdel.o: ft_lstdel.c
	$(CC) ft_lstdel.c
ft_lstadd.o: ft_lstadd.c
	$(CC) ft_lstadd.c
ft_lstiter.o: ft_lstiter.c
	$(CC) ft_lstiter.c
ft_lstmap.o: ft_lstmap.c
	$(CC) ft_lstmap.c


clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all