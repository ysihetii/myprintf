#include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fccontinue(char *str, t_param *p, int len)
{
    int res;

    res = 0;
    if (p->flag[2])
    {
        while (p->width - res - len > 0)
            if (p->precision > -1)
                res += write(1, "0", 1);
            else
                res += write(1, "0", 1);
        res += write(1, str, len);
    }
    else
    {
        while (p->width - res - len )
            res += write(1, " ", 1);
        res += write(1, str, len);
    }
    return (res);
}

int pr_cx(char *str, t_param *p, int len)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else 
        res = fccontinue(str, p, len);
    if (str)
        free(str);
	return (res);
}

int ft_print_unicode(char *s, wchar_t n)
{
    if (n <= 127)
        *s = n;
    else if (n <= 2047)
    {
        s[0] = (n >> 6) | 192;
        s[1] = (n & 63) | 128;
    }
    else if (n <= 65535)
    {
        s[0] = (n >> 12) | 224;
        s[1] = ((n >> 6) & 63) | 128;
        s[2] = (n & 63) | 128;
    }
    else
    {
        s[0] = (n >> 18) | 240;
        s[1] = ((n >> 12) & 63) | 128;
        s[2] = ((n >> 6) & 63) | 128;
        s[3] = (n & 63) | 128;
    }
    return (strlen(s));
}
int null_prec(t_param *p, char *chislo)
{
    int j;

    j = 0;
    while (j < p->width - 1)
    {
        if (p->flag[2])
            write(1, "0", 1);
        else
             write(1, " ", 1);
         j++;
    }
    write(1, chislo, 1);
    free(chislo);
    return p->width;
}
    
int ft_print_c(long long n, t_param *p)
{
    char *chislo;
    int len;

    chislo = ft_strnew(4);
    if (n == 0)
       return (pr_cx(chislo, p, 1));
    else if ((!strcmp(p->modificator, "l") || !strcmp(p->type, "C")) && MB_CUR_MAX == 4)
        len = ft_print_unicode(chislo, (wchar_t)n);
    else
        *chislo = (char)n;
    if (p->precision == 0 )
        return null_prec(p, chislo);
    len = strlen(chislo);
    return (pr_cx(chislo, p, len));
}
