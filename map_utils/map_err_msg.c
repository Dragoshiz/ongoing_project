/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:14:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/18 16:02:47 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_pec_errmsg(void)
{
	write(1, "Error\n", 6);
	write(1, "The map must contain at least 1 E, 1 C, and only 1 P", 52);
	exit(0);
}

void	ft_wall_errmsg(void)
{
	write(1, "Error\n", 6);
	write(1, "Wall must be rectangular and closed by 1s", 41);
	exit(0);
}

void	ft_map_errmsg(void)
{
	write(1, "Error\n", 6);
	write(1, "Wrong simbol used! Simbols allowed PEC10X", 41);
	exit(0);
}

void	ft_empty_errmsg(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_err(void)
{
	write(1, "Error opening the map", 21);
	exit(0);
}
