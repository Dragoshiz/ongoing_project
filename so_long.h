/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:19:16 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/12 12:36:02 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_mlx
{
	void	*mlx_pointer;
	void	*window;
}t_mlx;
typedef struct s_map
{
	int		map_height;
	int		map_width;
	char	*line;
}t_map;
void	ft_pec_errmsg(void);
void	ft_empty_errmsg(void);
void	ft_wall_errmsg(void);
void	ft_map_errmsg(void);
int		ft_check_sizenwall(t_map *map);
void	ft_check_pec10(t_map *map);
int		ft_get_map(t_map *map, char *argv);
int		main(int argc, char *argv[]);

#endif
