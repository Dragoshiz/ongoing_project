/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:25:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/03 18:40:32 by dimbrea          ###   ########.fr       */
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

int	main (int argc, char *argv[])
{
	t_var			var;
	struct timeval	start;
	struct timeval	end;

	if (!ft_check_input(argc, argv))
		return (1);
	gettimeofday(&start, NULL);
	for(int i=0; i < 200000; i++)
		printf("%d", i);
	printf("\n%ld\n", ft_time_df(&start, &end));
	return (0);
}
