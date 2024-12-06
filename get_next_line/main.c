/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:33:42 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/06 18:37:56 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text_test.txt", O_RDONLY);
	write(1, "main\n", 5);
	line = get_next_line(fd);
	printf("\nmain1\n%s\n", line);
	line = get_next_line(fd);
	printf("\nmain2\n%s\n", line);
/*
	//while (line != NULL)
	int	i = 0;
	while (i < 4)
	{
		printf("%d%s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
*/
	close(fd);
}
