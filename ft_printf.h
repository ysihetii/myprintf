/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:04:48 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 20:04:51 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

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
int					ft_atoi(const char *a);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					dow(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_print_sss(wchar_t *sstr, t_param *p);
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
void				to_upper(char *str);
int					dow_0x(unsigned long long n);
char				*to_0xl(long long n);
int					print_flag_and_widthss(int len, t_param *p, char *str);
int					fssscontinue(char *str, t_param *p, int len);
t_param				*ft_new_p(t_param *p);
int					prosto_function(char format, int n, char *this);
void				do_manipulations(char **format, t_param **p, int is_valid);
void				ft_preludiya(t_param **p, int *res);
int					chtototamneto(int is_valid, char **format);
char				*to_o0xl(long long n);
char				*to_o0x(int n);
char				*to_u0xl(unsigned long long n);
char				*to_u0x(unsigned int n);
int					dow_i0x(unsigned long long n);
char				*to_i0xl(long long n, char **x);
int					dow_p0x(unsigned long long n);
int					ft_work_with_param(char *str, t_param *p);
char				*ft_pr(char **str, int precision);
int					dow_0x(unsigned long long n);
char				*ft_opr(char **str, int precision);
int					dow_o0x(unsigned long long n);
int					dow_u0x(unsigned long long n);

#endif
