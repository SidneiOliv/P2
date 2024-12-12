/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:14:57 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/12 19:57:13 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_read(int fd, char *rd, char *mem);
static void	get_split(char *mem, char *line);
static char	*get_split2(char *mem);

char	*get_next_line(int fd)
{
	static char	*mem = 0;
	char		*rd;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!mem)
	{
		mem = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (mem == NULL)
			return (NULL);
	}
	rd = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (rd == NULL)
		return (NULL);
	if (ft_strchr(mem, '\n'))
		return (free(rd), get_split2(mem));
	line = get_read(fd, rd, mem);
	free (rd);
	return (line);
}

static char	*get_read(int fd, char *rd, char *mem)
{
	char	*temp;
	char	*line;
	int		n;

	temp = ft_strdup(mem);
	n = read(fd, rd, BUFFER_SIZE);
	printf("n %d", n);
	while (n > 0)
	{
		line = ft_strjoin(temp, rd);
		free (temp);
		if (ft_strchr(line, '\n'))
		{
			get_split(mem, line);
			return (line);
		}
		temp = ft_strdup(line);
		free (line);
		n = read(fd, rd, BUFFER_SIZE);
	}
	if (n < 0)
		return (free(mem), free(temp), NULL);
	return (temp);
	/*if (n == 0)
		return (temp);
	return(NULL);*/
}

static void	get_split(char *mem, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	while (line[i] != '\0')
	{
		i++;
		mem[j] = line[i];
		j++;
	}
	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	line[i] = '\0';
}

static char	*get_split2(char *mem)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (line == NULL)
		return (NULL);
	while (mem[i] != '\n')
	{
		line[i] = mem[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = '\0';
	while (mem[i + j] != '\0')
	{
		mem[j] = mem[i + j];
		j++;
	}
	mem[j] = '\0';
	return (line);
}
