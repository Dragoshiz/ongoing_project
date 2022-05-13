/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:14:51 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/13 18:50:41 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_extension(char *argv)
{
	int	end;

	end = ft_strlen(argv) - 1;

	if (argv[end] == 'r' && argv[end - 1] == 'e'
		&& argv[end - 2] == 'b' && argv[end - 3] == '.')
		return ;
	else
	{
		perror("Map must be with a .ber extension.");
		exit(1);
	}
}

void	ft_check_pec(t_map *map)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (map->line[i])
	{
		if (map->line[i] == 'P')
			p++;
		if (map->line[i] == 'E')
			e++;
		if (map->line[i] == 'C')
			c++;
		i++;
	}
	if (p == 0 || e == 0 || c == 0)
		ft_pec_errmsg();
}

void	ft_check_pec10(t_map *map)
{
	int		i;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i] != 'P' && map->line[i] != 'E'
			&& map->line[i] != 'C' && map->line[i] != '1'
			&& map->line[i] != '0')
			ft_map_errmsg();
		i++;
	}
}

void	ft_check_sizenwall(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_height * map->map_width != ft_strlen(map->line))
		ft_wall_errmsg();
	while (i++ < map->map_width)
		if (map->line[i] != '1')
			ft_wall_errmsg();
	i = ft_strlen(map->line) - map->map_width - 1;
	while (i++ < ft_strlen(map->line) - 1)
		if (map->line[i] != '1')
			ft_wall_errmsg();
	i = map->map_width;
	while (i < ft_strlen(map->line) - map->map_width - 1)
	{
		if (map->line[i] == '1')
			i += map->map_width - 1;
		else
			ft_wall_errmsg();
		if (map->line[i] == '1')
			i += 1;
		else
			ft_wall_errmsg();
	}
}

// free(map->line);free somewhere map->line
int	ft_get_map(t_map *map, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_empty_errmsg();
	map->map_width = ft_strlen(line) - 1;
	map->line = ft_strdup_nonl(line);
	free(line);
	while (line != NULL)
	{
		map->map_height += 1;
		printf("%d", map->map_height);
		line = get_next_line(fd);
		if (line)
		{	
			map->line = ft_strjoin(map->line, line);
			free(line);
		}
	}
	ft_check_extension(argv);
	ft_check_sizenwall(map);
	ft_check_pec10(map);
	ft_check_pec(map);
	return (1);
}
