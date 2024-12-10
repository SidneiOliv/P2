/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:15:49 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/06 18:43:02 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
/*
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
*/
char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;

	len = ft_strlen(str) + 1;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (0);
	ft_strlcpy(ptr, str, len);
	return (ptr);
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
