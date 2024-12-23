/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:14:57 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/12 14:01:24 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_read(int fd, char *line, char *rd, char *mem);
static void	get_split(char *mem, char *line);
static void	get_split2(char *mem, char *line);

char	*get_next_line(int fd)
{
	static char	*mem = 0;
	char		*line;
	char		*rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!mem)
	{
		mem = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (mem == NULL)
			return (NULL);
	}
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	rd = malloc(BUFFER_SIZE * sizeof(char));
	if (rd == NULL)
		return (NULL);
	if (ft_strchr(mem, '\n'))
		return (get_split2(mem, line), line);
	line = ft_strdup(mem);// strlcpy(line, mem, strlen(mem) + 1);
	line = get_read(fd, line, rd, mem);
	free (rd);
	return (line);
}
//get_split2 o recebe o mem como parametro. vc cria o line la dentro,
	// aloca memoria pra ele, usa ele, e dps da free
// faz o line = strdup(mem) dentro do get_read;

char	*get_read(int fd, char *line, char *rd, char *mem)
{
	int	n;
	
	n = read(fd, rd, BUFFER_SIZE);
	while (n > 0)
	{
		line = ft_strjoin(line, rd);
		if (ft_strchr(line, '\n'))
		{
			get_split(mem, line);
			return (line);
		}
		n = read(fd, rd, BUFFER_SIZE);
	}
	if (n <= 0)
		return (NULL);
	return (line);	
}

void	get_split(char *mem, char *line)
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

void	get_split2(char *mem, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mem[i] != '\n')
	{
		line[i] = mem[i];
		i++;
	}
	line[i] = mem[i];
	i++;
	line[i] = '\0';
	while (mem[i] != '\0')
	{
		mem[j] = mem[i];
		j++;
		i++;
	}
	mem[j] = '\0';
//	return (mem);
}
