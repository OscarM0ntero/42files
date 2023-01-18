/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:58 by omontero          #+#    #+#             */
/*   Updated: 2023/01/18 15:55:00 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <time.h>
# include <pthread.h>

typedef struct s_agora	t_agora;

typedef struct s_philo
{
	int				num;
	int				action;
	int				is_alive;
	int				last_meal_time;
	int				times_eaten;
	t_agora			*agora;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	fork;
	uint64_t		last_time_check;
	pthread_t		thread;
}			t_philo;

typedef struct s_agora
{
	uint64_t		time;
	t_philo			*philos;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;
	pthread_mutex_t	print;
}			t_agora;

#endif
