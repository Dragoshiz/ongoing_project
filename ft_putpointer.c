/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:31:19 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/28 13:52:24 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count = ft_putstr("0x0");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr);
	return (count);
}

int	ft_puthex(unsigned long p)
{
	char	*repr;
	int		count;

	count = 0;
	repr = "0123456789abcdef";
	if (p == 0)
		return (count);
	if (p >= 16)
		count += ft_puthex(p / 16);
	ft_putchar(repr[p % 16]);
	return (1 + count);
}
