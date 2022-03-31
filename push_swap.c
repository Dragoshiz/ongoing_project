/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:08:23 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/31 18:43:16 by dimbrea          ###   ########.fr       */
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

	a_stack = malloc(sizeof(int) * argc);
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
			{	
				ft_err_msg();
			}
			j++;
		}
		i++;
	}
}

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
	int	*a_stack;
	int	i;

	if (argc == 1)
		exit(0);
	if (argc == 2)
		exit(0);
	ft_check_isnum(argc, argv);
	a_stack = ft_convert2int(argc, argv);
	// printf("%d", argc);
	ft_check_dup(argc, a_stack);
	i = 1;
	free(a_stack);
	return 0;
}
