/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:51:44 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/18 18:14:03 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lo(unsigned int x)
{
	char	*repr_lo;
	int		count;

	count = 0;
	repr_lo = "0123456789abcdef";
	if (x >= 16)
		count += ft_puthex_lo(x / 16);
	ft_putchar(repr_lo[x % 16]);
	return (1 + count);
}

int	ft_puthex_upp(unsigned int xx)
{
	char	*repr_upp;
	int		count;

	count = 0;
	repr_upp = "0123456789ABCDEF";
	if (xx >= 16)
		count += ft_puthex_upp(xx / 16);
	ft_putchar(repr_upp[xx % 16]);
	return (1 + count);
}
