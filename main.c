/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:22:37 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/10 17:39:59 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			*a_stack;
	int			*b_stack;
	t_counter	i;

	if (argc == 1 || argc == 2)
		exit(0);
	b_stack = malloc(sizeof(int) * (argc));
	if (!b_stack)
		return (0);
	ft_isnum(argv);
	a_stack = ft_convert2int(argc, argv);
	ft_check_dup(argc, a_stack);
	ft_initialize(&i, argc);
	if (ft_is_ordered(&i, a_stack))
	{
		ft_free(&i, a_stack, b_stack);
		exit(0);
	}
	i.sorted_st = ft_get_sorted(&i, a_stack);
	i.idx_st = ft_get_indexes(&i, a_stack);
	// for(int k = 0; k < argc- 1; k++)
		// printf("%d ", a_stack[k]);
	// printf("BEFORE\n");
	ft_sort(&i, a_stack, b_stack);
	// for(int k = 0; k < argc - 1; k++)
	// 	printf("%d ", a_stack[k]);
	ft_free(&i, a_stack, b_stack);
	
	return (0);
}
