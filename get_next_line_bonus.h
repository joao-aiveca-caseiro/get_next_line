/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:52:53 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/24 16:56:02 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_buffer(int fd, char *str);
char	*copy_until_nl(char *str);
char	*trim_printed(char *str);
size_t	ft_strlen(const char *str);
int		strchr_gnl(const char *str);
char	*strjoin_gnl(char *s1, char *s2);
void	*ft_calloc(size_t nitems, size_t size);

#endif