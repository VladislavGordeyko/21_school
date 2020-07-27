/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:44:57 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:44:59 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long long			size_allocation(long long n, int base)
{
	long long				count;

	count = 0;
	while (n > base - 1)
	{
		count++;
		n = n / base;
	}
	return (count + 1);
}

static char					*ft_itoa_positive(char *str,
												long long sign,
												long long n, int base)
{
	long long				i;
	long long				size;
	char					*base_numbers;

	size = size_allocation(n, base);
	base_numbers = "0123456789abcdef";
	i = size - 1 + sign;
	while (1)
	{
		str[i] = base_numbers[n % base];
		n = n / base;
		if (n == 0)
			break ;
		i--;
	}
	str[size + sign] = '\0';
	return (str);
}

char						*ft_itoa_base(long long n, int base)
{
	char					*str;
	long long				sign;

	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	str = (char *)malloc(sizeof(char) * size_allocation(n, base) + sign + 1);
	if (str)
	{
		if (sign == 1)
			str[0] = '-';
		return (ft_itoa_positive(str, sign, n, base));
	}
	return (NULL);
}

char						*ft_upperstr(char *str)
{
	size_t					i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int							ft_strcmp(const char *s1, const char *s2)
{
	size_t					i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
