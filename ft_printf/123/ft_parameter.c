/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:14:03 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/22 20:35:05 by chemelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char			*get_id_parameter(va_list args, t_formats *formats)
{
	if (formats->size[0] == 'h' && formats->size[1] == 'h')
		return (ft_itoa_base((signed char)va_arg(args, int), 10));
	if (formats->size[0] == 'h')
		return (ft_itoa_base((short int)va_arg(args, int), 10));
	if (formats->size[0] == 'l' && formats->size[1] == 'l')
		return (ft_itoa_base(va_arg(args, unsigned long long int), 10));
	if (formats->size[0] == 'l')
		return (ft_itoa_base(va_arg(args, unsigned long int), 10));
	return (ft_itoa_base(va_arg(args, int), 10));
}

char			*get_xbigx_parameter(va_list args, t_formats *formats)
{
	long long	res;

	res = va_arg(args, int);
	formats->set_octotorp = 0;
	if (res == 0 && formats->accuracy[0] == '.' &&
		ft_atoi(formats->accuracy + 1) == 0)
		return (ft_strdup(""));
	if (res == 0)
		return (ft_itoa_base(res, 16));
	formats->set_octotorp = 1;
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
		return (get_id_parameter(args, formats));
	if (in_set(formats->type[0], "xX"))
		return (get_xbigx_parameter(args, formats));
	res = va_arg(args, long long);
	formats->set_octotorp = 0;
	formats->set_octotorp = 1;
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

void			print_formats(t_formats *formats)
{
	ft_putnstr("Formats: ", ft_strlen("Formats: "));
	if (formats)
	{
		ft_putnchar('|', 1);
		ft_putnstr(formats->flag, ft_strlen(formats->flag));
		ft_putnchar('|', 1);
		ft_putnstr(formats->width, ft_strlen(formats->width));
		ft_putnchar('|', 1);
		ft_putnstr(formats->accuracy, ft_strlen(formats->accuracy));
		ft_putnchar('|', 1);
		ft_putnstr(formats->size, ft_strlen(formats->size));
		ft_putnchar('|', 1);
		ft_putnstr(formats->type, ft_strlen(formats->type));
		ft_putnchar('|', 1);
		ft_putnchar('\n', 1);
	}
	else
		ft_putnstr("NULL\n", ft_strlen("NULL\n"));
}
