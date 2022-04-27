/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:26:06 by omontero          #+#    #+#             */
/*   Updated: 2022/04/07 14:41:20 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

struct		s_parameters;
int			ft_first_check(struct s_parameters *param, int x, int y);
int			*ft_second_check(struct s_parameters *param, int x, int y);
int			ft_move_square(struct s_parameters *param);
int			*ft_move_square2(struct s_parameters *param);
void		ft_assign_matrix_size(struct s_parameters *param);
void		ft_print_matrix(struct s_parameters *param);
void		ft_write_square(struct s_parameters *param, int *esc);
void		ft_matrix_assign(char *argv, struct s_parameters *param);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
int			ft_check_all_matrix_lines(char *argv, struct s_parameters *param,
				int i);
int			ft_extract_width(char *argv, struct s_parameters *param);
int			ft_check_height(char *argv, struct s_parameters *param);
void		ft_assign_things(struct s_parameters *param, char *str);

#endif
