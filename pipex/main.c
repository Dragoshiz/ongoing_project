/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:29:25 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/21 16:33:43 by dimbrea          ###   ########.fr       */
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
	int	fd[2];

	fd[0] = access(argv[1], R_OK);
	fd[1] = access(argv[4], W_OK);
	if (fd[0] < 0)
	{
		write(1, "First file does not exist/not readable", 38);
		exit(0);
	}
	if (fd[1] < 0)
	{
		write(1, "Second file does not exist/not writable", 39);
		exit(0);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_vars	vars;
	int		i;

	i = 0;
	if (argc != 5)
	{
		write(1, "Program must have 4 arguments!", 30);
		return (1);
	}
	ft_exist(argv);
	ft_path(env, &vars);
	// while (vars.paths[i])
	// {
	// 	// printf("%s\n", vars.paths[i]);
	// 	i++;
	// }
	while (vars.paths[i])
	{
		free(vars.paths[i]);
		i++;
	}
	return (0);
}
