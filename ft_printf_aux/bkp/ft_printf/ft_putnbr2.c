/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:06:36 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/28 15:52:50 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr(long n);

int	ft_putnbr2(int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	return (putnbr(n) + count);
}

static int	putnbr(long n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += putnbr(n / 10);
	if (n <= 9)
		n += 48;
	else
		n = n % 10 + 48;
	count += write(1, &n, 1);
	return (count);
}
