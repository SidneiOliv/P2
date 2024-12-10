/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:33:42 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/10 16:19:22 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		l;

	l = 6;
	i = 1;
	fd = open("text_test.txt", O_RDONLY);
	write(1, "main\n", 5);
	while (i <= l)
	{
	line = get_next_line(fd);
	printf("main line %d :   %s\n", i, line);
	i++;
	}
	close(fd);
}

/*	line = get_next_line(fd);
	printf("\nmain2\n%s\n", line);
	line = get_next_line(fd);
	printf("\nmain3\n%s\n", line);
	line = get_next_line(fd);
	printf("\nmain4\n%s\n", line);
	line = get_next_line(fd);
	printf("\nmain5\n%s\n", line);
	line = get_next_line(fd);
	printf("\nmain6\n%s\n", line);
	line = get_next_line(fd);
	printf("\nmain7\n%s\n", line);
*/


//	n = 0
//	rd
//	line
//
//	n = read(fd, rd, BUFFER_SIZE);
//	while (n > -1)
//	{
//		line = strjoin(line, rd);
//		if (strchr(line,'\n'));
//		{
//			line = get_line(line);
//			return (line);
//		}
//
//		n = read(fd, rd, BUFFER_SIZE);
//	}