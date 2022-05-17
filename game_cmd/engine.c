/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:06:55 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/17 16:49:56 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//destroys img and rerender it
void	ft_dstroy_n_put(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.line[i++])
		if (mlx->map.line[i] == 'P')
			mlx->map.player = i;
	mlx_destroy_image(mlx->ptr, mlx->img);
	write(1, ft_itoa(mlx->map.steps), sizeof(int));
	write(1, "\n", 1);
	ft_put_tiles(mlx);
	ft_put_all(mlx);
}

//exit function
void	ft_esc(t_mlx *mlx)
{
	if (mlx->map.collect == 0)
		write(1, "YOU WON!", 8);
	write(1, "Exited game!", 12);
	mlx_destroy_window(mlx->ptr, mlx->window);
	exit(0);
}

//when pressing x
int	ft_x(void)
{
	write(1, "Exited game!", 12);
	exit(0);
	return (0);
}

//when you touch enemy
void	ft_game_over(void)
{
	write(1, "You touched the enemey, GAME OVER!", 34);
	exit(0);
}

//Check the key pressed
int	ft_keypress(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_esc(mlx);
	else if (key == W || key == UP)
		ft_mv_w(mlx);
	else if (key == A || key == LEFT)
		ft_mv_a(mlx);
	else if (key == S || key == DOWN)
		ft_mv_s(mlx);
	else if (key == D || key == RIGHT)
		ft_mv_d(mlx);
	return (0);
}
