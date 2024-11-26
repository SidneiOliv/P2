/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:02:09 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/26 17:36:08 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void)
{
	int	a = 10;
	printf(" ft_printf return : %d\n", ft_printf("\nft_printf %%\\ %c %s %p ", 'S', "Sid", &a));
	printf(" ft_printf return : %d\n", ft_printf("second %d %x %X", -42, 1000, 1000));
	printf("    printf return : %d\n",    printf("\n   printf %%\\ %c %s %p ", 'S', "Sid", &a));
	printf("    printf return : %d\n",    printf("second %d %x %X", -42, 1000, 1000));
	printf("\n");
}
