/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:25:58 by sde-oliv          #+#    #+#             */
/*   Updated: 2024/11/28 11:58:52 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr2(int nb);
int		ft_putstr2(char *s);
int		ft_putptr(unsigned long ptr);
int		ft_putnbr_base(unsigned long nbr, char *base);
size_t	ft_strlen(const char *str);

#endif
