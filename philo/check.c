/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:46:28 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/28 16:09:57 by dimbrea          ###   ########.fr       */
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
	vars->all_meals = -1;
	vars->is_end = 0;
	if (argv[5] && philo_atoi(argv[5], &vars->x_to_eat))
	{
		vars->is_end = 0;
		return (1);
	}
	return (0);
}

//it returns the time I return tvsec*1000 + tv_usec/1000 because
//if I use only tv_usec/1000 when i call it the second time,
//if it passed one milisecond it gets resetted so if i do
//end - start, end will be smaller than start, end the result will be negative
long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
