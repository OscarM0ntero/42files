/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:08:08 by omontero          #+#    #+#             */
/*   Updated: 2022/10/02 12:48:15 by oscar            ###   ########.fr       */
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
	//	Se inicializan y van variando su valor en base al estado actual
	//	de la ordenacion
	int		lowest_number_in_order;
	int		numbers_in_order;
	//	Se inicializan y no se cambia
	int		highest_number;
	int		lowest_number;
	int		total_amount_of_numbers;
}			t_data;

#endif