/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:14:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/11 17:11:53 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_errmsg(void)
{
	perror("There's something wrong with the map!");
	exit(1);
}

void	ft_check_pec10(t_map *map)
{
	int		i;
	int		j;
	char	*pec10;

	pec10 = "PEC10";
	i = 0;
	j = 0
	while (map->line[i++])
	{
		
	}
}

int	ft_check_sizenwall(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_height * map->map_width != ft_strlen(map->line))
		ft_map_errmsg();
	while (i++ < map->map_width)
		if (map->line[i] != '1')
			ft_map_errmsg();
	i = ft_strlen(map->line) - map->map_width - 1;
	while (i++ < ft_strlen(map->line) - 1)
		if (map->line[i] != '1')
			ft_map_errmsg();
	i = map->map_width;
	while (i < ft_strlen(map->line) - map->map_width - 1)
	{
		if (map->line[i] == '1')
			i += map->map_width - 1;
		else
			ft_map_errmsg();
		if (map->line[i] == '1')
			i += 1;
		else
			ft_map_errmsg();
	}
	return (1);
}

int	ft_get_map(t_map *map, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_map_errmsg();
	map->map_width = ft_strlen(line) - 1;
	map->line = ft_strdup_nonl(line);
	free(line);
	while (line != NULL)
	{
		map->map_height++;
		line = get_next_line(fd);
		if (line)
		{	
			map->line = ft_strjoin(map->line, line);
			free(line);
		}
	}
	// free(map->line);free somewhere map->line
	ft_check_sizenwall(map);
	printf("%s",map->line);
	return (1);
}
