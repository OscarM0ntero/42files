/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:08 by omontero          #+#    #+#             */
/*   Updated: 2022/11/22 14:39:04 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

//		Structs
typedef struct s_value
{
	int		val;
	int		pos;
}			t_value;

typedef struct s_stack
{
	t_value	*stk;
	int		size;
}			t_stack;

typedef struct s_data
{
	int		highest_number_dis;
	int		lowest_number_ord;
	int		numbers_in_order;
	int		highest_number;
	int		lowest_number;
	int		total_amount_of_numbers;
	int		x;
	int		error;
}			t_data;

//	push_swap_utils.c
void		ft_add_to_stack(t_stack *stack, int new_val, int pos);
void		ft_remove_from_stack(t_stack *stack, int pos);
void		read_stack(t_stack a, t_stack b);

//	push_swap_push.c
void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);

//	push_swap_swap.c
void		ft_sa(t_stack *a, int print);
void		ft_sb(t_stack *b, int print);
void		ft_ss(t_stack *a, t_stack *b);

//	push_swap_rotate.c
void		ft_ra(t_stack *a, int print);
void		ft_rb(t_stack *b, int print);
void		ft_rr(t_stack *a, t_stack *b);

//	push_swap_reverse_rotate.c
void		ft_rra(t_stack *a, int print);
void		ft_rrb(t_stack *b, int print);
void		ft_rrr(t_stack *a, t_stack *b);

//	push_swap_sorter.c
void		rotate_extract_10_higher(t_stack *a, t_stack *b, t_data *data);
void		extract_in_order(t_stack *a, t_stack *b, t_data *data);
void		realloc_a(t_stack *a, t_data *data);
void		order_a(t_stack *a, t_data *data);

//	push_swap_sorter_large.c
void		rotate_extract_100_higher(t_stack *a, t_stack *b, t_data *data);

//	push_swap_sorter_generic.c
void		rotate_extract_x_higher(t_stack *a, t_stack *b, t_data *data);
void		organize_3(t_stack *a, t_data *data);

//	push_swap_sorter_utils.c
int			s_h(t_stack x);
int			search_higher_pos(t_stack x);
int			search_lower(t_stack x);
int			search_num_pos(t_stack x, int val);
int			search_higher_und_x(t_stack x, int max);

//	push_swap_checkval
long		ft_atoi_long(const char *nptr, t_data *data);
int			ft_check_rep(t_stack *a, t_data *data);

#endif