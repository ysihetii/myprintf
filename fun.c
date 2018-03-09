
#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>



int find_h(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h' &&  ( (i == 0 && str[i + 1] !='h') || (str[i + 1] != 'h' && str[i - 1] != 'h')))
			return (1);
		i++;
	}
	return(0);
}

int ft_pass_digit(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

void print_flags(t_param *p)
{
	printf("\n-------------------------\n");
	for (int i = 0; i < 5; i++)
		printf("%i=%c\n", i, p->flag[i]);
	printf("-------------------------\n");
}
void ft_print_param(t_param *p)
{
	printf("\n-------------------------\n");
	printf("param=%i\n", p->param);
	printf("flag=%c\n", p->flag[0]);
	printf("width=%i\n", p->width);
	printf("precision=%i\n", p->precision);
	printf("modificator=%s\n", p->modificator);
	printf("type=%s\n", p->type);
	printf("-------------------------\n");
}

int not_alph(char c)
{
	char *alph ="0123456789. +-#sSpdDioOuUxXcChljz%";
	return ((int)strchr(alph, c));
}

int is_dig(char c)
{
	return (c >= '0' && c <='9');
}
int find_z(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' && (i == 0 || !is_dig(str[i - 1])) && str[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}
