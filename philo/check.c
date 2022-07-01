/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:46:28 by dimbrea           #+#    #+#             */
/*   Updated: 2022/07/01 19:06:33 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//modified atoi function so that arguments get assigned to variables
int	philo_atoi(char *str, int *var)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (str[i] == '-')
		return (1);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			i++;
			if (res > INT_MAX || res == 0)
				return (1);
		}
		else
			return (1);
	}
	*var = (int)res;
	return (0);
}

//writes an error message to stderr
void	errmsg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

//function to check arguments using a modified atoi 
int	check_args(char *argv[], t_vars *vars)
{
	if (philo_atoi(argv[1], &vars->num_philo)
		|| philo_atoi(argv[2], &vars->tm_to_die)
		|| philo_atoi(argv[3], &vars->tm_to_eat)
		|| philo_atoi(argv[4], &vars->tm_to_sleep))
		return (1);
	vars->x_to_eat = -1;
	if (argv[5] && philo_atoi(argv[5], &vars->x_to_eat))
		return (1);
	vars->is_end = 0;
	return (0);
}
