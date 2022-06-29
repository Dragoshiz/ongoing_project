/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/29 19:46:51 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_sleep(t_philo *philo)
{
	if (((ft_time() - philo->last_meal) + philo->vars->tm_to_sleep
			>= philo->vars->tm_to_die) && !philo->vars->is_end)
	{
		philo->vars->is_end = 1;
		philo->is_dead = 1;
		pthread_mutex_lock(&philo->vars->print);
		printf("%05lld %d is dead\n", ft_time()
			- philo->vars->start, philo->id);
		pthread_mutex_unlock(&philo->vars->print);
		pthread_mutex_unlock(&philo->vars->dead);
	}
}

int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->dead);
	usleep(100);
	if (ft_time() - philo->last_meal >= philo->vars->tm_to_die
		&& !philo->vars->is_end)
	{
		philo->vars->is_end = 1;
		philo->is_dead = 1;
		pthread_mutex_lock(&philo->vars->print);
		printf("%05lld %d is dead\n", ft_time()
			- philo->vars->start, philo->id);
		pthread_mutex_unlock(&philo->vars->print);
		pthread_mutex_unlock(&philo->vars->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->vars->dead);
	check_sleep(philo);
	return (0);
}

void	ft_check_n_print(t_philo *philo, char *msg)
{
	int	i;

	usleep(100);
	if (ft_is_dead(philo))
		return ;
	if (!philo->vars->is_end)
	{
		pthread_mutex_lock(&philo->vars->print);
		printf("%05lld %d %s\n", ft_time() - philo->vars->start, philo->id, msg);
		pthread_mutex_unlock(&philo->vars->print);
	}
}

void	ft_eat(t_philo *philo)
{
	usleep(100);
	if (!philo->vars->is_end)
	{
		usleep(100);
		pthread_mutex_lock(&philo->vars->forks[philo->l_fork]);
		ft_check_n_print(philo, "has taken a fork");
		usleep(100);
		ft_is_dead(philo);
		pthread_mutex_lock(&philo->vars->forks[philo->r_fork]);
		ft_check_n_print(philo, "has taken a fork");
		usleep(100);
		philo->last_meal = ft_time();
		ft_check_n_print(philo, "is eating");
		usleep(philo->vars->tm_to_eat * 1000);
		ft_is_dead(philo);
		pthread_mutex_unlock(&philo->vars->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->vars->forks[philo->r_fork]);
	}
}

void	ft_sleep(t_philo *philo)
{
	ft_is_dead(philo);
	usleep(100);
	if (!philo->vars->is_end)
	{
		ft_check_n_print(philo, "is sleeping");
		usleep(100);
		check_sleep(philo);
		if (!philo->vars->is_end)
			usleep(philo->vars->tm_to_sleep * 1000);
	}
}

void	*routine(t_philo *philo)
{
	if (philo->vars->num_philo == 1)
	{
		usleep(philo->vars->tm_to_die * 1000);
		ft_check_n_print(philo, "dead");
	}
	if (philo->id % 2 == 0)
	{
		usleep(philo->vars->tm_to_eat * 1000);
	}
	while (!philo->vars->is_end && !philo->vars->all_ate)
	{
		ft_eat(philo);
		usleep(100);
		ft_sleep(philo);
		usleep(100);
		ft_check_n_print(philo, "is thinking");
	}
	return (NULL);
}
