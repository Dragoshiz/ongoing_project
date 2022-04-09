/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:56:00 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:56:45 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(int size, int *stack)
{
	int	i;
	int	temp;

	temp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i -1];
		i--;
	}
	stack[0] = temp;
}

void	ft_rra(int size, int *a_stack)
{
	ft_reverse_rotate(size, a_stack);
	write(1, "rra\n", 4);
}

void	ft_rrb(int size, int *b_stack)
{
	ft_reverse_rotate(size, b_stack);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_counter *i, int *a_stack, int *b_stack)
{
	ft_reverse_rotate(i->count_a, a_stack);
	ft_reverse_rotate(i->count_b, b_stack);
	write(1, "rrr\n", 4);
}
