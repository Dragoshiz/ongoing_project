/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:37:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/10 18:01:45 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_sorted(t_counter *args, int *a_stack)
{
	int	i;
	int	temp;

	args->sorted_st = malloc(sizeof(int) * (args->count_a + 1));
	i = 0;
	while (i < args->count_a)
	{
		args->sorted_st[i] = a_stack[i];
		i++;
	}
	i = 0;
	while (!ft_is_ordered(args, args->sorted_st))
	{
		if (i == args->count_a - 1)
			i = 0;
		if (args->sorted_st[i] > args->sorted_st[i + 1])
		{
			temp = args->sorted_st[i + 1];
			args->sorted_st[i + 1] = args->sorted_st[i];
			args->sorted_st[i] = temp;
		}
		i++;
	}
	return (args->sorted_st);
}

int	*ft_get_indexes(t_counter *i, int *a_stack)
{
	int	j;
	int	counter;

	i->idx_st = malloc(sizeof(int) * (i->count_a + 1));
	counter = 0;
	while (counter < i->count_a)
	{
		j = 1;
		while (j <= i->count_a)
		{
			if (a_stack[counter] == i->sorted_st[j - 1])
				i->idx_st[counter] = j;
			j++;
		}
		counter++;
	}
	free(i->sorted_st);
	return (i->idx_st);
}

void	ft_radix(t_counter *i, int *a_stack, int *b_stack)
{
	i->count_temp = 0;
	i->bit = 1;
	while (!ft_is_ordered(i, i->idx_st))
	{
		i->an_index = 1;
		while (i->an_index++ < i->argc && !ft_is_ordered(i, i->idx_st))
		{
			if (i->idx_st[0] & i->bit)
			{
				ft_rotate(i->count_index, i->idx_st);
				ft_ra(i->count_a, a_stack);
			}
			else
			{
				ft_push(&i->count_temp, &i->count_index, i->tmp_st, i->idx_st);
				ft_pb(i, a_stack, b_stack);
			}
		}
		while (i->count_temp)
		{
			ft_push(&i->count_index, &i->count_temp, i->idx_st, i->tmp_st);
			ft_pa(i, a_stack, b_stack);
		}
		i->bit <<= 1;
	}
}

void	ft_sort3(t_counter *k, int *a_stack)
{
	int	i;

	i = 1;
	while (!ft_is_ordered(k, a_stack))
	{
		if (a_stack[i] > a_stack[i - 1] && a_stack[i] > a_stack[i + 1])
			ft_rra(k->count_a, a_stack);
		if (a_stack[i - 1] > a_stack[i] && a_stack[i - 1] > a_stack[i + 1])
			ft_ra(k->count_a, a_stack);
		if (a_stack[i] < a_stack[i - 1])
			ft_sa(a_stack);
	}
}

void	ft_sort5(t_counter *i, int *a_stack, int *b_stack)
{
	while (!ft_is_ordered(i, a_stack) && i->an_index < 3)
	{
		if (i->idx_st[0] == i->an_index)
		{
			ft_push(&i->count_temp, &i->count_index, i->tmp_st, i->idx_st);
			ft_pb(i, a_stack, b_stack);
			i->an_index++;
		}
		else if (i->an_index == i->idx_st[1])
		{
			ft_switch(i->idx_st);
			ft_sa(a_stack);
		}
		else if (i->an_index == i->idx_st[2])
		{
			ft_rotate(i->count_index, i->idx_st);
			ft_ra(i->count_a, a_stack);
		}
		else if (i->an_index == i->idx_st[4] || i->an_index == i->idx_st[3])
		{
			ft_reverse_rotate(i->count_index, i->idx_st);
			ft_rra(i->count_a, a_stack);
		}
	}
}
