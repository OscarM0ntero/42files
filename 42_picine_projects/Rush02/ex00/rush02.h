/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:10:37 by carmgarc          #+#    #+#             */
/*   Updated: 2022/04/07 11:00:47 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdio.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*number_to_word(char *str, char *dic);
void	print_number(char *str, char *dic);
void	putstr(char *str);
void	print_separator(int j, char *dic);
char	*get_number(int j);
void	next_line(int *fd, int *i);
int		check_number_length(int len, char *dic);
void	remove_initial_zeros(char **str);
int		ft_realloc(char **str, char sign);
void	print_between(int j, char *dic);
void	move_index(int *k, int *l);

#endif
