/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:29:47 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/15 21:25:47 by letuffle         ###   ########.fr       */
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	while (i != n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
	{
		*(s + i) = '\0';
		i++;
	}
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
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