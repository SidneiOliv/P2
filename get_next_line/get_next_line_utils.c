/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:15:49 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/12 16:45:00 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(num * size);
	if (ptr == NULL)
		return (0);
	while (i < (num * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

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

char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	len = ft_strlen(str) + 1;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (0);
	if (len > 0)
	{
		while (str[i] != '\0' && i < len - 1)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
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
