/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:19:16 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/16 17:55:40 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# define TILE "srcs/tile.xpm"
# define WALL "./srcs/wall.xpm"
# define COLLECT "srcs/turd.xpm"
# define EXITC "srcs/c-door.xpm"
# define EXITO "srcs/o-door.xpm"
# define PLAYER "srcs/down-fly.xpm"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

typedef struct s_map
{
	size_t	map_width;
	size_t	map_height;
	int		player;
	int		x;
	int		y;
	int		width;
	int		height;
	int		collect;
	char	*line;
}t_map;
typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_map	map;
}t_mlx;
void	ft_mv_w(t_mlx *mlx);
int		ft_keypress(int key, t_mlx *mlx);
void	ft_pec_errmsg(void);
void	ft_empty_errmsg(void);
void	ft_wall_errmsg(void);
void	ft_map_errmsg(void);
void	ft_start(t_mlx *mlx);
void	ft_check_sizenwall(t_mlx *mlx);
void	ft_check_pec10(t_mlx *mlx);
int		ft_get_map(t_mlx *mlx, char *argv);
int		main(int argc, char *argv[]);

#endif
