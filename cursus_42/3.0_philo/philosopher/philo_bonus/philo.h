/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:58 by omontero          #+#    #+#             */
/*   Updated: 2023/01/19 13:47:17 by omontero         ###   ########.fr       */
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

# define COLOUR_GREEN "\033[0;32m"
# define COLOUR_RED "\033[0;31m"
# define COLOUR_BLUE "\033[0;34m"
# define COLOUR_GREY "\033[0;37m"
# define COLOUR_YELLOW "\033[1;33m"

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

//	philo_inits.c

void		init_philos(t_agora *agora);
void		init_agora(t_agora *agora, char **argv);
void		init_threads(t_agora *agora);

//	philo_routine.c

void		eat(t_philo *philo);
void		keep_philo_alive(t_philo *philo);
int			check_times_eaten(t_philo *philo);
void		take_philo_soul(t_philo *philo);
void		*philo_routine(void *arg);

//	philo_time.c

uint64_t	time_now(uint64_t t);
void		my_sleep(uint64_t ms);

//	philo_print.c

char		*get_time_and_philo(t_philo *philo);
char		*color_selector(char *s, char *action);
void		print_action(t_philo *philo, char *action);

#endif
