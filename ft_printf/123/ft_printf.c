/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:44:45 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:44:48 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int				alignement(t_formats *formats, char *str)
{
	if (in_set('0', formats->flag) && !in_set('-', formats->flag) &&
		((in_set(formats->type[0], "iudxX") &&
		(formats->accuracy[0] == '\0' || ft_atoi(formats->accuracy + 1) < 0)) ||
		formats->type[0] == '%'))
		return (print_digitformat(formats, str));
	if (in_set('#', formats->flag) && in_set('0', formats->flag) &&
		in_set(formats->type[0], "xX") && formats->accuracy[0] == '\0')
		return (print_digitformat(formats, str));
	if (formats->type[0] == 'c')
		return (print_c_format(formats, str));
	else if (formats->type[0] == 'p')
		return (print_p_format(formats, str));
	return (print_others(formats, str));
}

char			*set_formats(va_list args, t_formats **formats, char *str)
{
	if (!(*formats))
		*formats = malloc(sizeof(t_formats));
	str = flag(str, *formats);
	str = width(str, *formats);
	str = accuracy(str, *formats);
	str = type(str, *formats);
	set_stars(args, formats);
	return (str);
}

static int		main_func(va_list args, char *str)
{
	char		*bef_perc;
	char		*param;
	t_formats	*formats;
	int			count;

	bef_perc = malloc(ft_strlen(str) + 1);
	formats = NULL;
	count = 0;
	while (1)
	{
		str = ft_memccpy_m(bef_perc, str, '%', ft_strlen(str) + 1);
		count += ft_putnstr(bef_perc, ft_strlen(bef_perc));
		if (!str)
			break ;
		str = set_formats(args, &formats, str);
		if (!(*formats->type))
			return (count + forbidden_formats(formats, str, bef_perc));
		param = get_parameter(args, formats);
		update_parameter(&param, formats);
		count += alignement(formats, param);
		free(param);
		clear(&formats);
	}
	free(bef_perc);
	return (count);
}

int				ft_printf(const char *str, ...)
{
	int			count;
	va_list		args;

	va_start(args, str);
	count = main_func(args, (char*)str);
	va_end(args);
	return (count);
}
