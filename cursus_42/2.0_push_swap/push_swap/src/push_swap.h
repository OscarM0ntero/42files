/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:08 by omontero          #+#    #+#             */
/*   Updated: 2022/06/12 21:46:13 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

//		Structs
typedef struct s_value
{
	int		val;
	size_t	pos;
}	t_value;

typedef struct s_stack
{
	t_value	*stk;
	size_t	size;
}	t_stack;

typedef struct s_game
{
	char	**argv;
	t_stack	a;
	t_stack	b;
}	t_game;

//			push_swap.c

//			push_swap_utils.c
t_stack		ft_assign_stack(t_stack old_stk, t_value new_val, int assign);
t_game		ft_add_to_stack(t_game g, t_value new_val, int a, int b);
t_stack		ft_remove(t_stack old_stk, size_t pos);
t_game		ft_remove_from_stack(t_game g, size_t pos, int a, int b);

//			push_swap_swap.c
t_game		ft_sa(t_game game, int print);
t_game		ft_sb(t_game game, int print);
t_game		ft_ss(t_game game);

//			push_swap_push.c
t_game		ft_pa(t_game g, int print);
t_game		ft_pb(t_game g, int print);

//			push_swap_rotate.c
t_game		ft_ra(t_game g, int print);
t_game		ft_rb(t_game g, int print);
t_game		ft_rr(t_game g);

#endif