/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 07:46:53 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/08 17:14:36 by chemelin         ###   ########.fr       */
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
