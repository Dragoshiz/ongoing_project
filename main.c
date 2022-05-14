/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:40:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/14 17:21:21 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	map.map_height = 0;
	ft_get_map(&map, argv[1]);
	ft_start(&mlx, &map);

	return (0);
}
