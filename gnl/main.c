/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:50:07 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/15 21:16:57 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "get_next_line.h"

int main()
{
    int fd;
    char *line;
    int i;

    fd = open("mix_marge2", O_RDONLY);

    // char buf[BUFF_SIZE + 1];
    // int res;

    // res = read(fd, buf, BUFF_SIZE);
    // printf("res - %d, buf - %s\n", res, buf);

    // res = read(fd, buf, BUFF_SIZE);
    // printf("res - %d, buf - %s\n", res, buf);

    // res = read(fd, buf, BUFF_SIZE);
    // printf("res - %d, buf - %s\n", res, buf);

    // res = read(fd, buf, BUFF_SIZE);
    // printf("res - %d, buf - %s\n", res, buf);


    // for (int i = 0; i <= 19; i++)
    // {
    //     get_next_line(fd, &line);
    //     printf("%s\n\n", line);
    //     free(line);
    // }

    // get_next_line(fd, &line);
    // printf("%s\n", line);
    // free(line);


    // printf("%s\n", line);

    // get_next_line(fd, &line);
    // printf("%s\n", line);

    // get_next_line(fd, &line);
    // printf("%s\n", line);

    // get_next_line(fd, &line);

    // int res;
    // static char *buf;
    // size_t BUFFER_SIZE = 18;

    // buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    // res = read(fd, buf, BUFFER_SIZE);

    // printf("res - %d\n", res);
    // printf("buf - %s\n", buf);



    i = 0;
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        free(line);
        i++;
    }
    // printf("i = %d %s\n", i, line);
    //     free(line);
    return (0);
}