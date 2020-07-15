/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:33:16 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/15 21:30:02 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char    *check_remainder(char *rem, char **line)
{
    char    *pntr;
    // char    *temp;

    pntr = NULL;
    if (rem)
        if ((pntr = ft_strchr(rem, '\n')))
        {
            *pntr = '\0';
            *line = ft_strdup(rem);
            // temp = *rem;
            strcpy(rem, ++pntr);
            // *rem = ft_strdup(++pntr);
            // free(temp);
        }
        else
        {
            *line = ft_strdup(rem);
            ft_strclr(rem);
        }
    else
        *line = "\0";
    return (pntr);
}

int get_next_line(int fd, char **line)
{
    static char *rem;
    char        buf[BUFF_SIZE + 1];
    int         res;
    
    char        *nl_pntr;
    // char        *temp;
    // static int  iter = 0;

    // printf("iter # - %d | rem - |%s| \n", iter, rem);
    nl_pntr = check_remainder(rem, line);
    while (!nl_pntr &&(res = read(fd, buf, BUFF_SIZE)))
    {
        buf[res] = '\0';
        if ((nl_pntr = ft_strchr(buf, '\n')))
        {
            *nl_pntr = '\0';
            rem = ft_strdup(++nl_pntr);
        }
        // if (*line)
        // temp = *line;
        *line = ft_strjoin(*line, buf);
        // if (temp)
        // free(temp);
    }
    // iter++;
    return(res || ft_strlen(rem) || ft_strlen(*line) ? 1 : 0);
    // if (res == 0)
    //     return (0);
    // else
    //     return (1);
}