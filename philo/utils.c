/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:25:46 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/03 15:56:56 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *argv)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	while (argv[i] <= 32)
		i++;
	if (argv[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (argv[i] == '+')
		i++;
	while (argv[i] && argv[i] >= '0' && argv[i] <= '9')
	{
		res *= 10;
		res += argv[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_init_input(t_var *var, int argc, char *argv[])
{
	var->philos = ft_atoi(argv[1]);
	var->t_todie = ft_atoi(argv[2]);
	var->t_toeat = ft_atoi(argv[3]);
	var->t_tosleep = ft_atoi(argv[4]);
	if (argc == 6)
		var->num_of_eats = ft_atoi(argv[5]);
	var->forks = var->philos;
}
