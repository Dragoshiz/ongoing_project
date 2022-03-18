/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:00:20 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/18 17:26:52 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsdec(unsigned int n)
{	
	unsigned int	modulednum;
	int				digits;

	digits = ft_get_digits(n);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		modulednum = n % 10;
		n /= 10;
		ft_putnbr(n);
		ft_putchar(modulednum + 48);
		return (digits);
	}
	ft_putchar(n + 48);
	return (digits);
}
