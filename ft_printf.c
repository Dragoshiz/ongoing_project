/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:39:50 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/17 17:43:06 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_count_specifiers(const char *arr)
// {
// 	int		i;
// 	int		j;
// 	char	*specifiers;
// 	int		count;

// 	specifiers = "cspdiuxX";
// 	count = 0;
// 	i = 0;
// 	while (arr[i++])
// 	{
// 		if (arr[i] == '%' && arr[i + 1] == '%')
// 			i = i + 2;
// 		if (arr[i] == '%')
// 		{
// 			i++;
// 			j = 0;
// 			while (specifiers[j++])
// 				if (specifiers[j] == arr[i])
// 					count++;
// 			j = 0;
// 		}
// 	}
// 	return (count);
// }

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
			i++;
		}
		count += ft_putchar(arr[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	ft_get_specifier(const char specifier, va_list ap)
{
	int	count;

	if (specifier == 'c')
		count = ft_putchar(va_arg(ap, int));
	if (specifier == 's')
		count = ft_putstr(va_arg(ap, char *));
	if (specifier == 'p')
		count = ft_putpointer(va_arg(ap, void *));
	if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr(va_arg(ap, int));
	printf("%d", count);
	if (specifier == 'u')
		count = ft_putnbr(va_arg(ap, unsigned int));
	if (specifier == 'x')
		count = ft_puthex_lo(va_arg(ap, unsigned int));
	if (specifier == 'X')
		count = ft_puthex_upp(va_arg(ap, unsigned int));
	else
		return (0);
	return (count);
}

int main(void)
{
	int num = 0;
	char c = 'p';
	char *p = &c;
	char *hi = "helloo%%%X%d%s%p%x";
	// ft_printf(hi, 20);
	//  num = ft_putstr(hi);
	// printf("++++++%d++++++", printf("%%X", 3000000));
	printf("original num%d", printf("%d", -100000));
	// ft_printf("hello%d\n", 1234567);
	printf("\n_____mynum%d____\n", ft_putnbr(-100000));
	// ft_printf("hello%d\n", 1234567)
	// printf("myyyy%x\n", ft_puthex_lo(3000000));
	return (0);
}
