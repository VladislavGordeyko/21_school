/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:44:09 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/27 23:44:12 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t			set_length(t_formats *formats)
{
	if (isnumbertype(formats->type[0]) && ft_atoi(formats->accuracy + 1) > 0)
		return (ft_atoi(formats->accuracy + 1));
	return (0);
}

char			*set_width(char *param, t_formats *formats)
{
	char		*new_param;
	char		*complement;
	char		*sign;
	size_t		length;

	sign = strfromchr('\0');
	if (param[0] == '-' || param[0] == '+')
		sign[0] = param[0];
	length = set_length(formats);
	if (ft_strlen(param) - ft_strlen(sign) < length)
	{
		length -= ft_strlen(param) - ft_strlen(sign);
		new_param = malloc(length + ft_strlen(param) + 1);
		ft_memcpy(new_param, param, ft_strlen(sign));
		complement = ft_full('0', length);
		ft_memcpy(new_param + ft_strlen(sign), complement, length);
		ft_strlcpy(new_param + ft_strlen(sign) + length,
			param + ft_strlen(sign), ft_strlen(param + ft_strlen(sign)) + 1);
		free(complement);
		free(param);
		param = new_param;
	}
	free(sign);
	return (param);
}
