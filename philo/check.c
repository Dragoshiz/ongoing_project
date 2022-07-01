/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:46:28 by dimbrea           #+#    #+#             */
/*   Updated: 2022/07/01 18:51:02 by dimbrea          ###   ########.fr       */
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

// int		ft_all_ate(t_vars *vars)
// {
// 	int	i;

// 	i = 0;
// 	while (i < vars->num_philo)
// 	{
// 		if (!vars->philo[i].has_eaten)
// 		{
// 			// pthread_mutex_lock(&vars->meal);
// 			if (vars->philo[i].meals >= vars->x_to_eat)
// 			{
// 				vars->all_ate++;
// 				vars->philo[i].has_eaten = 1;
// 			}
// 			// pthread_mutex_unlock(&vars->meal);
// 		}
// 		// printf("%d ID %d has eaten, %d MEALS %d X TO EAT %d ALL ATE\n", vars->philo[i].id, vars->philo[i].has_eaten, vars->philo[i].meals, vars->x_to_eat, vars->all_ate);
// 		if (vars->all_ate == vars->num_philo)
// 		{
// 			vars->is_end = 1;
// 			// printf("%05lld all ate\n", ft_time() - vars->start);
// 			pthread_mutex_unlock(&vars->sleep);
// 			pthread_mutex_unlock(&vars->dead);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	ft_all_ate(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_philo)
	{
		if (vars->philo[i].has_eaten)
			vars->all_ate++;
		if (vars->all_ate == vars->x_to_eat)
		{
			pthread_mutex_lock(&vars->dead);
			vars->is_end = 1;
			pthread_mutex_unlock(&vars->dead);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_no_space(t_vars *vars)
{
	pthread_mutex_lock(&vars->dead);
	pthread_mutex_lock(&vars->sleep);
	pthread_mutex_lock(&vars->meal);
}
