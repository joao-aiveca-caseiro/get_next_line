/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:11 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/22 02:39:23 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_nl(int fd, char *str)
{
	char	*buff;
	int		readbytes;
	
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readbytes = read(fd, buff, BUFFER_SIZE);
	while (readbytes > 0)
	{
		str = strjoin_gnl(str, buff);
		if (strchr_gnl(str) == 1)
			break ;
		readbytes = read(fd, buff, BUFFER_SIZE);
		buff[readbytes] = '\0';
	}
	free(buff);
	return (str);
}

char	*copy_until_nl(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * (strlen_gnl(str) + 2));
	if (!line)
		return (NULL);
	while (i < strlen_gnl(str) + 1)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*forward_to_nl(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	newstr = malloc(sizeof(char) * (ft_strlen(str) + 1 - i));
	if (!newstr)
		return (NULL);
	i++;
	while (str[i])
	{
		newstr[j] = str[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*nline;

	if (!text)
		text = malloc(sizeof(char) * 1);
	text = read_until_nl(fd, text);
	nline = copy_until_nl(text);
	text = forward_to_nl(text);
	return (nline);
}

int main(void)
{
	int fd = open("text", O_RDONLY);
	char	*s;
	
	s = get_next_line(fd);
	printf("Line 1:\n%s", s);
	free(s);
	s = get_next_line(fd);
	printf("Line 2:\n%s", s);
	free(s);
	// s = get_next_line(fd);
	// printf("Line 3:\n%s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	close(fd);
}
