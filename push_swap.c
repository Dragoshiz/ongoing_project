/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:08:23 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/02 18:11:58 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

bool	ft_isnum(char *argv[])
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
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	*ft_convert2int(int argc, char *argv[])
{
	int	*a_stack;
	int	i;
	int	j;

	//changed to argc - 1
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

// is this funct necessary? check if you can implement in is_num
void	ft_check_isnum(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(&argv[i]))
		{
			ft_err_msg();
			exit(0);
		}
		i++;
	}
}



int	main(int argc, char *argv[])
{
	int			*a_stack;
	int			*b_stack;
	t_counter	i;

	b_stack = malloc(sizeof(int) * (argc));
	if (!b_stack)
		return (0);
	i.count_a = argc - 1;
	printf("%d main count\n", i.count_a);
	if (argc == 1)
		exit(0);
	if (argc == 2)//check if y
		exit(0);
	ft_check_isnum(argc, argv);
	a_stack = ft_convert2int(argc, argv);
	ft_check_dup(argc, a_stack);
	// b_stack[0] = 10;
	printf("%d, %d , %d, %d, %d , %d A__STACK\n",  a_stack[0],a_stack[1],a_stack[2],a_stack[3],a_stack[4],a_stack[5]);
	ft_pb(&i, a_stack, b_stack);
	ft_rrb(i.count_a, a_stack);

	// printf("%d, %d , %d, %d, %d , %d-------after\n",  a_stack[0],a_stack[1],a_stack[2],a_stack[3],a_stack[4],a_stack[5]);
	// ft_pb(&i, a_stack, b_stack);
	// printf("%d, %d , %d, %d, %d , %d B__STAACK\n",  b_stack[0],b_stack[1],b_stack[2],b_stack[3],b_stack[4],b_stack[5]);
	printf("%d, %d , %d, %d, %d , %d A_STAACK--after\n",  a_stack[0],a_stack[1],a_stack[2],a_stack[3],a_stack[4],a_stack[5]);
	// ft_pa(&i, a_stack, b_stack);
	// ft_pa(&i, a_stack, b_stack);
	// printf("%d, %d , %d, %d, %d , %d B__STAACK\n",  b_stack[0],b_stack[1],b_stack[2],b_stack[3],b_stack[4],b_stack[5]);
	// printf("%d, %d , %d, %d, %d , %d A_STAACK--after\n",  a_stack[0],a_stack[1],a_stack[2],a_stack[3],a_stack[4],a_stack[5]);

	printf("%d count a ---- %d count b", i.count_a, i.count_b);
	return 0;
}
