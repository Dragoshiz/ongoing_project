/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:08:23 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/10 17:22:12 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
