/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:35 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/23 11:34:48 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_idform(char idf, va_list arguments);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	i = 0;
	count = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_idform(format[i], arguments);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(arguments);
	return (count);
}

static int	ft_idform(char idf, va_list arguments)
{
	if (idf == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	if (idf == 's')
		return (ft_putstr2(va_arg(arguments, char *)));
	if (idf == 'p')
		return (ft_putptr(va_arg(arguments, unsigned long)));
	if (idf == 'd' || idf == 'i')
		return (ft_putnbr2(va_arg(arguments, int)));
	if (idf == 'u')
		return (ft_putnbr_base(va_arg(arguments, unsigned long),
				"0123456789"));
	if (idf == 'x')
		return (ft_putnbr_base(va_arg(arguments, unsigned int),
				"0123456789abcdef"));
	if (idf == 'X')
		return (ft_putnbr_base(va_arg(arguments, unsigned int),
				"0123456789ABCDEF"));
	if (idf == '%')
		return (write(1, &idf, 1));
	return (0);
}
