/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:29:25 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/23 17:53:03 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//temp variable to be freed
//function to check if command exists
//todo: split command argument by space and pass that into this function
char	*ft_cmnd_chk(t_vars *vars, char *argv[])
{
	int		i;
	char	*temp;

	i = 0;
	while (vars->paths[i])
	{
		temp = ft_strjoin(vars->paths[i], argv[2]);
		if (access(temp, F_OK) == 0)
			return (temp);
		else
		{
			free(temp);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	t_vars	vars;
	int		i;

	// ft_c2heck(argc, argv, env, &vars);
	// if (pipe(vars.fd) < 0)
	// 	ft_errmsg(0);
	i = 0;
	// if (access("/bin/wc", F_OK) == 0)
	// 	printf("GOOD");
	// else
	// 	printf("BAD");
	// while(vars.paths[i])
	// {	
	// 	printf("%s\n", vars.paths[i]);
	// 	i++;
	// }
	// execve("/bin/ls", arg1, NULL);
	return (0);
}
