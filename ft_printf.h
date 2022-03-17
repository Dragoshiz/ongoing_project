/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:14:43 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/17 15:45:54 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_get_specifier(const char specifier, va_list ap);
int		ft_get_digits(long n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);
int		ft_putpointer(void *c);
int		ft_puthex(uintptr_t p);
int		ft_puthex_lo(unsigned int x);
int		ft_puthex_upp(unsigned int xx);

#endif