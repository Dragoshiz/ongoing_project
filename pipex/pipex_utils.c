/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:51:02 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/23 17:47:36 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//finds path environment var, splits by ':' and saves.
void	ft_path(char *env[], t_vars *vars)
{
	int		i;
	int		k;
	int		j;
	char	*path;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			path = ft_strdup(env[i]);
		i++;
	}
	i = 5;
	vars->paths = ft_split(path, ':');
	k = ft_strlen(vars->paths[0]);
	j = 0;
	while (i <= k)
	{
		vars->paths[0][j] = vars->paths[0][i];
		i++;
		j++;
	}
	vars->paths[0][j] = '\n';
	free(path);
}

//checks if files exists and if readable/writeble is valid
void	ft_exist(char *argv[])
{
	int	fd;

	fd = access(argv[1], R_OK);
	if (fd < 0)
	{
		write(1, "First file does not exist/not readable", 38);
		exit(0);
	}
}

//function to put above functions in one place + checking argument number
void	ft_check(int argc, char *argv[], char *env[], t_vars *vars)
{
	if (argc != 5)
	{
		write(1, "Pipex must have 4 arguments!", 28);
		exit(1);
	}
	ft_exist(argv);
	ft_path(env, vars);
	
}

void	ft_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->paths[i])
	{
		free(vars->paths[i]);
		i++;
	}
}

//function to write errmsg and exit program
void	ft_errmsg(int err)
{
	if (err == 0)
		write(1, "Error with pipe function", 24);
	if (err == 1)
		write(1, "Error with fork function", 24);
	if (err == 2)
		write(1, "Error opening the file 1", 24);
	exit(1);
}
