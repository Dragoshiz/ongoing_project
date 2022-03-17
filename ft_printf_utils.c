/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:45:50 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/17 14:09:12 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_get_digits(long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
	{
		digits++;
		return (digits);
	}
	while (n != 0)
	{
		if (n < 0)
		{	
			n *= -1;
			digits++;
		}
		n /= 10;
		digits++;
	}
	return (digits);
}

int	ft_putnbr(int n)
{	
	long	ln;
	long	nn;

	ln = (long)n;
	if (ln < 0)
	{
		ft_putchar('-');
		ln *= -1;
	}
	if (ln >= 10)
	{
		nn = ln % 10;
		ln /= 10;
		ft_putnbr(ln);
		ft_putchar(nn + 48);
	}
	ft_putchar(ln + 48);
	return (ft_get_digits(n));
}

int	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
