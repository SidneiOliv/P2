/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:14:57 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/06 19:06:58 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getarc(int fd);
char	*ft_getline(char *txt, char *ptr);

char	*get_next_line(int fd)
{
	static char	*ptr;
	static char	*txt;
//	char		*ptr;
//	char		*line;

	
	if (!txt)
		txt = ft_getarc(fd);
	ptr = &txt;
	ptr = ft_getline(txt, ptr);
	return (ptr);
}

char	*ft_getarc(int fd)
{
	char		*txt;
	char		*rd;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = malloc(BUFFER_SIZE * sizeof(char));
	if (rd == NULL)
		return (NULL);
	i = read (fd, rd, BUFFER_SIZE);
	txt = ft_strdup(rd);
	i = read (fd, rd, BUFFER_SIZE);
	while (i == BUFFER_SIZE)
	{
		temp = ft_strdup(txt);
		free (txt);
		txt = ft_strjoin(temp, rd);
		free (temp);
		i = read (fd, rd, BUFFER_SIZE);
	}
	free (rd);
	return (txt);
}

char	*ft_getline(char *txt, char *ptr)
{
	char	line[] = 40;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (txt[i] && txt[i] != '\n')
	{
		i++;		
	}
	while ( j < i)
	{
		&line[j] = &txt[j];
		j++;
	}
	
	return (line, ptr);
}
/*
{
	static char	*temp;
	char	*rd;
//	char	*temp;
	char	*line;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
write(1, "GNL2\n", 5);
//	if (temp1 == NULL)
//	{
		write(1, "GNL3\n", 5);
		temp = malloc(BUFFER_SIZE * sizeof(char));
		if (temp == NULL)
			return (NULL);
//	}
write(1, "GNL4\n", 5);
	rd = malloc(BUFFER_SIZE * sizeof(char));
	if (rd == NULL)
		return (NULL);

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (line == NULL)
			return (NULL);
	i = read (fd, rd, BUFFER_SIZE);
	ft_strlcpy(line, rd, BUFFER_SIZE + 1);

	while (i == BUFFER_SIZE)
	{
		i = read (fd, rd, BUFFER_SIZE);
		
		while (i < BUFFER_SIZE)
		{
			if (rd[i] == '\0')
			{
				ft_strlcat(line, rd, i + 1);
				free (rd); // ?
				return (line);
			}
			i++;
		}
	//	if (ft_strchr(&temp2, '\0'))

		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (rd[i] == '\n')
			{
				ft_strlcat(line, rd, i + 1);
				ft_strlcpy(temp1, &rd[i + 1], BUFFER_SIZE - i - 1);
				free (rd); // ?
				return (line);
			}
			i++;
	}
	free (temp);
	temp = ft_strjoin(line, rd);
	free (line);
	line = malloc(ft_strlen(temp + BUFFER_SIZE) * sizeof(char));
	if (line == NULL)
		return (NULL);
	}
}
*/
/*

id == BS
rd = read
rd contem \n
	line = rd\n
	mem = \nrd
	return line
line = line + rd
mem = line
free line
line = strlen temp + BS
line = temp
rd = read




line = line + rd

line = temp + rd
return line
*/

/*
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
*/
