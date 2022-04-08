/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:56:32 by dimbrea           #+#    #+#             */
/*   Updated: 2022/04/08 19:21:58 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_counter
{
	int	an_index;
	int	count_a;
	int	count_b;
	int	count_index;
	int	count_temp;
	int	argc;
	int	*s_st;
	int	*idx_st;
	int	*tmp_st;
	int	*sorted_st;
	int	bit;
}t_counter;
int		ft_atoi(const char *str);
int		ft_isdigit(int ch);
void	ft_check_mxint(long sum);
void	ft_err_msg(void);
int		*ft_convert2int(int argc, char *argv[]);
void	ft_check_isnum(int argc, char *argv[]);
void	ft_check_dup(int argc, int *a_stack);
void	ft_switch(int *stack);
void	ft_sa(int *a_stack);
void	ft_sb(int *b_stack);
void	ft_ss(int *a_stack, int *b_stack);
void	ft_copy_stack_n_add(int argc, int *copy2, int *copyfrom);
void	ft_copy_stack_n_crop(int argc, int *copy2, int *copyfrom);
void	ft_pa(t_counter *i, int *a_stack, int *b_stack);
void	ft_remv_elem(int size, int *stack);
void	ft_put_elem(int size, int *stack);
void	ft_pb(t_counter *i, int *a_stack, int *b_stack);
void	ft_rotate(int size, int *stack);
void	ft_ra(int size, int *a_stack);
void	ft_rb(int size, int *b_stack);
void	ft_rr(t_counter *size, int *a_stack, int *b_stack);
void	ft_reverse_rotate(int size, int *stack);	
void	ft_rra(int size, int *a_stack);
void	ft_rrb(int size, int *b_stack);
void	ft_rrr(t_counter *i, int *a_stack, int *b_stack);
bool	ft_is_ordered(t_counter *count, int *a_stack);
int		*ft_get_sorted(t_counter *count, int *a_stack);
int		*ft_get_indexes(t_counter *i, int *a_stack);
void	ft_radix(t_counter *i, int *a_stack, int *b_stack);
void	ft_push(int *to_add, int *to_subt, int *stk_add, int *stk_subt);
void	ft_sort3(t_counter *k, int *a_stack);

#endif
