/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:30:09 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/21 14:53:23 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_vars
{
	char	**paths;
}t_vars;

int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif