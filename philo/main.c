/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:25:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/03 15:24:33 by dimbrea          ###   ########.fr       */
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
				printf("%c", argv[i][j]);
				if (argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
				else
					return (0);
			}
			printf("\n");
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	printf("%d",ft_check_input(argc, argv));
	return (0);
	
}