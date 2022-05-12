/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:40:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/12 17:41:57 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_pixel_input(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_map	map;
	int		width;
	int		heigth;
	char	*turd;

	turd = "./srcs/turd.xpm";
	if (argc != 2) 
		return (0);
	// ft_get_map(&map, argv[1]);
	mlx.ptr = mlx_init();
	// mlx.window = mlx_new_window(mlx.ptr, 1920, 1080, "turd");
	// mlx.img = mlx_new_image(mlx.ptr, 1920, 1080);
	// mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp,
	// 		&mlx.line_length, &mlx.endian);
	mlx.img = mlx_xpm_file_to_image(mlx.ptr, turd, &width, &heigth);
	// mlx_put_image_to_window(mlx.ptr, mlx.window, mlx.img, 0, 0);
	// mlx_loop(mlx.ptr);
	return (0);
}
