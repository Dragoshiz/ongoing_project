/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:08:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/07/05 17:18:18 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//function for destroying mutexes and freeing allocated memory
void	ft_kill_them_all(t_philo *philo)
{
	int	i;

	pthread_mutex_destroy(&philo->vars->l_meal);
	pthread_mutex_destroy(&philo->vars->print);
	pthread_mutex_destroy(&philo->vars->dead);
	pthread_mutex_destroy(&philo->vars->x_meal);
	i = 0;
	while (i < philo->vars->num_philo)
	{
		pthread_mutex_destroy(&philo->vars->forks[i]);
		i++;
	}
	free(philo->vars->forks);
	free(philo);
}

//allcating mem to each philo and alloc mem for forks MUST BE FREED!!!!
int	ft_alloc(t_vars *vars)
{
	int	i;

	i = 0;
	vars->philo = malloc(sizeof(t_philo) * vars->num_philo);
	if (!vars->philo)
		return (1);
	vars->forks = malloc(sizeof(pthread_mutex_t) \
	* vars->num_philo);
	if (!vars->forks)
		return (1);
	pthread_mutex_init(&vars->print, NULL);
	pthread_mutex_init(&vars->dead, NULL);
	pthread_mutex_init(&vars->l_meal, NULL);
	pthread_mutex_init(&vars->x_meal, NULL);
	while (i < vars->num_philo)
	{
		pthread_mutex_init(&vars->forks[i], NULL);
		i++;
	}
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
		vars->philo[i].vars = vars;
		vars->philo[i].id = id;
		vars->philo[i].l_fork = i;
		vars->philo[i].is_full = 0;
		vars->philo[i].meals = 0;
		if (i == vars->num_philo - 1)
			vars->philo[i].r_fork = 0;
		else
			vars->philo[i].r_fork = i + 1;
		id++;
		i++;
	}
}

//function to create threads in a loop, also checking with ft_is_dead()
//that runs in an infinite loop if a philosopher died
int	ft_thread(t_vars *vars)
{
	int	i;

	vars->all_ate = 0;
	vars->start = ft_time();
	i = 0;
	while (i < vars->num_philo)
	{
		vars->philo[i].last_meal = ft_time();
		if (pthread_create(&vars->philo[i].thread, NULL, \
		(void *(*)(void *))routine, &vars->philo[i]))
			return (1);
		i++;
	}
	ft_is_dead(vars);
	i = 0;
	while (i < vars->num_philo)
	{
		if (pthread_join(vars->philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
