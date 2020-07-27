/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:44:52 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:44:54 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_formats
{
	char			*flag;
	char			*width;
	char			*accuracy;
	char			*type;
}					t_formats;

char				*ft_itoa_base(long long n, int base);
char				*ft_upperstr(char *str);
int					ft_strcmp(const char *s1, const char *s2);

int					forbidden_formats(t_formats *formats, char *remainder_str,
									char *before_proc);
int					print_c_format(t_formats *formats, char *str);
int					print_digitformat(t_formats *formats, char *str);
int					print_others(t_formats *formats, char *str);
int					print_p_format(t_formats *formats, char *str);
char				*flag(char *str, t_formats *formats);
char				*width(char *str, t_formats *formats);
char				*accuracy(char *str, t_formats *formats);
char				*type(char *str, t_formats *formats);
char				*get_parameter(va_list args, t_formats *formats);
void				update_parameter(char **param, t_formats *formats);
void				print_initial_formats(t_formats *formats);
char				*set_formats(va_list args, t_formats **formats, char *str);
void				clear(t_formats **formats);
void				*ft_memccpy_m(void *dest, void *src, int c, size_t n);
char				*set_nullstr(va_list args, t_formats *formats);
void				ft_putnchar(char c, size_t n);
int					ft_putnstr(char *str, size_t n);
char				*strfromchr(char c);
int					in_set(char c, char *set);
char				*ft_cpytillforbidden(char *str, char *set);
void				*ft_memccpy_m(void *dest, void *src, int c, size_t n);
char				*set_nullstr(va_list args, t_formats *formats);
char				*ft_full(char c, size_t size);
int					ft_max(int a, int b);
int					isnumbertype(char c);
size_t				set_length(t_formats *formats);
char				*set_width(char *param, t_formats *formats);
void				set_stars(va_list args, t_formats **formats);
int					alignement(t_formats *formats, char *str);
int					ft_printf(const char *str, ...);

#endif
