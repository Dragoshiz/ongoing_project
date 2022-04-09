/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:08:23 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/09 19:12:21 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

void	ft_isnum(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_err_msg();
			j++;
		}
		i++;
	}
}

int	*ft_convert2int(int argc, char *argv[])
{
	int	*a_stack;
	int	i;
	int	j;

	a_stack = malloc(sizeof(int) * (argc));
	if (!a_stack)
		return (NULL);
	i = 1;
	j = 0;
	while (argv[i])
	{
		a_stack[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (a_stack);
}

void	ft_check_dup(int argc, int *a_stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (a_stack[i] == a_stack[j])
				ft_err_msg();
			j++;
		}
		i++;
	}
}

bool	ft_is_ordered(t_counter *count, int *a_stack)
{
	int	i;

	i = 0;
	while (i < count->count_a - 1)
	{
		if (a_stack[i] > a_stack[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	int			*a_stack;
	int			*b_stack;
	t_counter	i;

	// i.argc = argc;
	b_stack = malloc(sizeof(int) * (argc));
	// i.tmp_st = malloc(sizeof(int) * (i.argc));
	if (!b_stack)
		return (0);
	ft_initialize(&i, argc);
	if (argc == 1 || argc == 2)
		exit(0);
	ft_isnum(argv);
	a_stack = ft_convert2int(argc, argv);
	ft_check_dup(argc, a_stack);
	if (ft_is_ordered(&i, a_stack))
		exit(0);
	i.sorted_st = ft_get_sorted(&i, a_stack);
	i.idx_st = ft_get_indexes(&i, a_stack);
	// ft_sort3(&i, a_stack);
	// ft_sort5(&i, a_stack, b_stack);
	// ft_radix(&i, a_stack, b_stack);
	for (int k = 0; k < i.count_a; k++)
		printf("%d, a_stack ", a_stack[k]);
	ft_free(&i, a_stack, b_stack);
	return 0;
}

