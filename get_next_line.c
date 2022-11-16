/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:14:11 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/11/16 02:40:02 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

//// apagar antes de submeter//////
#include <stdio.h>
#include <fcntl.h>


int	get_next_line(int fd)
{
	char	buff[100];
	int	result;

	result = read(fd, buff, 10);
	return (result);
}



int	main(void)
{
	int	fd = open("text", O_RDONLY);
	int nbytes = get_next_line(fd);

	printf("%i", nbytes);
	close(fd);
}
