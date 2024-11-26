/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:17:15 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/26 17:29:32 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base(int nbr, char *base)
{
		long	n;
		int		count;
		int		valbase;

		n = nbr;
		count = 0;
		valbase = strlen(base);
//		printf("valbase %d", valbase);
		if (n < 0)
		{
			n = -n;
			write(1, "-", 1);
			count++;
		}
		if (n > valbase)
		{
			ft_putnbr_base(n / valbase, base);
//			count++;
		}
		write(1, &base[n % valbase], 1);
		count++;
//		printf("  count %d ", count);
	return (count);
}
