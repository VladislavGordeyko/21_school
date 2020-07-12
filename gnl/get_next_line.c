/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:33:16 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/12 16:46:46 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    int res;
    static char *buf;
    size_t BUFFER_SIZE;
    int temp;

    BUFFER_SIZE = 6;
    buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    res = read(fd, buf, BUFFER_SIZE);
    temp = has_next_line(buf);
    if (temp)
    {
        printf("There is 'slash n' in the line\n");
        line = (char*)malloc(sizeof(char) * (temp +1 ));
        ft_memcpy(line, buf, '\n');
        printf("copied line - %s\n", line);
    }
    else
        printf("There isn't 'slash n' in the line!\n");
    return (0);
}