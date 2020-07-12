/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:29:47 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/12 16:44:26 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int has_next_line(char *s)
{
    int res;

    res = 0;
	while (s[res])
	{
		if (s[res] == '\n')
			return (res);
		res++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const char *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str;

	if (!dest && !src)
		return (dest);
	i = 0;
	str = (unsigned char*)dest;
	while (i != n)
	{
		str[i] = src[i];
		i++;
	}
	return (dest);
}