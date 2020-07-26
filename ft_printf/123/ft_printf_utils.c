/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:12:18 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/20 18:42:43 by chemelin         ###   ########.fr       */
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
