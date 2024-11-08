/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:58 by omontero          #+#    #+#             */
/*   Updated: 2023/01/23 15:01:14 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>

# define COLOUR_GREEN "\033[0;32m"
# define COLOUR_RED "\033[0;31m"
# define COLOUR_BLUE "\033[0;34m"
# define COLOUR_GREY "\033[0;37m"
# define COLOUR_YELLOW "\033[1;33m"

typedef struct s_agora	t_agora;

typedef struct s_philo
{
	pid_t			pid;
	int				num;
	int				is_alive;
	int				times_eaten;
	int				enough_meals;
	sem_t			*status;
	uint64_t		last_meal_time;
	t_agora			*agora;
}			t_philo;

typedef struct s_agora
{
	t_philo			*philos;
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;
	sem_t			*meals_achieved;
	uint64_t		init_time;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*dead;
	sem_t			*finish;
}			t_agora;

//	philo_inits_bonus.c

void		init_semaphores(t_agora *agora);
void		init_philos(t_agora *agora);
int			init_agora(t_agora *agora, char **argv);
void		init_threads(t_agora *agora);

//	philo_routine_bonus.c

void		eat(t_philo *philo);
void		*philo_routine(void *arg);
void		routine(t_philo *philo);

//	philo_time_bonus.c

uint64_t	time_now(uint64_t t);
void		my_sleep(uint64_t ms);

//	philo_print_bonus.c

char		*get_time_and_philo(t_philo *philo);
char		*color_selector(char *s, char *action);
void		print_action(t_philo *philo, char *action);

//	philo_libft_bonus.c

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

//	philo_atoi_itoa_bonus.c

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);

//	philo_death_bonus.c

void		keep_philo_alive(t_philo *philo);
int			check_times_eaten(t_philo *philo);
void		take_philo_soul(t_philo *philo);
void		*death_routine(void *arg);

//	philo_bonus.c

void		check_on_philo(t_agora *agora);

void		*finish(void *arg);
void		*meals_control(void *arg);
#endif
