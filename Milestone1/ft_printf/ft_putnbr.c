/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:30:25 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/08/17 14:49:44 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
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
}
/*
#include <stdio.h>

int	main(void)
{
	// 2³¹ -2,147,483,648 to 2147483647 

	int	number1 = 12;
	printf ("\nprintf number1: %d\n", number1);
	write(1, "putnbr write  : ", 15);
	ft_putnbr(number1);
	
	int	number2 = 29;
	printf ("\n\nprintf number2: %d\n", number2);
	write(1, "putnbr write  : ", 15);
	ft_putnbr(number2);
	
	int	number3 = 2147483647;
	printf ("\n\nprintf number3: %d\n", number3);
	write(1, "putnbr write  : ", 15);
	ft_putnbr(number3);
	
	int	number4 = -2147483648;
	printf ("\n\nprintf number4: %d\n", number4);
	write(1, "putnbr write  : ", 15);
	ft_putnbr(number4);
}*/
