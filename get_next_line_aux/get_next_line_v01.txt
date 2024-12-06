
 Repeated calls (e.g., using a loop) 
 to your get_next_line() function 
 should let you read 
 the text file pointed to by 
 the file descriptor, 
 one line at a time.
 Your function should return the line that was read.
 If there is nothing else to read or if an error occurred, it should return NULL.
 Make sure that your function works as expected both when reading a file and when reading from the standard input.
 Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
 Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
 Add all the helper functions you need in the get_next_line_utils.c file.



#include "get_next_line.h"

//char	ft_line(char *temp2);
//char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

char	*get_next_line(int fd)
{
	static char	*temp1;
	char	*temp2;
	char	*temp3;
	char	*line;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
write(1, "GNL2\n", 5);
	if (temp1 == NULL)
	{
		write(1, "GNL3\n", 5);
		temp1 = malloc(BUFFER_SIZE * sizeof(char));
		if (temp1 == NULL)
			return (NULL);
		temp1[0] = '\0';
	}
write(1, "GNL4\n", 5);
	temp2 = malloc(BUFFER_SIZE * sizeof(char));
	if (temp2 == NULL)
		return (NULL);

	line = malloc(2 * BUFFER_SIZE * sizeof(char));
		if (line == NULL)
			return (NULL);

	ft_strlcpy(line, temp1, BUFFER_SIZE);

	while (1)
	{
		read (fd, temp2, BUFFER_SIZE);
		
		while (i < BUFFER_SIZE)
		{
			if (temp2[i] == '\0')
			{
				ft_strlcat(line, temp2, i + 1);
				free (temp2); // ?
				return (line);
			}
			i++;
		}
	//	if (ft_strchr(&temp2, '\0'))

		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (temp2[i] == '\n')
			{
				ft_strlcat(line, temp2, i + 1);
				ft_strlcpy(temp1, &temp2[i + 1], BUFFER_SIZE - i - 1);
				free (temp2); // ?
				return (line);
			}
			i++;
	}
	free (temp3);
	temp3 = ft_strjoin(line, temp2);
	free (line);
	line = malloc(ft_strlen(temp3 + BUFFER_SIZE) * sizeof(char));
	if (line == NULL)
		return (NULL);
	}
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	id;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	id = len_dst;
	ft_strlcpy(&dst[id], src, size - len_dst);
	return (len_dst + len_src);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*subs;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	subs = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (subs == NULL)
		return (0);
	while (s1[i1])
	{
		subs[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2])
	{
		subs[i1] = s2[i2];
		i1++;
		i2++;
	}
	subs[i1] = '\0';
	return (subs);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
