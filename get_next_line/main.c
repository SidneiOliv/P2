/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:33:42 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/12 19:30:32 by sde-oliv         ###   ########.fr       */
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

	i = 0;
	fd = open("text_test.txt", O_RDONLY);
//	printf("fd %d\n", fd);
	line = get_next_line(fd);
/*	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
*/
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
