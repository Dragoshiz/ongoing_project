/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:47:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/28 16:16:36 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printmsg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->vars->print);
	if (!philo->vars->is_end)
	{
		ft_is_dead(philo);
		usleep(100);
		printf("%05llu %d %s\n", (ft_time() - philo->vars->start),
			philo->id, msg);
		pthread_mutex_unlock(&philo->vars->print);
	}
	else
		pthread_mutex_unlock(&philo->vars->print);
}

void	ft_is_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->vars->num_philo && !philo->vars->is_end)
	{
		// printf("x");
		pthread_mutex_lock(&philo->vars->dead);
		// printf("x");
		if (ft_time() - philo[i].last_meal >= philo->vars->tm_to_die)
		{
			// printf("x");
			ft_printmsg(philo, "died");
			philo->vars->is_end = 1;
			pthread_mutex_unlock(&philo->vars->dead);
		}
		else
			pthread_mutex_unlock(&philo->vars->dead);
		if (philo->vars->is_end)
			break ;
		// i = 0;
		while (philo->vars->x_to_eat != -1 && i < philo->vars->num_philo
			&& philo[i].meals >= philo->vars->x_to_eat)
		{
			// printf("x");
			i++;
		}
		if (i == philo->vars->x_to_eat)
			philo->vars->all_meals = 1;
	}
}

// void	ft_is_dead(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philo->vars->num_philo && !philo->vars->is_end)
// 	{
// 		// printf("x");
// 		pthread_mutex_lock(&philo->vars->dead);
// 		// printf("x");
// 		if (ft_time() - philo[i].last_meal >= philo->vars->tm_to_die)
// 		{
// 			// printf("x");
// 			ft_printmsg(philo, "died");
// 			philo->vars->is_end = 1;
// 			pthread_mutex_unlock(&philo->vars->dead);
// 		}
// 		else
// 			pthread_mutex_unlock(&philo->vars->dead);
// 		if (philo->vars->is_end)
// 			break ;
// 		// i = 0;
// 		while (philo->vars->x_to_eat != -1 && i < philo->vars->num_philo
// 			&& philo[i].meals >= philo->vars->x_to_eat)
// 		{
// 			// printf("x");
// 			i++;
// 		}
// 		if (i == philo->vars->x_to_eat)
// 			philo->vars->all_meals = 1;
// 	}
void	ft_usleep(t_philo *philo, int howmuch)
{
	int	i;

	i = 0;
	while (i < howmuch)
	{
		ft_is_dead(philo);
		usleep(i);
		i += 10;
	}
}

void	ft_sleep(t_philo *philo)
{
	long long	start;
	long long	now;
	long long	diff;

	start = ft_time();
	ft_printmsg(philo, "is sleeping");
	while (!philo->vars->is_end)
	{
		ft_usleep(philo, philo->vars->tm_to_sleep);
		now = ft_time();
		diff = now - start;
		if (diff >= philo->vars->tm_to_sleep)
			break ;
	}
	ft_printmsg(philo, "is thinking");
}

void	ft_eat(t_philo *philo)
{
	long long	start;
	long long	now;
	long long	diff;

	if (philo->meals == philo->vars->all_meals && !philo->vars->is_end)
		return ;
	// ft_is_dead(philo);
	pthread_mutex_lock(&philo->vars->forks[philo->l_fork]);
	ft_printmsg(philo, "has taken the left fork");
	ft_is_dead(philo);
	pthread_mutex_lock(&philo->vars->forks[philo->r_fork]);
	ft_printmsg(philo, "has taken the right fork");
	ft_is_dead(philo);
	pthread_mutex_lock(&philo->vars->last_meal);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->vars->last_meal);
	ft_printmsg(philo, "is eating");
	start = ft_time();
	while (!philo->vars->is_end)
	{
		ft_usleep(philo, 100);
		if ((ft_time() - start) >= philo->vars->tm_to_eat)
		{
			philo->meals++;
			pthread_mutex_unlock(&philo->vars->forks[philo->l_fork]);
			pthread_mutex_unlock(&philo->vars->forks[philo->r_fork]);
			break ;
		}
	}
	ft_usleep(philo, philo->vars->tm_to_eat);
}

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(15000);
	philo->last_meal = ft_time();
	while (!philo->vars->is_end)
	{
		ft_usleep(philo, 100);
		ft_eat(philo);
		if (!philo->vars->all_meals)
			break ;
		ft_sleep(philo);
		ft_is_dead(philo);
	}
	return (NULL);
}
