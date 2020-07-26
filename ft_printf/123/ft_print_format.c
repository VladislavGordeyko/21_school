/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:06:56 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/22 20:34:49 by chemelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			forbidden_formats(t_formats *formats, char *remainder_str,
									char *before_proc)
{
	if (!(*formats->type))
	{
		ft_putnchar('%', 1);
		print_initial_formats(formats);
		ft_putnstr(remainder_str, ft_strlen(remainder_str));
		clear(&formats);
		free(before_proc);
		return (1 + ft_strlen(remainder_str));
	}
	return (0);
}

int			print_c_format(t_formats *formats, char *str)
{
	if (in_set('-', formats->flag))
	{
		ft_putnchar(*str, 1);
		if (ft_atoi(formats->width) - 1 > 0)
			ft_putnchar(' ', ft_atoi(formats->width) - 1);
	}
	else
	{
		if (ft_atoi(formats->width) - 1 > 0)
			ft_putnchar(' ', ft_atoi(formats->width) - 1);
		ft_putnchar(*str, 1);
	}
	return ((ft_atoi(formats->width) > 0) ? ft_atoi(formats->width) : 1);
}

int			print_digitformat(t_formats *formats, char *str)
{
	char	*zeros;

	if (str[0] == '-')
		ft_putnchar('-', 1);
	else if (in_set('+', formats->flag) && in_set(formats->type[0], "id"))
		ft_putnchar('+', 1);
	else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		ft_putnstr(str, 2);
	if (ft_strlen(str) < (size_t)ft_atoi(formats->width))
	{
		zeros = ft_full('0', (size_t)ft_atoi(formats->width) - ft_strlen(str));
		ft_putnstr(zeros, ft_strlen(zeros));
		free(zeros);
	}
	if (str[0] == '-' || in_set('+', formats->flag))
		ft_putnstr(str + 1, ft_strlen(str + 1));
	else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		ft_putnstr(str + 2, ft_strlen(str + 2));
	else
		ft_putnstr(str, ft_strlen(str));
	return (ft_max(ft_strlen(str), (size_t)ft_atoi(formats->width)));
}

int			print_others(t_formats *formats, char *str)
{
	size_t	max_length;
	int		accuracy;

	max_length = ft_strlen(str);
	accuracy = (size_t)ft_atoi(formats->accuracy + 1);
	if (formats->type[0] == 's' && formats->accuracy[0] == '.' &&
			max_length > (size_t)accuracy)
		max_length = accuracy;
	if (in_set('-', formats->flag))
	{
		ft_putnstr(str, max_length);
		if (max_length < (size_t)ft_atoi(formats->width))
			ft_putnchar(' ', (size_t)ft_atoi(formats->width) - max_length);
	}
	else
	{
		if (max_length < (size_t)ft_atoi(formats->width))
			ft_putnchar(' ', (size_t)ft_atoi(formats->width) - max_length);
		ft_putnstr(str, max_length);
	}
	return (ft_max(max_length, ft_atoi(formats->width)));
}

int			print_p_format(t_formats *formats, char *str)
{
	if (in_set('-', formats->flag))
	{
		ft_putnstr("0x", 2);
		ft_putnstr(str, ft_strlen(str));
		if (ft_strlen(str) + 2 < (size_t)ft_atoi(formats->width))
			ft_putnchar(' ',
				(size_t)ft_atoi(formats->width) - ft_strlen(str) - 2);
	}
	else
	{
		if (ft_strlen(str) + 2 < (size_t)ft_atoi(formats->width))
			ft_putnchar(' ',
				(size_t)ft_atoi(formats->width) - ft_strlen(str) - 2);
		ft_putnstr("0x", 2);
		ft_putnstr(str, ft_strlen(str));
	}
	return (ft_max(ft_strlen(str) + 2, (size_t)ft_atoi(formats->width)));
}
