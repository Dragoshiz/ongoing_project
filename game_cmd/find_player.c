/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:06:55 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/16 18:46:59 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//GETTING segfault when pressing 'ESC, W'
int	ft_keypress(int key, t_mlx *mlx)
{
	if (key == ESC)
		write(1, "ESC\n", 4);
	if (key == W)
		ft_mv_w(mlx);
	if (key == A)
		write(1, "A\n", 2);
	if (key == S)
		write(1, "S\n", 2);
	if (key == D)
		write(1, "D\n", 2);
	if (key == UP)
		write(1, "UP\n", 3);
	if (key == LEFT)
		write(1, "LEFT\n", 5);
	if (key == DOWN)
		write(1, "DOWN\n", 5);
	if (key == RIGHT)
		write(1, "RIGHT\n", 6);
	return (0);
}

void	ft_mv_w(t_mlx *mlx)
{
	//put collectible here
	char temp;
	
	if (mlx->map.line[mlx->map.player - mlx->map.map_width] == '0')
	{
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.line[mlx->map.player - mlx->map.map_width] = 'P';
	}
	// write(1, "HELLO", 5);
}
