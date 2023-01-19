/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omontero <omontero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:27:53 by omontero          #+#    #+#             */
/*   Updated: 2023/01/19 13:50:29 by omontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//	Returns a string with the actual time stamp in ms and
//	the number of the current philosopher
char	*get_time_and_philo(t_philo *philo)
{
	char	*s1;
	char	*s2;
	char	*tmp;

	s1 = ft_itoa(time_now(philo->agora->init_time));
	s2 = ft_itoa(philo->num);
	tmp = s1;
	s1 = ft_strjoin(s1, "  ms ");
	free (tmp);
	tmp = s1;
	s1 = ft_strjoin(s1, "		");
	free (tmp);
	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free (tmp);
	free (s2);
	return (s1);
}

//	Selects a color for the output based on the action and returns the string
//	with the color added
char	*color_selector(char *s, char *action)
{
	char	*f;

	if (ft_strncmp(action, "fork", 4) == 0)
		f = ft_strjoin(COLOUR_YELLOW, s);
	else if (ft_strncmp(action, "eat", 3) == 0)
		f = ft_strjoin(COLOUR_GREEN, s);
	else if (ft_strncmp(action, "sleep", 5) == 0)
		f = ft_strjoin(COLOUR_GREY, s);
	else if (ft_strncmp(action, "think", 5) == 0)
		f = ft_strjoin(COLOUR_BLUE, s);
	else if (ft_strncmp(action, "died", 4) == 0)
		f = ft_strjoin(COLOUR_RED, s);
	free (s);
	return (f);
}

//	Prints philosopher action changes
void	print_action(t_philo *philo, char *action)
{
	char	*s;
	char	*f;

	pthread_mutex_lock(&philo->agora->print);
	s = get_time_and_philo(philo);
	s = color_selector(s, action);
	if (ft_strncmp(action, "fork", 4) == 0)
		f = ft_strjoin(s, " has taken a fork\n");
	else if (ft_strncmp(action, "eat", 3) == 0)
		f = ft_strjoin(s, " is eating\n");
	else if (ft_strncmp(action, "sleep", 5) == 0)
		f = ft_strjoin(s, " is sleeping\n");
	else if (ft_strncmp(action, "think", 5) == 0)
		f = ft_strjoin(s, " is thinking\n");
	else if (ft_strncmp(action, "died", 4) == 0)
		f = ft_strjoin(s, " died\n");
	if (!philo->agora->corpse_found || (philo->agora->corpse_found
			&& !ft_strncmp(action, "died", 4)))
		write (1, f, ft_strlen(f));
	free (s);
	free (f);
	pthread_mutex_unlock(&philo->agora->print);
}
