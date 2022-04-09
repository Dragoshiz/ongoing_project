/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:48:54 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:03:28 by dimbrea          ###   ########.fr       */
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

void	ft_remv_elem(int size, int *stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	ft_free(t_counter *i, int *a_stack, int *b_stack)
{
	free(i->idx_st);
	free(i->tmp_st);
	free(a_stack);
	free(b_stack);
}

void	ft_sort(t_counter *i, int *a_stack, int *b_stack)
{
	if (i->count_a <= 3)
	{
		ft_sort3(i, a_stack);
		return ;
	}
	else if (i->count_a <= 5)
	{
		ft_sort5(i, a_stack, b_stack);
		return ;
	}
	else
		ft_radix(i, a_stack, b_stack);
	return ;
}

void	ft_initialize(t_counter *i, int argc)
{
	i->argc = argc;
	i->count_a = argc - 1;
	i->count_b = 0;
	i->count_index = argc - 1;
	i->count_temp = 0;
	i->tmp_st = malloc(sizeof(int) * (argc));
}