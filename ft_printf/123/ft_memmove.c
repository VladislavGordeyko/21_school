/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:44:29 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:44:30 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_fwd(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || (dest == NULL && src == NULL))
		return (dest);
	i = 0;
	while (i < n && dest + i != src)
		i++;
	if (i < n)
		dest = ft_memmove_fwd(dest, src, n);
	else
	{
		i = n - 1;
		while (1)
		{
			((char*)dest)[i] = ((char*)src)[i];
			if (i == 0)
				break ;
			i--;
		}
	}
	return (dest);
}
