/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:29 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/13 18:56:38 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_xpm(char c, t_mlx *mlx, t_map *map)
{
	map->wall = "srcs/wall.xpm";
	map->turd = "srcs/turd.xpm";
	map->exit = "srcs/exit.xpm";
	map->player = "srcs/down-fly.xpm";
	if (c == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, map->wall,
				&map->width, &map->height);
	else if (c == 'C')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, map->turd,
				&map->width, &map->height);
	else if (c == 'E')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, map->exit,
				&map->width, &map->height);
	else if (c == 'P')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, map->player,
				&map->width, &map->height);
}

void	ft_put_tiles(t_mlx *mlx, t_map *map)
{
	int		i;
	int		x;
	int		y;
	char	*tile;

	tile = "srcs/tile.xpm";
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, tile, &map->width, &map->height);
	i = 0;
	x = 0;
	y = 0;
	while (map->line[i])
	{
		mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
		x += 64;
		if (x == 64 * map->map_width)
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

// void	ft_put_wall(t_mlx *mlx, t_map *map)
// {
// 	int		i;
// 	int		x;
// 	int		y;
// 	char	*wall;

// 	wall = "srcs/wall.xpm";
// 	mlx->img = mlx_xpm_file_to_image(mlx->ptr, wall, &map->width, &map->height);
// 	i = 0;
// 	x = 0;
// 	y = 0;
// 	while (map->line[i])
// 	{
// 		if (map->line[i] == '1')
// 			mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
// 		x += 64;
// 		if (x == 64 * map->map_width)
// 		{
// 			y += 64;
// 			x = 0;
// 		}
// 		i++;
// 	}
// }

// 4some reason segfaults the new function check it!!!
void	ft_put_collect(t_mlx *mlx, t_map *map)
{
	int		i;
	int		x;
	int		y;
	// char	*clect;

	// clect = "srcs/turd.xpm";
	// mlx->img = mlx_xpm_file_to_image(mlx->ptr, clect,
	// 		&map->width, &map->height);
	i = 0;
	x = 0;
	y = 0;
	while (map->line[i])
	{
		ft_put_xpm(map->line[i], mlx, map);
		mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
		x += 64;
		if (x == 64 * map->map_width)
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

void	ft_start(t_mlx *mlx, t_map *map)
{
	mlx->ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->ptr, map->map_width * 64,
			map->map_height * 64, "so_long");
	ft_put_tiles(mlx, map);
	// ft_put_wall(mlx, map);
	ft_put_collect(mlx, map);
	mlx_loop(mlx->ptr);
}
