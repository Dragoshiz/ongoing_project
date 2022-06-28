/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:08:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/28 15:21:42 by dimbrea          ###   ########.fr       */
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

typedef struct s_vars	t_vars;

typedef struct s_philo
{
	t_vars		*vars;
	int			id;
	int			l_fork;
	int			r_fork;
	int			has_eaten;
	int			is_dead;
	int			meals;
	long long	last_meal;
	pthread_t	thread;
}t_philo;
typedef struct s_vars
{
	t_philo				*philo;
	long long			start;
	int					num_philo;
	int					tm_to_die;
	int					tm_to_eat;
	int					tm_to_sleep;
	int					x_to_eat;
	int					all_meals;
	int					is_end;
	pthread_mutex_t		last_meal;
	pthread_mutex_t		print;
	pthread_mutex_t		dead;
	pthread_mutex_t		*forks;
}t_vars;

int			philo_atoi(char *str, int *var);
void		errmsg(char *str);
int			check_args(char *argv[], t_vars *vars);
long long	ft_time(void);
int			ft_alloc(t_vars *vars);
void		ft_assign_idnforks(t_vars *vars);
int			ft_thread(t_vars *philo);
void		ft_printmsg(t_philo *philo, char *msg);
void		ft_is_dead(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_eat(t_philo *philo);
void		*routine(t_philo *philo);
#endif
