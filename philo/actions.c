/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/30 19:19:00 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_dead(t_vars *vars)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&vars->dead);
		pthread_mutex_lock(&vars->sleep);
		if ((ft_time() - vars->philo[i].last_meal >= vars->tm_to_die))
		{
			printf("%05lld %d is dead\n", ft_time()
				- vars->start, vars->philo[i].id);
			vars->is_end = 1;
			pthread_mutex_unlock(&vars->sleep);
			pthread_mutex_unlock(&vars->dead);
			break ;
		}
		pthread_mutex_unlock(&vars->sleep);
		pthread_mutex_unlock(&vars->dead);
	}
}

void	ft_check_n_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->vars->dead);
	if (!philo->vars->is_end)
	{
		pthread_mutex_lock(&philo->vars->print);
		printf("%05lld %d %s\n", ft_time() - philo->vars->start, philo->id, msg);
		pthread_mutex_unlock(&philo->vars->print);
	}
	pthread_mutex_unlock(&philo->vars->dead);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->forks[philo->l_fork]);
	ft_check_n_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->vars->forks[philo->r_fork]);
	ft_check_n_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->vars->sleep);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->vars->sleep);
	philo->meals++;
	ft_check_n_print(philo, "is eating");
	usleep(philo->vars->tm_to_eat * 1000);
	pthread_mutex_unlock(&philo->vars->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->vars->forks[philo->r_fork]);
}

void	ft_sleep(t_philo *philo)
{
	ft_check_n_print(philo, "is sleeping");
	usleep(philo->vars->tm_to_sleep * 1000);
	ft_check_n_print(philo, "is thinking");
}

void	*routine(t_philo *philo)
{
	if (philo->vars->num_philo == 1)
		usleep(philo->vars->tm_to_die * 1000);
	if (philo->id % 2 == 0)
		usleep(philo->vars->tm_to_eat * 1000);
	pthread_mutex_lock(&philo->vars->sleep);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->vars->sleep);
	while (1)
	{
		pthread_mutex_lock(&philo->vars->sleep);
		if (philo->vars->is_end)
		{
			pthread_mutex_unlock(&philo->vars->sleep);
			break ;
		}
		pthread_mutex_unlock(&philo->vars->sleep);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
