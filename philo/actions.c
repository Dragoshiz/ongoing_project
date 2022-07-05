/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/07/05 17:18:41 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//checks if philosophers have died 
void	ft_is_dead(t_vars *vars)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == vars->num_philo)
			i = 0;
		if (ft_all_ate(vars))
			return ;
		ft_no_space(vars);
		if (vars->philo[i].meals == vars->x_to_eat)
			vars->philo[i].is_full = 1;
		pthread_mutex_unlock(&vars->x_meal);
		if ((ft_time() - vars->philo[i].last_meal >= vars->tm_to_die))
		{
			printf("%05lld %d is dead\n", ft_time()
				- vars->start, vars->philo[i].id);
			vars->is_end = 1;
			ft_no_space2(vars);
			break ;
		}
		ft_no_space2(vars);
		i++;
	}
}

//eating action to run until time_to_eat time;
void	ft_eat_action(t_philo *philo)
{
	long long	now;
	long long	diff;
	long long	start;

	start = ft_time();
	while (1)
	{
		usleep(100);
		now = ft_time();
		diff = now - start;
		if (diff >= philo->vars->tm_to_eat)
			break ;
	}
}

//function to make philosophers eat
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->forks[philo->l_fork]);
	ft_check_n_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->vars->forks[philo->r_fork]);
	ft_check_n_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->vars->l_meal);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->vars->l_meal);
	ft_check_n_print(philo, "is eating");
	ft_eat_action(philo);
	pthread_mutex_lock(&philo->vars->x_meal);
	philo->meals++;
	pthread_mutex_unlock(&philo->vars->x_meal);
	pthread_mutex_unlock(&philo->vars->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->vars->forks[philo->r_fork]);
}

//fucntion to make philosophers sleep
void	ft_sleep(t_philo *philo)
{
	long long	now;
	long long	diff;
	long long	start;

	ft_check_n_print(philo, "is sleeping");
	start = ft_time();
	while (1)
	{
		usleep(100);
		now = ft_time();
		diff = now - start;
		if (diff >= philo->vars->tm_to_sleep)
			break ;
	}
	ft_check_n_print(philo, "is thinking");
}

//function used in pthread_create
void	*routine(t_philo *philo)
{
	if (philo->vars->num_philo == 1)
		usleep(philo->vars->tm_to_die * 1000);
	if (philo->id % 2 == 0)
		usleep(philo->vars->tm_to_eat * 1000);
	pthread_mutex_lock(&philo->vars->l_meal);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->vars->l_meal);
	while (1)
	{
		pthread_mutex_lock(&philo->vars->dead);
		if (philo->vars->is_end)
		{
			pthread_mutex_unlock(&philo->vars->dead);
			break ;
		}
		pthread_mutex_unlock(&philo->vars->dead);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
