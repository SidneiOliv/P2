/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:33:42 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/02 17:11:34 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text_test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("main1 %s\n", line);
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
