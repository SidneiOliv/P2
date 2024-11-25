/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:30:25 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/25 17:23:14 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	int		i;
	long	n;
	char	num[12];

	n = nb;
	nb = 0;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		nb++;
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
		nb++;
	}
	return (nb);
}
