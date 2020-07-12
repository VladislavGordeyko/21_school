/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:29:22 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/12 16:38:18 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
// temporary
#include <stdio.h>

int get_next_line(int fd, char **line);
int has_next_line(char *s);

#endif