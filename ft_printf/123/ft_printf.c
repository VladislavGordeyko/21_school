/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 09:55:28 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/22 17:55:53 by chemelin         ###   ########.fr       */
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
	str = size(str, *formats);
	str = type(str, *formats);
	set_stars(args, formats);
	return (str);
}

static int		do_printf(va_list args, char *str)
{
	char		*before_proc;
	char		*param;
	t_formats	*formats;
	int			count;

	before_proc = malloc(ft_strlen(str) + 1);
	formats = NULL;
	count = 0;
	while (1)
	{
		str = ft_memccpy_mod(before_proc, str, '%', ft_strlen(str) + 1);
		count += ft_putnstr(before_proc, ft_strlen(before_proc));
		if (!str)
			break ;
		str = set_formats(args, &formats, str);
		if (!(*formats->type))
			return (count + forbidden_formats(formats, str, before_proc));
		param = get_parameter(args, formats);
		update_parameter(&param, formats);
		count += alignement(formats, param);
		free(param);
		clear(&formats);
	}
	free(before_proc);
	return (count);
}

int				ft_printf(const char *str, ...)
{
	int			count;
	va_list		args;

	va_start(args, str);
	count = do_printf(args, (char*)str);
	va_end(args);
	return (count);
}
