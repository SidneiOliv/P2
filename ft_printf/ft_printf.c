/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:35 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/26 17:34:42 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_idform(char idf, va_list arguments);

int ft_printf(const char *format, ...)
{
	va_list	arguments;
	va_start(arguments, format);
	int	i;
	int	count;

	i = 0;
	count = 0;
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

int	ft_idform(char idf, va_list arguments)
{
//	printf("idf : %c ... ", idf);
	if (idf == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	if (idf == 's')
		return (ft_putstr2(va_arg(arguments, char *)));


	if (idf == 'p')
//		count += ft_putstr2(va_arg(arguments, char *));
	{
//		return (printf("%p", va_arg(arguments, char *)));
		int	*adr = va_arg(arguments, int *);
		return (printf("%p", adr));
//		ft_putnbr(adr);
//		int	i = 0;
//		while (adr[i])
//		{
//			write(1, &adr, 12);
//			i++;
//		}
	}

	if (idf == 'd' || idf == 'i' || idf == 'u')  // ?
		return (ft_putnbr(va_arg(arguments, int)));


	if (idf == 'x')
		return (ft_putnbr_base(va_arg(arguments, int), "0123456789abcdef"));
	if (idf == 'X')
		return (ft_putnbr_base(va_arg(arguments, int), "0123456789ABCDEF"));


	if (idf == '%')
		return (write(1, &idf, 1));
	return (0);
}
