/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 07:46:53 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/19 15:05:12 by chemelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - ' ');
	return (ch);
}