/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:26:48 by chemelin          #+#    #+#             */
/*   Updated: 2020/07/27 22:44:36 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			*ft_memccpy_m(void *dest, void *src, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
		{
			((unsigned char*)dest)[i] = '\0';
			break ;
		}
		i++;
	}
	if (i < n)
		return (src + i + 1);
	return (NULL);
}

char			*set_nullstr(va_list args, t_formats *formats)
{
	char		*str;
	int			accuracy;

	str = va_arg(args, char*);
	if (!str)
	{
		str = ft_strdup("(null)");
		if (formats->accuracy[0] == '.')
		{
			accuracy = ft_atoi(formats->accuracy + 1);
			if (accuracy >= 0 && accuracy <= 6)
				str[accuracy] = '\0';
		}
		return (str);
	}
	return (ft_strdup(str));
}

char			*ft_full(char c, size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	str = malloc(size + 1);
	if (str)
	{
		while (i < size)
		{
			str[i] = c;
			i++;
		}
		str[size] = '\0';
	}
	return (str);
}

int				ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int				isnumbertype(char c)
{
	if (c == 'd' || c == 'u' || c == 'i' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
