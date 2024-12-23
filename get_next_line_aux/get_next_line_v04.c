/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:14:57 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/19 18:59:23 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_read(int fd, char *mem);
static char	*get_split1(char *mem);
static void	get_split2(char *line, char *mem);
//char	*get_line(char *mem);
//void	get_mem(char *mem);
//char	*get_end(char *mem);

char	*get_next_line(int fd)
{
	static char	*mem = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!mem)
	{
		mem = ft_calloc((BUFFER_SIZE), sizeof(char));
		if (mem == NULL)
			return (NULL);
	}
	if (ft_strchr(mem, '\n'))
		return (get_split1(mem));
	line = get_read(fd, mem);
	if (!line)
		return (NULL);
//	if (ft_strchr(line, '\0'))
//	{
//		line = get_end(line);
//		return (line);
//	}
	if (ft_strchr(line, '\n'))
	{
		get_split2(line, mem);
		return (line);
	}
	return (line);
}

static char	*get_read(int fd, char *mem)
{
	char	*temp;
	char	*rd;
	char	*line;
	int		n;
	int		i;

	temp = ft_strdup(mem);
	i = 0;
//	while (i < BUFFER_SIZE - 1)
//		mem[i++] = '\0';
	rd = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (rd == NULL)
		return (NULL);
	rd[BUFFER_SIZE] = '\0';
	n = read(fd, rd, BUFFER_SIZE);
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		line = ft_strjoin(temp, rd);
		free(temp);
		if (ft_strchr(line, '\n'))
			return (free(rd), line);
		temp = ft_strdup(line);
		free(line);
		i = 0;
		while (i < BUFFER_SIZE - 1)
			rd[i++] = '\0';
		n = read(fd, rd, BUFFER_SIZE);
	}
	if (n == -1)
		return (free(temp), free(rd), NULL);
	return (free(rd), temp);
}

static char	*get_split1(char *mem)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mem[i++] != '\n')
	line = ft_calloc((i + 1), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (mem[i] != '\n')
	{
		line[i] = mem[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	while (mem[i + j] != '\0')
	{
		mem[j] = mem[i + j];
		j++;
	}
	mem[j] = '\0';
	return (line);
}

static void	get_split2(char *line, char *mem)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	i++;
	while (line[i] != '\0')
	{
		mem[j] = line[i];
		j++;
		i++;
	}
	mem[j] = '\0';
	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	line[i] = '\0';
}

/*
char	*get_line(char *mem)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
//	temp = ft_strdup(line);
//	free(line);
	while (mem[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (mem[i] != '\n')
	{
		line[i] = mem[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = '\0';
//	get_mem(temp, mem);
	return (line);
}

void	get_mem(char *mem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mem[i] != '\n')
		i++;
	i++;
	while (mem)
	{
		mem[j] = mem[i + j];
		j++;
	}
	mem[j] = '\0';
}

char	*get_end(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] != '\0')
		i++;
	temp = malloc((i + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
*/