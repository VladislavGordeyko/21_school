/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:16:29 by chemelin          #+#    #+#             */
/*   Updated: 2020/07/27 22:19:03 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void				clear(t_formats **formats)
{
	if (formats && (*formats))
	{
		free((*formats)->flag);
		free((*formats)->width);
		free((*formats)->accuracy);
		free((*formats)->type);
		free(*formats);
		*formats = NULL;
	}
}

void				print_initial_formats(t_formats *formats)
{
	if (formats)
	{
		ft_putnstr(formats->flag, ft_strlen(formats->flag));
		ft_putnstr(formats->width, ft_strlen(formats->width));
		ft_putnstr(formats->accuracy, ft_strlen(formats->accuracy));
		ft_putnstr(formats->type, ft_strlen(formats->type));
	}
	else
		ft_putnstr("NULL\n", ft_strlen("NULL\n"));
}

static void			without_negative_values(t_formats *formats)
{
	char			*flags;

	if (ft_atoi(formats->width) < 0)
	{
		flags = malloc(ft_strlen(formats->flag) + 2);
		ft_memcpy(flags, formats->flag, ft_strlen(formats->flag));
		flags[ft_strlen(formats->flag)] = '-';
		flags[ft_strlen(formats->flag) + 1] = '\0';
		free(formats->flag);
		formats->flag = flags;
		ft_memmove(formats->width, formats->width + 1,
			ft_strlen(formats->width) - 1);
		(formats->width)[ft_strlen(formats->width) - 1] = '\0';
	}
}

void				add_flag(char c, t_formats **formats)
{
	char			*flags;

	if (*formats)
	{
		flags = malloc(1 + ft_strlen((*formats)->flag) + 1);
		flags[0] = c;
		ft_strlcpy(flags + 1, (*formats)->flag,
			ft_strlen((*formats)->flag) + 1);
		free((*formats)->flag);
		(*formats)->flag = flags;
	}
}

void				set_stars(va_list args, t_formats **formats)
{
	char			*itoa;
	int				arg;

	if (!(ft_strcmp((*formats)->width, "*")))
	{
		arg = va_arg(args, int);
		if (arg < 0)
		{
			add_flag('-', formats);
			arg = -arg;
		}
		free((*formats)->width);
		(*formats)->width = ft_itoa_base(arg, 10);
	}
	if (!(ft_strcmp((*formats)->accuracy, ".*")))
	{
		free((*formats)->accuracy);
		itoa = ft_itoa_base(va_arg(args, int), 10);
		(*formats)->accuracy = ft_strjoin(".", itoa);
		free(itoa);
	}
	without_negative_values(*formats);
}
