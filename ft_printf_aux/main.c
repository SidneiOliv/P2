/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:02:09 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/28 17:04:50 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = 10;
	ret = ft_printf("\nft_printf %%\\ %c %s %p", 'S', "Sid", &ret);
	printf("           ft_printf return : %d\n", ret);
	ret = ft_printf("second %d %i %u %x %X", -42, -42, -42, -1000, -100000);
	printf(" ft_printf return : %d\n", ret);

	ret =    printf("\n---printf %%\\ %c %s %p", 'S', "Sid", &ret);
	printf("           ---printf return : %d\n", ret);
	ret =    printf("second %d %i %u %x %X", -42, -42, -42, -1000, -100000);
	printf(" ---printf return : %d\n", ret);
	printf("\n");

/*
//	printf("ret:%d \n", ft_printf(" NULL %s NULL ", NULL));
//	printf("ret:%d \n", printf(" NULL %s NULL ", (void *)0));

	printf("\n");
	ft_printf("22 %u ", INT_MAX);
	ft_printf("23 %u \n", INT_MIN);
	printf(" ret:%d \n", ft_printf("24 %u ", LONG_MAX));
	ft_printf("25 %u \n", LONG_MIN);
	ft_printf("26 %u \n", UINT_MAX);
	ft_printf("27 %u ", ULONG_MAX);
	ft_printf("28 %u ", 9223372036854775807LL);
	printf(" ret:%d \n", ft_printf("29 %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	
	printf("\n\n");

	printf("22 %u ", INT_MAX);
	printf("23 %u \n", INT_MIN);
	printf(" ret:%d \n", printf("24 %lu ", LONG_MAX));
	printf("25 %lu \n", LONG_MIN);
	printf("26 %u \n", UINT_MAX);
	printf("27 %lu ", ULONG_MAX);
	printf("28 %llu ", 9223372036854775807LL);
	printf(" ret:%d \n", printf("29 %u %u %lu %lu %lu %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
*/
}

