/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:25:09 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/03 18:32:22 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_var
{
	int	philos;
	int	t_todie;
	int	t_toeat;
	int	t_tosleep;
	int	num_of_eats;
}t_var;
typedef struct s_philo
{
	int	l_f;
	int	r_f;
}t_philo;

int		ft_atoi(const char *argv);
void	ft_init_input(t_var *var, int argc, char *argv[]);

#endif