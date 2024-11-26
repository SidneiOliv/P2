/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:30:25 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/26 14:20:43 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_countnum(int nb)
{
	int		i;
	long	n;
	char	num[12];

	n = nb;
	nb = 0;
	if (n < 0)
	{
		n *= -1;
		nb++;
	}
	i = 0;
	while (n > 9)
	{
		num[i] = (n % 10) + 48;
		n = n / 10;
		i++;
		nb++;
	}
	nb++;
	return (nb);
}

int	ft_putnbr(int nb)
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
	return (ft_countnum(nb));
}
