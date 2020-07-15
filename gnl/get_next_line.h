/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letuffle <letuffle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:29:22 by letuffle          #+#    #+#             */
/*   Updated: 2020/07/15 21:25:52 by letuffle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
// temporary
# include <stdio.h>
#ifndef BUFF_SIZE
# define BUFF_SIZE 32
#endif

int get_next_line(int fd, char **line);
int has_next_line(char *s);
void	*ft_memcpy(void *dest, const char *src, unsigned int n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strnew(size_t size);

#endif