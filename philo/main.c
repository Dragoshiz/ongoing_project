/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:08:41 by dimbrea           #+#    #+#             */
/*   Updated: 2022/07/04 12:11:26 by dimbrea          ###   ########.fr       */
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
	{
		errmsg("One of the arguments is not valid!");
		return (1);
	}
	if (ft_alloc(&vars))
	{
		errmsg("Allocation did not succeed");
		return (1);
	}
	ft_assign_idnforks(&vars);
	ft_thread(&vars);
	ft_kill_them_all(vars.philo);
	return (0);
}
