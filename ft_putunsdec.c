/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:00:20 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/17 15:10:57 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsdec(unsigned int u)
{	
	long	ln;
	long	nn;

	ln = (long)u;
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
	return (ft_get_digits(u));
}
