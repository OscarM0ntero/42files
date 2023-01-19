/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:58 by omontero          #+#    #+#             */
/*   Updated: 2023/01/19 00:11:06 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_agora	t_agora;

typedef struct s_philo
{
	int				num;
	int				is_alive;
	int				times_eaten;
	uint64_t		last_meal_time;
	t_agora			*agora;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	fork;
	pthread_t		thread;
}			t_philo;

typedef struct s_agora
{
	t_philo			*philos;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;
	int				meals_achieved;
	int				corpse_found;
	uint64_t		init_time;
	pthread_mutex_t	print;
}			t_agora;

#endif
