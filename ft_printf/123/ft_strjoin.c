/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:45:08 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:45:09 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*str;
	unsigned int	len_s1;
	unsigned int	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str)
	{
		while (i < len_s1 + len_s2)
		{
			if (i < len_s1)
				str[i] = s1[i];
			else
				str[i] = s2[i - len_s1];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
