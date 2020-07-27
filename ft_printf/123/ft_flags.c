/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:21:40 by chemelin          #+#    #+#             */
/*   Updated: 2020/07/27 23:30:49 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char			*flag(char *str, t_formats *formats)
{
	if (str[0] == '-' || str[0] == '0')
	{
		formats->flag = ft_cpytillforbidden(str, "-0");
		return (str + ft_strlen(formats->flag));
	}
	formats->flag = strfromchr('\0');
	return (str);
}

char			*width(char *str, t_formats *formats)
{
	if (str[0] == '*')
	{
		formats->width = strfromchr(str[0]);
		return (str + 1);
	}
	if (str[0] == '-' || (str[0] >= '0' && str[0] <= '9'))
	{
		formats->width = ft_cpytillforbidden(str, "-0123456789");
		return (str + ft_strlen(formats->width));
	}
	formats->width = strfromchr('\0');
	return (str);
}

char			*accuracy(char *str, t_formats *formats)
{
	if (str[0] == '.')
	{
		if (str[1] == '*')
		{
			formats->accuracy = malloc(3);
			formats->accuracy[0] = '.';
			formats->accuracy[1] = '*';
			formats->accuracy[2] = '\0';
			return (str + 2);
		}
		if (str[1] == '-' || (str[1] >= '0' && str[1] <= '9'))
		{
			formats->accuracy = ft_cpytillforbidden(str, ".-0123456789");
			return (str + ft_strlen(formats->accuracy));
		}
		formats->accuracy = strfromchr('.');
		return (str + 1);
	}
	formats->accuracy = strfromchr('\0');
	return (str);
}

char			*type(char *str, t_formats *formats)
{
	if (in_set(*str, "cspdiuxX%"))
	{
		formats->type = strfromchr(*str);
		return (str + 1);
	}
	formats->type = strfromchr('\0');
	return (str);
}
