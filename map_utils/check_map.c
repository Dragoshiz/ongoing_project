/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:14:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/10 15:53:16 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_get_map(t_map *map, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	while ((map->line = get_next_line(fd)) > 0)
	{
		printf("%s", map->line);
		map->map_height++;
	}
	printf("%d", map->map_height);
	return (0);
}
