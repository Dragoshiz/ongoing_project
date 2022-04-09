/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:57:49 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:58:24 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
