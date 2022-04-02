/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:33:58 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/02 18:16:20 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int *a_stack)
{
	int	temp;

	if (!a_stack[0] || !a_stack[1])
		exit(0);
	temp = a_stack[0];
	a_stack[0] = a_stack[1];
	a_stack[1] = temp;
	write(1, "sa\n", 3);
}

void	ft_sb(int *b_stack)
{
	int	temp;

	if (!b_stack[0] || !b_stack[1])
		exit(0);
	temp = b_stack[0];
	b_stack[0] = b_stack[1];
	b_stack[1] = temp;
	write(1, "sb\n", 3);
}

void	ft_ss(void ft_sa(), void ft_sb())
{
	write(1, "ss\n", 3);
}

void	ft_pa(t_counter *i, int *a_stack, int *b_stack)
{
	if (!b_stack)
		return ;
	i->count_a += 1;
	ft_put_elem(i->count_a, a_stack);
	a_stack[0] = b_stack[0];
	ft_remv_elem(i->count_b, b_stack);
	i->count_b -= 1;
	write(1, "pa\n", 3);
}

void	ft_pb(t_counter *i, int *a_stack, int *b_stack)
{
	if (!a_stack)
		return ;
	i->count_b += 1;
	ft_put_elem(i->count_b, b_stack);
	b_stack[0] = a_stack[0];
	ft_remv_elem(i->count_a, a_stack);
	i->count_a -= 1;
	write(1, "pb\n", 3);
}

void	ft_ra(int size, int *a_stack)
{
	int	i;
	int	temp;

	temp = a_stack[0];
	i = 0;
	while (i < size)
	{
		a_stack[i] = a_stack[i + 1];
		i++;
	}
	a_stack[size - 1] = temp;
	write(1, "ra\n", 3);
}

void	ft_rb(int size, int *b_stack)
{
	int	i;
	int	temp;

	temp = b_stack[0];
	i = 0;
	while (i < size)
	{
		b_stack[i] = b_stack[i + 1];
		i++;
	}
	b_stack[size - 1] = temp;
	write(1, "rb\n", 3);
}

void	ft_rr(void ft_ra(), void ft_rb())
{
	// considered 1 move use it with both functions.
}

void	ft_rra(int size, int *a_stack)
{
	int	i;
	int	temp;

	temp = a_stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		a_stack[i] = a_stack[i -1];
		i--;
	}
	a_stack[0] = temp;
	write(1, "rra\n", 4);
}

void	ft_rrb(int size, int *b_stack)
{
	int	i;
	int	temp;

	temp = b_stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		b_stack[i] = b_stack[i -1];
		i--;
	}
	b_stack[0] = temp;
	write(1, "rrb\n", 4);
}
