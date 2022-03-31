/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:56:32 by dimbrea           #+#    #+#             */
/*   Updated: 2022/03/31 18:19:28 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

int			ft_atoi(const char *str);
int			ft_isdigit(int ch);
void		ft_check_mxint(long sum);
void		ft_err_msg(void);
int			*ft_convert2int(int argc, char *argv[]);
void		ft_check_isnum(int argc, char *argv[]);
void		ft_check_dup(int argc, int *a_stack);

#endif
