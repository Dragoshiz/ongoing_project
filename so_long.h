/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:19:16 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/10 15:53:13 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
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
	int		readval;
	char	*line;
}t_map;
int				ft_get_map(t_map *map, char *argv);
static char		**ft_dest_row(char const *s, char c, char **dest, int rows);

#endif