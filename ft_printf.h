/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:14:43 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/18 17:11:04 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_get_digits(long n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_putunsdec(unsigned int n);
int		ft_putnbr(int n);
int		ft_putpointer(void *c);
int		ft_puthex(uintptr_t p);
int		ft_puthex_lo(unsigned int x);
int		ft_puthex_upp(unsigned int xx);

#endif