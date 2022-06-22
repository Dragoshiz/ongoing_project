/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:08:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/22 16:13:12 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_philo
{
	int	id;
	int	*l_fork;
	int	*r_fork;
	int	sleep;
	int	eaten;
	int 
}t_philo;

typedef struct s_vars
{
	long long	start;
	int			philos;
	int			tm_to_die;
	int			tm_to_eat;
	int			tm_to_sleep;
	int			x_to_eat;
	int			forks;
}t_vars;

int			philo_atoi(char *str, int *var);
void		errmsg(char *str);
int			check_args(char *argv[], t_vars *vars);
long long	ft_time(void);
#endif
