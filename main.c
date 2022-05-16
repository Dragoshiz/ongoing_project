/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:40:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/16 18:44:10 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc != 2)
		return (0);
	mlx.map.map_height = 0;
	ft_get_map(&mlx, argv[1]);
	printf("%s\n", mlx.map.line);
	printf("%c", mlx.map.line[mlx.map.player- mlx.map.map_width]);
	ft_start(&mlx);
	return (0);
}
