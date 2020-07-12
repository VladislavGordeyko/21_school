/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:33:16 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/12 20:41:38 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void    check_remainder(char *rem, char **line)
// {
// }

int get_next_line(int fd, char **line)
{
    int res;
    char buf[BUFF_SIZE + 1];
    static char *rem;
    char    *nl_pntr;

    *line = "\0";
    if (rem)
        *line = ft_strjoin(*line, rem);
    while ((res = read(fd, buf, BUFF_SIZE)))
    {
        buf[res] = '\0';
        if ((nl_pntr = ft_strchr(buf, '\n')))
        {
            *nl_pntr = '\0';
            *line = ft_strjoin(*line, buf);
            rem = ft_strdup(++nl_pntr);
            break ;
        }
        *line = ft_strjoin(*line, buf);
    }
    return (0);
}