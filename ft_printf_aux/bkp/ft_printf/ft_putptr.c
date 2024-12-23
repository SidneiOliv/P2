/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:44:11 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/12/23 11:36:28 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putptr_base(unsigned long nbr, char *base);

int	ft_putptr(unsigned long ptr)
{
	int		count;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += putptr_base(ptr, "0123456789abcdef");
	return (count);
}

static int	putptr_base(unsigned long nbr, char *base)
{
	unsigned int	valbase;
	int				count;

	valbase = ft_strlen(base);
	count = 0;
	if (nbr > valbase - 1)
		count += putptr_base(nbr / valbase, base);
	count += write(1, &base[nbr % valbase], 1);
	return (count);
}
