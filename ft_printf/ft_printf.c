/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:35 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/25 17:04:52 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*void	ft_typeident(const char *ident)
{
	ident++;
	if (*ident == 's')
	{
		char	*str;
		str = va_arg(arguments, char *);
		write(1, str, ft_strlen(str));
	}
}*/

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
//			count += ft_idform(va_arg(arguments, int));
			
			if (format[i] == 'c')
				count += ft_putchar(va_arg(arguments, int));
			if (format[i] == 's')
				count += ft_putstr2(va_arg(arguments, char *));
//			if (format[i] == 'p')
//				count += ft_putstr2(va_arg(arguments, char *));
			if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				count += ft_putnbr(va_arg(arguments, int));
//			if (format[i] == 'x')
//				count += ft_putstr2(va_arg(arguments, char *));
//			if (format[i] == 'X')
//				count += ft_putstr2(va_arg(arguments, char *));
			if (format[i] == '%')
				count += write(1, &format[i], 1);

		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(arguments);
	return (count);
}
