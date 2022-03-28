/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:39:50 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/28 14:19:43 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_specifier(const char specifier, va_list ap)
{
	static int	count;

	if (specifier == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (specifier == 'p')
		count = ft_putpointer(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count = ft_putunsdec(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count = ft_puthex_lo(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		count = ft_puthex_upp(va_arg(ap, unsigned int));
	else if (specifier == '%')
		count = ft_putchar('%');
	else
		return (0);
	return (count);
}

int	ft_printf(const char *arr, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, arr);
	i = 0;
	count = 0;
	while (arr[i])
	{
		if (arr[i] == '%')
		{
			i++;
			count += ft_get_specifier(arr[i], ap);
		}
		else
			count += ft_putchar(arr[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
