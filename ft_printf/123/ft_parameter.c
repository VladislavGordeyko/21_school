/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:14:03 by chemelin          #+#    #+#             */
/*   Updated: 2020/07/27 23:36:24 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char			*xbigx_parameter(va_list args, t_formats *formats)
{
	long long	res;

	res = va_arg(args, int);
	if (res == 0 && formats->accuracy[0] == '.' &&
		ft_atoi(formats->accuracy + 1) == 0)
		return (ft_strdup(""));
	if (res == 0)
		return (ft_itoa_base(res, 16));
	if (formats->type[0] == 'x')
		return (ft_itoa_base((unsigned)res, 16));
	if (formats->type[0] == 'X')
		return (ft_upperstr(ft_itoa_base((unsigned)res, 16)));
	return (ft_itoa_base(0, 16));
}

char			*get_parameter(va_list args, t_formats *formats)
{
	long long	res;

	if (!(ft_strcmp(formats->type, "s")))
		return (set_nullstr(args, formats));
	if (!(ft_strcmp(formats->type, "%")))
		return (strfromchr('%'));
	if (in_set(formats->type[0], "id"))
		return (ft_itoa_base(va_arg(args, int), 10));
	if (in_set(formats->type[0], "xX"))
		return (xbigx_parameter(args, formats));
	res = va_arg(args, long long);
	if (!(ft_strcmp(formats->type, "c")))
		return (strfromchr(res));
	else if ((!(ft_strcmp(formats->type, "u"))))
		return (ft_itoa_base((unsigned)res, 10));
	else if (!(ft_strcmp(formats->type, "p")))
		return (ft_itoa_base(res, 16));
	return (NULL);
}

void			update_parameter(char **param, t_formats *formats)
{
	char		*pos_str;

	if (ft_atoi(*param) == 0 && in_set(formats->type[0], "idup") &&
		formats->accuracy[0] == '.' && ft_atoi(formats->accuracy + 1) == 0)
	{
		if (in_set('+', formats->flag))
			(*param)[1] = '\0';
		else
			(*param)[0] = '\0';
	}
	if (in_set(formats->type[0], "iduxXp"))
		*param = set_width(*param, formats);
	if ((in_set('+', formats->flag)) && param[0][0] != '-')
	{
		pos_str = malloc(ft_strlen(*param) + 2);
		pos_str[0] = '+';
		ft_strlcpy(pos_str + 1, *param, ft_strlen(*param) + 1);
		free(*param);
		*param = pos_str;
	}
}
