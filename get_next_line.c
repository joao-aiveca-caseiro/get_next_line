/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:11 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/23 17:40:58 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		readbytes;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	readbytes = read(fd, buff, BUFFER_SIZE);
	if (readbytes <= 0)
	{
		if (str[0] != '\0')
		{
			free(str);
			str = NULL;
		}
	}
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
	if (!str)
		return (NULL);
//	line = malloc(sizeof(char) * (strlen_gnl(str) + 2));
	line = ft_calloc(strlen_gnl(str) + 2, sizeof(char));
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
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
//	newstr = malloc(sizeof(char) * (ft_strlen(str) + 1 - i));
	newstr = ft_calloc((ft_strlen(str) + 1 - i), sizeof(char));
	if (!newstr)
		return (NULL);
	i++;
	while (str[i])
		newstr[j++] = str[i++];
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*nline;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (NULL);
	}
	if (!text)
		text = ft_calloc(1, sizeof(char));
	if (strchr_gnl(text) == 1)
	{
		nline = copy_until_nl(text);
		text = forward_to_nl(text);
		return (nline);
	}
	text = read_line(fd, text);
	nline = copy_until_nl(text);
	text = forward_to_nl(text);
	return (nline);
}

/*int	main(void)
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
}*/
