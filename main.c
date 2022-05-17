/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:40:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/17 13:32:59 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	mlx.map.map_height = 0;
	mlx.map.steps = 0;
	mlx.map.p_path = "srcs/down-fly.xpm";
	ft_get_map(&mlx, argv[1]);
	ft_start(&mlx);
	return (0);
}
