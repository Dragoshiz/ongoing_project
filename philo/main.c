/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:08:41 by dimbrea           #+#    #+#             */
/*   Updated: 2022/06/25 19:32:06 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 5 || argc > 6)
	{
		write(2, "Arguments must be 4 or 5", 24);
		return (1);
	}
	if (check_args(argv, &vars))
		errmsg("One of the arguments is not valid!");
	if (ft_alloc(&vars))//freeee!!
		errmsg("Allocation did not succeed");
	ft_assign_idnforks(&vars);
	// pthread_mutex_init(&vars.print, NULL);
	ft_thread(&vars);
	return (0);
}

