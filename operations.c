/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:33:58 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 15:07:42 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_switch(int *stack)
{
	int	temp;

	if (!stack[0])
		exit(0);
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	ft_sa(int *a_stack)
{
	ft_switch(a_stack);
	write(1, "sa\n", 3);
}

void	ft_sb(int *b_stack)
{
	ft_switch(b_stack);
	write(1, "sb\n", 3);
}

void	ft_ss(int *a_stack, int *b_stack)
{
	ft_switch(a_stack);
	ft_switch(b_stack);
	write(1, "ss\n", 3);
}

void	ft_push(int *to_add, int *to_subt, int *stk_add, int *stk_subt)
{
	if (!stk_subt)
		return ;
	*to_add += 1;
	ft_put_elem(*to_add, stk_add);
	stk_add[0] = stk_subt[0];
	ft_remv_elem(*to_subt, stk_subt);
	*to_subt -= 1;
}
void	ft_pa(t_counter *i, int *a_stack, int *b_stack)
{
	ft_push(&i->count_a, &i->count_b, a_stack, b_stack);
	write(1, "pa\n", 3);
}

void	ft_pb(t_counter *i, int *a_stack, int *b_stack)
{
	ft_push(&i->count_b, &i->count_a, b_stack, a_stack);
	write(1, "pb\n", 3);
}

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
