/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:02:09 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/25 15:59:30 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main(void)
{
	printf("ft_printf return : %d\n", ft_printf("%%\\   %c   %d\n", 'S', -42));
	printf("ft_printf return : %d\n", ft_printf("name %s %d\n", "Sid", -42));
}
/*
int	main(void)
{
	int result = printf("Sentence to know how many %s\n", "characers where witten");
	printf("characters where written %d\n", result);
}
*/