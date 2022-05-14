/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:29 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/14 18:08:17 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Funcion to put images accordingly
void	ft_put_xpm(char c, t_mlx *mlx, t_map *map)
{
	if (c == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, WALL,
				&map->width, &map->height);
	if (c == 'C')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, COLLECT,
				&map->width, &map->height);
	else if (c == 'E')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, EXITC,
				&map->width, &map->height);
	if (c == 'P')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, PLAYER,
				&map->width, &map->height);
}

//Function to render the background image
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

//Function to put all images
void	ft_put_all(t_mlx *mlx, t_map *map)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (map->line[i])
	{
		if (map->line[i] != '0')
		{
			ft_put_xpm(map->line[i], mlx, map);
			mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
		}
		x += 64;
		if (x == 64 * map->map_width)
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

//GETTING segfault when pressing 'x'
//now dis works, continue from here!
int	ft_keypress(int key, t_mlx mlx)
{
	if (key == ESC)
		write(1, "ANYAD\n", 6);
	return (0);
}

void	ft_start(t_mlx *mlx, t_map *map)
{
	mlx->ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->ptr, map->map_width * 64,
			map->map_height * 64, "so_long");
	ft_put_tiles(mlx, map);
	ft_put_all(mlx, map);
	mlx_hook(mlx->window, 17, 0L, ft_keypress, &mlx);
	mlx_key_hook(mlx->window, ft_keypress, &mlx);
	mlx_loop(mlx->ptr);
}
