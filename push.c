/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:27:38 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:52:24 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
