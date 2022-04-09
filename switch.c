/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:33:58 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:56:55 by dimbrea          ###   ########.fr       */
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
