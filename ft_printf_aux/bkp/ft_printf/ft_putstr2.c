/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:36:29 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/28 16:38:35 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr2(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		count += write (1, &s[i], 1);
		i++;
	}
	return (count);
}
