/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:48:54 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:26:15 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_mxint(long sum)
{
	if (sum < -2147483648 || sum > 2147483647)
	{
		ft_err_msg();
		exit(0);
	}
}

void	ft_err_msg(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_isdigit(int ch)
{
	if ((ch >= '0') && (ch <= '9'))
	{
		return (ch);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long		sum;
	int			sign;

	i = 0;
	sum = 0;
	sign = 1;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	ft_check_mxint(sign * sum);
	return (sign * sum);
}

void	ft_put_elem(int size, int *stack)
{
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
}
