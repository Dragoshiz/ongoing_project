/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:30:09 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/23 17:48:09 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_vars
{
	char	**paths;
	char	**arg1;
	int		fd[2];
	int		pid1;
	int		pid2;
	int		fdfile1;
	int		fdfile2;
}t_vars;

void	ft_path(char *env[], t_vars *vars);
void	ft_exist(char *argv[]);
void	ft_check(int argc, char *argv[], char *env[], t_vars *vars);
void	ft_free(t_vars *vars);
void	ft_errmsg(int err);

#endif