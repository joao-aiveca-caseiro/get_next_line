/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:11 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/16 16:38:17 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*print_until_nl(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while ((str[i]) != '\n')
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read(fd, buff, BUFFER_SIZE);
	line = print_until_nl(buff);
	return (line);
}

int	main(void)
{
	int	fd = open("text", O_RDONLY);

	printf("%s", get_next_line(fd));
	close(fd);
}
