/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:29 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/16 18:44:23 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Funcion to put images accordingly
void	ft_put_xpm(char c, t_mlx *mlx, int x, int y)
{
	if (c == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, WALL,
				&mlx->map.width, &mlx->map.height);
	if (c == 'C')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, COLLECT,
				&mlx->map.width, &mlx->map.height);
	else if (c == 'E')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, EXITC,
				&mlx->map.width, &mlx->map.height);
	if (c == 'P')
	{
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, PLAYER,
				&mlx->map.width, &mlx->map.height);
		mlx->map.x = x;
		mlx->map.y = y;
	}
}

//Function to render the background image
void	ft_put_tiles(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	mlx->img = mlx_xpm_file_to_image(mlx->ptr, TILE,
			&mlx->map.width, &mlx->map.height);
	i = 0;
	x = 0;
	y = 0;
	while (mlx->map.line[i])
	{
		mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
		x += 64;
		if (x == 64 * mlx->map.map_width)
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

//Function to put all images
void	ft_put_all(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (mlx->map.line[i])
	{
		if (mlx->map.line[i] != '0')
		{
			ft_put_xpm(mlx->map.line[i], mlx, x, y);
			mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
		}
		x += 64;
		if (x == 64 * mlx->map.map_width)
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

// void	ft_update_map(t_mlx *mlx, t_map *map)
// {
// 	mlx_xpm_file_to_image(mlx->ptr, PLAYER,&map->width, &map->height);
// 	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, ml, 128);
// }
int ft_nxt_frame(t_mlx *mlx)
{
	ft_put_all(&mlx);
	return(0);
}
void	ft_start(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->ptr, mlx->map.map_width * 64,
			mlx->map.map_height * 64, "so_long");
	ft_put_tiles(mlx);
	ft_put_all(mlx);
	mlx_hook(mlx->window, 17, 0L, ft_keypress, &mlx);
	mlx_key_hook(mlx->window, ft_keypress, &mlx);
	// mlx_loop_hook(mlx->ptr, ft_nxt_frame(mlx), &mlx);
	mlx_loop(mlx->ptr);
}
