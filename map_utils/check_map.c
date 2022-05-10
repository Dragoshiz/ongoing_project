/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:14:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/10 19:02:30 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_get_map(t_map *map, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	map->map_width = ft_strlen(line) - 1;
	map->line = ft_strdup_nonl(line);
	free(line);
	while ((line = get_next_line(fd)) > 0)
	{
		map->line = ft_strjoin(map->line, line);
	}
	printf("%s", map->line);
	return (0);
}
