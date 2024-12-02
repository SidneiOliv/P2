/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:14:57 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/02 17:42:42 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c);

char	*get_next_line(int fd)
{
	
	char	*temp1;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	temp1 = malloc(BUFFER_SIZE * sizeof(char));
	if (temp1 == NULL)
		return (NULL);
	
	read (fd, temp1, BUFFER_SIZE);
	
	if (ft_strchr(temp1, '\n'))
	{	printf("GNL %s", temp1);
		return (temp1);
	}
	if (ft_strchr(temp1, '\0'))
		return (temp1);

	
	
	return (temp1);
}

/*
temp1 = read
temp1 have \n or \0 ?
	line = temp1 \0, free temp1
	line = temp1 \n, temp2 = \n temp1, free temp 1

temp2 = read
temp3 = temp1 + temp2
temp3 have \n or \0 ?
	line = temp3 \0
	line = temp3 \n and temp1 \n temp1

*/
char	*ft_strchr(const char *str, int c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (0);
}