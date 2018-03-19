#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TYPES_NUM 20
# define MODIFICATORS_NUM 5

#include <stdlib.h>


typedef struct		s_param
{
	int				param;
	char			flag[5];
	int				width;
	int				precision;
	char			modificator[3];
	char			type[3];
}					t_param;


int					find_h(char *str);
int					ft_pass_digit(char *str);
void				ft_print_param(t_param *p);
void				print_flags(t_param *p);
int					not_alph(char c);
int					is_dig(char c);
int					find_z(char *str);


int					ft_printf(char *format, ...);

int					mod(long long int a);
int					ft_atoi(const char *a);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					dow(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_print_sS(wchar_t *sstr, t_param *p);
int					ft_print_s(char *str, t_param *p);
int					ft_print_pr(char *str, t_param *p);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					print_flag_and_width(int len, t_param *p, char *str);
int					ft_print_x(long long n, t_param *p);
int					ft_print_o(long long n, t_param *p);
int					ft_print_i(long long n, t_param *p);
int					ft_print_u(unsigned long long n, t_param *p);
int					ft_print_c(long long n, t_param *p);
int					ft_print_p(unsigned long long n, t_param *p);

void				print_flags(t_param *p);
void				ft_print_param(t_param *p);

#endif