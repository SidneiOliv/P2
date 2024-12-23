/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:05:08 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/28 17:31:28 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
//# include <stdio.h>
//# include <string.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr2(int nb);
int		ft_putstr2(char *s);
int		ft_putptr(unsigned long ptr);
int		ft_putnbr_base(unsigned int nbr, char *base);
size_t	ft_strlen(const char *str);

#endif
