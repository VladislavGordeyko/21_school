/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:33:16 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/19 17:19:54 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	clear_string(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	join_and_free(char **line, char *buf)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, buf);
	free(temp);
}

char	*check_remainder(char **rem, char **line)
{
	char	*pntr;
	char	*temp;

	pntr = NULL;
	if (*rem)
		if ((pntr = ft_strchr(*rem, '\n')))
		{
			*pntr = '\0';
			*line = ft_strdup(*rem);
			temp = *rem;
			*rem = ft_strdup(++pntr);
			free(temp);
		}
		else
		{
			*line = ft_strdup(*rem);
			clear_string(&(*rem));
		}
	else
		*line = ft_strdup("");
	return (pntr);
}

int		get_next_line(int fd, char **line)
{
	static char	*rem;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		res;
	char		*nl_pntr;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, buf, 0)) < 0)
		return (-1);
	nl_pntr = check_remainder(&rem, line);
	while (!nl_pntr && (res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		if ((nl_pntr = ft_strchr(buf, '\n')))
		{
			*nl_pntr = '\0';
			temp = rem;
			rem = ft_strdup(++nl_pntr);
			free(temp);
		}
		join_and_free(line, buf);
	}
	if (res > 0 || nl_pntr)
		return (1);
	clear_string(&rem);
	return (res);
}
