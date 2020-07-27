/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:44:05 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:44:15 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	size_t	i;
	int		sign;
	int		value;

	i = 0;
	value = 0;
	sign = 1;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		sign = 44 - s[i];
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		value = value * 10 + (s[i] - '0');
		i++;
	}
	return (sign * value);
}
