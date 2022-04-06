/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:37:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/06 18:39:42 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_sorted(t_counter *count, int *a_stack)
{
	int	*sorted_stack;
	int	i;
	int	temp;

	sorted_stack = malloc(sizeof(int) * (count->count_a + 1));
	i = 0;
	while (i < count->count_a)
	{
		sorted_stack[i] = a_stack[i];
		i++;
	}
	i = 0;
	while (!ft_is_ordered(count, sorted_stack))
	{
		if (i == count->count_a - 1)
			i = 0;
		if (sorted_stack[i] > sorted_stack[i + 1])
		{
			temp = sorted_stack[i + 1];
			sorted_stack[i + 1] = sorted_stack[i];
			sorted_stack[i] = temp;
		}
		i++;
	}
	return (sorted_stack);
}

//original stack and sorted original stack
int	*ft_get_indexes(t_counter *count, int *sorted, int *a_stack)
{
	int	*index_stack;
	int	i;
	int	counter;

	index_stack = malloc(sizeof(int) * (count->count_a + 1));
	counter = 0;
	while (counter < count->count_a)
	{
		i = 1;
		while (i <= count->count_a)
		{
			if (a_stack[counter] == sorted[i-1])
				index_stack[counter] = i;
			i++;
		}
		counter++;
	}
	// free(sorted); //HERE YOU FREE SORTED
	return (index_stack);
}

void	ft_radix(int argc, t_counter *count, int *a_stack, int *b_stack, int *index_stack)
{
	int	i;
	int	*temp_stack;
	int	j;

	temp_stack = malloc(sizeof(int) * (count->count_a + 1));
	i = 1;
	while (!ft_is_ordered(count, index_stack) && i <= 1280)
	{
		j = 1;
		while (j < argc)
		{
			if (index_stack[0] & i)
				ft_ra(count->count_a, index_stack);
			else
				ft_pb(count, index_stack, temp_stack);
			j++;
		}
		while (count->count_b)
		{
			ft_pa(count, index_stack, temp_stack);
		}
		i *= 2;
	}
	// printf("%d", i);
}
