/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:25:58 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/26 16:34:21 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
#include <stdarg.h>
# include <stdio.h>
//# include <stdlib.h>
# include <string.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr2(char *s);
size_t	ft_strlen(const char *str);
int 	ft_putnbr_base(int nbr, char *base);

#endif
