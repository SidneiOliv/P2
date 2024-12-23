/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:17:15 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/28 17:12:05 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	valbase;
	int				count;

	valbase = ft_strlen(base);
	count = 0;
	if (nbr > valbase - 1)
		count += ft_putnbr_base(nbr / valbase, base);
	count += write(1, &base[nbr % valbase], 1);
	return (count);
}
