/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:08:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/24 18:09:30 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//allcating mem to each philo and alloc mem for forks MUST BE FREED!!!!
int	ft_alloc(t_vars *vars)
{
	vars->philo = malloc(sizeof(t_philo) * vars->num_philo);
	if (!vars->philo)
		return (1);
	vars->forks = malloc(sizeof(pthread_mutex_t) \
	* vars->num_philo);
	return (0);
}

//assigning IDs and forks to each philosopher accordingly
void	ft_assign_idnforks(t_vars *vars)
{
	int	i;
	int	id;

	i = 0;
	id = 1;
	while (i < vars->num_philo)
	{
		vars->philo[i].id = id;
		vars->philo[i].l_fork = i;
		if (i == vars->num_philo - 1)
			vars->philo[i].r_fork = 0;
		else
			vars->philo[i].r_fork = i + 1;
		id++;
		i++;
	}
}

void	routine(void)
{
	
}

int	ft_start_threads(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_philo)
	{
		pthread_create(&vars->philo[i].thread, NULL, &routine, NULL);
		i++;
	}
	
}