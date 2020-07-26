/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:30:16 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/20 19:01:28 by chemelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void			ft_putnchar(char c, size_t n)
{
	size_t		i;

	i = 0;
	while (++i <= n)
		write(1, &c, 1);
}

int				ft_putnstr(char *str, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		ft_putnchar(str[i], 1);
		i++;
	}
	return (i);
}

char			*strfromchr(char c)
{
	char		*str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

int				in_set(char c, char *set)
{
	int			i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char			*ft_cpytillforbidden(char *str, char *set)
{
	int			i;

	i = 0;
	while (str[i])
		if ((i == 0 && str[i] == set[i]) || in_set(str[i], set))
			i++;
		else
			break ;
	return (ft_substr(str, 0, i));
}
