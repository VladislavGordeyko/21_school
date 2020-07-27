/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:45:02 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:45:03 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy_s;

	i = 0;
	copy_s = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (copy_s)
	{
		while (s[i] != '\0')
		{
			copy_s[i] = s[i];
			i++;
		}
		copy_s[i] = '\0';
	}
	return (copy_s);
}
