/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:58 by omontero          #+#    #+#             */
/*   Updated: 2023/01/17 13:39:48 by omontero         ###   ########.fr       */
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
# include <semaphore.h>

typedef struct s_fork
{
	int  ;
}			t_fork;

typedef struct s_philo
{
	int			num;
	int			action;
	int			is_alive;
	int			time_since_eat;
	int			time_eating;
	int			time_sleeping;
	int			times_eaten;
	int			forks_in_hand;
	int			need_print;
	void		*agora;
	time_t		last_time_check;
	pthread_t	thread;
}			t_philo;

typedef struct s_agora
{
	time_t	time;
	t_philo	*philos;
	sem_t	*forks;
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_times_must_eat;
	int		forks_in_use;
}			t_agora;

#endif
