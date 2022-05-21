/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:29:25 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/21 14:21:15 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//finds path environment var and saves it.
char	*ft_path(char *env[])
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		printf("%s", env[i]);
		if (ft_strncmp(env[i], "PATH", 4))
			path = ft_strdup(env[i]);
		i++;
	}
	return (path);
}

//this function checks if files exists and if readable/writeble is valid
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
	char	*path;

	if (argc != 5)
	{
		write(1, "Program must have 4 arguments!", 30);
		return (1);
	}
	ft_exist(argv);
	path = ft_path(env);
	// printf("%s", path);
	return (0);
}
