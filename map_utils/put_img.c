/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:29 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/17 19:14:55 by dimbrea          ###   ########.fr       */
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
	if (c == 'E')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, EXITC,
				&mlx->map.width, &mlx->map.height);
	if (c == 'E' && mlx->map.collect == 0)
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "srcs/o-door.xpm",
				&mlx->map.width, &mlx->map.height);
	if (c == 'P')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, mlx->map.p_path,
				&mlx->map.width, &mlx->map.height);
	if (c == 'X')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, mlx->map.x_path,
				&mlx->map.width, &mlx->map.height);
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

int	ft_loop(t_mlx *mlx)
{
	static int	i;

	if (i == 21)
		i = 0;
	if (i == 5)
		mlx->map.x_path = "srcs/web.xpm";
	if (i == 10)
		mlx->map.x_path = "srcs/web-2.xpm";
	if (i == 15)
		mlx->map.x_path = "srcs/web-3.xpm";
	if (i == 20)
		mlx->map.x_path = "srcs/web-4.xpm";
	i++;
	ft_dstroy_n_put(mlx);
	return (0);
}

void	ft_start(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->window = mlx_new_window(mlx->ptr, mlx->map.map_width * 64,
			mlx->map.map_height * 64, "so_long");
	ft_put_tiles(mlx);
	ft_put_all(mlx);
	mlx_hook(mlx->window, 2, (1L << 0), ft_keypress, mlx);
	mlx_hook(mlx->window, 17, 0L, ft_x, mlx);
	mlx_loop_hook(mlx->ptr, &ft_loop, mlx);
	mlx_loop(mlx->ptr);
}
