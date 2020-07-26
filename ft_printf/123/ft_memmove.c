/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 07:46:53 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/07 12:05:25 by chemelin         ###   ########.fr       */
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
