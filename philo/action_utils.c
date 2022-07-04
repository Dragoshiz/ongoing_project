/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:02:39 by dimbrea           #+#    #+#             */
/*   Updated: 2022/07/04 17:17:02 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//it returns the time I return tvsec*1000 + tv_usec/1000 because
//if I use only tv_usec/1000 when i call it the second time,
//if it passed one milisecond it gets resetted so if i do
//end - start, end will be smaller than start, end the result will be negative
long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

//had to use this ugly thing to workaround norm
void	ft_no_space(t_vars *vars)
{
	pthread_mutex_lock(&vars->dead);
	pthread_mutex_lock(&vars->l_meal);
	pthread_mutex_lock(&vars->x_meal);
}

//had to use this ugly thing to workaround norm.. again
void	ft_no_space2(t_vars *vars)
{
	pthread_mutex_unlock(&vars->l_meal);
	pthread_mutex_unlock(&vars->dead);
}

//checks if the program ended if not it will print the message
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

//checks wether philos have ate x times_to_eat if all of them at that much
//program ends
int	ft_all_ate(t_vars *vars)
{
	int	i;

	i = 0;
	vars->all_ate = 0;
	while (i < vars->num_philo)
	{
		if (vars->philo[i].is_full)
				vars->all_ate++;
		if (vars->all_ate == vars->num_philo && vars->x_to_eat > 1)
		{
			pthread_mutex_lock(&vars->dead);
			vars->is_end = 1;
			pthread_mutex_unlock(&vars->dead);
			return (1);
		}
		if (vars->all_ate == vars->num_philo && vars->x_to_eat == 1)
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
