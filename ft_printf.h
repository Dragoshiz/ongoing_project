/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:14:43 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/28 14:54:57 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_get_digits(long n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_putunsdec(unsigned int n);
int		ft_putnbr(int n);
int		ft_putpointer(void *c);
int		ft_puthex_lo(unsigned int x);
int		ft_puthex_upp(unsigned int xx);
int		ft_printf(const char *arr, ...);
int		ft_puthex(unsigned long p);

#endif