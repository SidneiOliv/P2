/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:58:47 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/28 17:08:34 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countnum(unsigned int nb);

int	ft_putnbru(unsigned int nb)
{
	int				i;
	unsigned int	n;
	char			num[12];

	n = nb;
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

static int	ft_countnum(unsigned int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 0;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}
