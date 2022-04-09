/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:55:02 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:55:30 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(int size, int *stack)
{
	int	i;
	int	temp;

	temp = stack[0];
	i = 0;
	while (i < size)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

void	ft_ra(int size, int *a_stack)
{
	ft_rotate(size, a_stack);
	write(1, "ra\n", 3);
}

void	ft_rb(int size, int *b_stack)
{
	ft_rotate(size, b_stack);
	write(1, "rb\n", 3);
}

void	ft_rr(t_counter *size, int *a_stack, int *b_stack)
{
	ft_rotate(size->count_a, a_stack);
	ft_rotate(size->count_b, b_stack);
	write(1, "rr\n", 3);
}
