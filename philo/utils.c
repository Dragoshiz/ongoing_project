/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:08:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/25 19:39:54 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		vars->philo[i].last_meal = ft_time();
		vars->philo[i].id = id;
		vars->philo[i].l_fork = i;
		vars->philo[i].has_eaten = 0;
		vars->philo->is_dead = 0;
		if (i == vars->num_philo - 1)
			vars->philo[i].r_fork = 0;
		else
			vars->philo[i].r_fork = i + 1;
		id++;
		i++;
	}
}

void	ft_printmsg(t_philo *philo, char *msg)
{
	long long	now;

	now = ft_time();
	pthread_mutex_lock(&philo->vars->dead);
	pthread_mutex_lock(&philo->vars->print);
	if (!philo->is_dead && !philo->vars->is_end)
	{
		printf("%.005lld %d %s\n", ft_time(), philo->id, msg);
	}
	pthread_mutex_unlock(&philo->vars->dead);
	pthread_mutex_unlock(&philo->vars->print);
}

void	ft_sleep(t_philo *philo)
{
	long long	start;
	long long	now;
	long long	diff;

	start = ft_time();
	ft_printmsg(philo, "is sleeping");
	while (1)
	{
		now = ft_time();
		diff = now - start;
		if (diff >= philo->vars->tm_to_sleep)
			break ;
	}
}

void	ft_think(t_philo *philo)
{
	ft_printmsg(philo, "is thinking");
}

// void	ft_eat(t_philo *philo)
// {
// 	long long	start;
// 	long long	now;
// 	long long	diff;

// 	start = ft_time;
// 	if (philo->id % 2 == 0)
// }

void	*routine(t_philo *philo)
{
	if (philo->vars->num_philo == 1)
		printf("Here is only one let it think and die");
// 	while (!philo->vars->is_end)
// 	{
		
// 	}
	ft_sleep(philo);
	// ft_think(philo);
	return (NULL);
}

int	ft_thread(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_philo)
	{
		if (pthread_create(&vars->philo[i].thread, NULL, \
		(void *(*)(void *))routine, &vars->philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < vars->num_philo)
	{
		if (pthread_join(vars->philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
