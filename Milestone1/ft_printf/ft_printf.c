/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:35 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/21 17:40:52 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	int		i;
	long	n;
	char	num[12];

	n = nb;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	i = 0;
	while (n > 9)
	{
		num[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	num[i] = n + 48;
	while (i >= 0)
	{
		write(1, &num[i], 1);
		i--;
	}
}

void	ft_putstr(char *s)
{
	write (1, s, ft_strlen(s));
}

int ft_printf(const char *format, ...)
{
	va_list	arguments;
	va_start(arguments, format);

	int	i;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_typeident (&format[i]);
		if (format[i] == '\')
			ft_typebar (&format[i]);
	}
/*
	int	i;
	i = 0;
	while (i < ft_strlen(format))
	{
		write(1, &format[i], 1);
		i++;
	}

	char	*str;
	str = va_arg(arguments, char *);
	printf("\nstr : %s\n", str);
	ft_putstr(str);
	write(1, str, ft_strlen(str));

	int n;
	n = va_arg(arguments, int);
	ft_putnbr(n);

	va_end(arguments);

	return (ft_strlen(format) + ft_strlen(str));
*/
}

int main(void)
{
	printf("\nft_printf return : %d\n", ft_printf("name%s ", "Sid ", 42));
}
