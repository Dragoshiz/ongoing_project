/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:14:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/12 12:24:57 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_pec_errmsg(void)
{
	perror("The map must contain at least 1 E, 1 C, and 1 P");
	exit(1);
}

void	ft_wall_errmsg(void)
{
	perror("Wall must be rectangular and closed by 1s");
	exit(1);
}

void	ft_map_errmsg(void)
{
	perror("Wrong simbol used! Simbols allowed PEC10");
	exit(1);
}

void	ft_empty_errmsg(void)
{
	perror("Map file is empty!");
	exit(1);
}
