/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:33:16 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/14 21:24:30 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *check_remainder(char **rem, char **line)
{
    char    *pntr;
    char    *temp;

    pntr = NULL;
    if (*rem)
    {  
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
            str_clr(*rem);
        }
    }
    else
        *line = "\0";
    return (pntr);
}

int get_next_line(int fd, char **line)
{
    int res;
    char buf[BUFF_SIZE + 1];
    static char *rem;
    char    *nl_pntr;
    char    *temp;

    // printf("iter # - %d | rem - |%s| \n", iter, rem);
    nl_pntr = check_remainder(&rem, line);
    while (!nl_pntr &&(res = read(fd, buf, BUFF_SIZE)))
    {
        buf[res] = '\0';
        if ((nl_pntr = ft_strchr(buf, '\n')))
        {
            *nl_pntr = '\0';
            *line = ft_strjoin(*line, buf);
            rem = ft_strdup(++nl_pntr);
        }
        temp = *line;
        *line = ft_strjoin(*line, buf);
        free(temp);
    }
    return (0);
}