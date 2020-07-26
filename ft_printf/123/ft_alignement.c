/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 18:20:17 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/22 20:31:52 by chemelin         ###   ########.fr       */
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

static void		set_octotorp(char **param, t_formats *formats)
{
	char		*new_param;

	if (formats->flag[0] == '#' && formats->set_octotorp == 1 &&
		(formats->type[0] == 'x' || formats->type[0] == 'X'))
	{
		if (!(new_param = malloc(ft_strlen(*param) + 3)))
			return ;
		new_param[0] = '0';
		if (formats->type[0] == 'x' || formats->type[0] == 'X')
			new_param[1] = formats->type[0];
		ft_strlcpy(new_param + 2, *param, ft_strlen(*param) + 1);
		free(*param);
		*param = new_param;
	}
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
	set_octotorp(&param, formats);
	free(sign);
	return (param);
}
