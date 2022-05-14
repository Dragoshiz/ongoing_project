/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:19:16 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/14 18:04:25 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# define WALL "./srcs/wall.xpm"
# define COLLECT "srcs/turd.xpm"
# define EXITC "srcs/c-door.xpm"
# define EXITO "srcs/o-door.xpm"
# define PLAYER "srcs/down-fly.xpm"
# define ESC 0x35

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}t_mlx;
typedef struct s_map
{
	size_t	map_width;
	size_t	map_height;
	int		width;
	int		height;
	int		collect;
	char	*line;
	char	*tile;
	char	*wall;
	char	*turd;
	char	*exit;
	char	*player;
}t_map;

void	ft_pec_errmsg(void);
void	ft_empty_errmsg(void);
void	ft_wall_errmsg(void);
void	ft_map_errmsg(void);
void	ft_start(t_mlx *mlx, t_map *map);
void	ft_check_sizenwall(t_map *map);
void	ft_check_pec10(t_map *map);
int		ft_get_map(t_map *map, char *argv);
int		main(int argc, char *argv[]);

#endif
