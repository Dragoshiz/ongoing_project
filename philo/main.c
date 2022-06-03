/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:25:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/03 18:14:19 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
				else
					return (0);
			}
			i++;
		}
		return (1);
	}
	else
		return (0);
}

long	ft_time_df(struct timeval *start, struct timeval *end)
{
	gettimeofday(end, NULL);
	return ((end->tv_usec - start->tv_usec) / 1000);
}
void run_loop(void)
{
	int i;

	i = 0;
	while(i < 10000)
	{
		printf("%d\n", i);
		i++;
	}
}
int	main (int argc, char *argv[])
{
	t_var			var;
	struct timeval	start;
	struct timeval	end;

	if (!ft_check_input(argc, argv))
		return (1);
	gettimeofday(&start, NULL);
	run_loop();
	printf("%ld", ft_time_df(&start, &end));
	return (0);
}
