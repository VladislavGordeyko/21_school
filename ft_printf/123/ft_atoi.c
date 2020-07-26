/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:52:00 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/19 15:06:53 by chemelin         ###   ########.fr       */
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
