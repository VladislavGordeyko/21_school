/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 08:10:04 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/08 16:51:18 by chemelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	if (size < len)
		len = size;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		while (s[i + start] && i < len)
		{
			str[i] = s[i + start];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
