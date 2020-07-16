/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:29:47 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/16 21:56:10 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (dst[i] != '\0')
		i++;
	res = 0;
	while (src[res] != '\0')
		res++;
	if (size <= i)
		res += size;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;

	if (!(s1 && s2))
		return (ft_strdup(""));
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, size + 1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	while (*str != c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return (str);
}
