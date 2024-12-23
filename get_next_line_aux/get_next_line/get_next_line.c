/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:14:57 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/23 20:29:10 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_read(int fd, char *mem);
static char	*get_line(char *mem);
static char	*get_mem(char *mem);
//static char	*get_split1(char *mem);
//static void	get_split2(char *line, char *mem);
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
		mem = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (mem == NULL)
			return (NULL);
	}
	mem = get_read(fd, mem);
//	printf("  gnl1 mem %s\n", mem);
	if (mem[0] == '\0')
		return (free(mem), NULL);
	if (!mem)
		return (NULL);
	line = get_line(mem);
//	printf("  gnl2 line %s\n", line);
	if (!line)
		return (NULL);
	mem = get_mem(mem);
//	printf("  gnl3 mem %s\n", mem);
	return (line);
}

static char	*get_read(int fd, char *mem)
{
	char	*rd;
	int		nbf;
	int		i;

	rd = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (rd == NULL)
		return (NULL);
	nbf = 1;
	while (nbf > 0 && !(ft_strchr(mem, '\n')))
	{
		nbf = read(fd, rd, BUFFER_SIZE);
		if (nbf == -1)
			return (free(rd), free(mem), NULL);
		if (nbf == 0)
			return (free(rd), mem);
		rd[BUFFER_SIZE] = '\0';
		mem = ft_strjoin(mem, rd);
		i = 0;
		while (i < BUFFER_SIZE)
			rd[i++] = '\0';
	}
	return (free(rd), mem);
}

static char	*get_line(char *mem)
{
	char	*line;
	int		i;

	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
	{
		line[i] = mem[i];
		i++;
	}
	if (mem[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_mem(char *mem)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	j = i;
	while (mem[i] != '\0')
		i++;
	new = ft_calloc((i - j + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	if (mem[i] == '\n')
		i++;
	j = 0;
	while (mem[i] != '\0')
		new[j++] = mem[i++];
	new[j] = '\0';
	free (mem);
	return (new);
}

/*
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
*/
/*
static char	*get_split1(char *mem)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mem[i++] != '\n')
	line = ft_calloc((i + 2), sizeof(char));
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
*/
/*
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
*/
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