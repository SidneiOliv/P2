/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:33:46 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/12 20:43:35 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	nb;
	char	num[12];

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	i = 0;
	while (nb > 9)
	{
		num[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	num[i] = nb + 48;
	while (i >= 0)
	{
		write(fd, &num[i], 1);
		i--;
	}
}
