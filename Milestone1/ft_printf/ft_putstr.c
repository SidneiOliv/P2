/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:57:07 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/08/14 18:57:16 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
/*
#include <stdio.h>

int main()
{
	char* str10 = "Hello world";

	puts(str10);
	puts("Hello world");
	
	char	str1[] = "Hello world";

	write(1, "\n", 1);
	ft_putstr(str1);

	return 0;
}*/
