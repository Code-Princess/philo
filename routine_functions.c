/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:46:59 by linda             #+#    #+#             */
/*   Updated: 2024/08/08 13:35:52 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->has_died == 0)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	print_mutex_lock(philo, "died");
	return (NULL);
}

void	eating(t_philo *philosopher)
{
	if (pthread_mutex_trylock(philosopher->fork_left) == 0)
	{
		print_mutex_lock(philosopher, "has taken a fork");
		if (pthread_mutex_trylock(philosopher->fork_right) == 0)
		{
			print_mutex_lock(philosopher, "has taken a fork");
			if (pthread_mutex_trylock(&philosopher->eat_mutex) == 0)
			{
				print_mutex_lock(philosopher, "is eating");
				ft_usleep(philosopher->time_to_eat);
				philosopher->time_of_last_meal = get_current_timestamp_in_ms();
				philosopher->nr_of_meals++;
				pthread_mutex_unlock(&philosopher->eat_mutex);
				pthread_mutex_unlock(philosopher->fork_left);
				pthread_mutex_unlock(philosopher->fork_right);
			}
		}
	}
}

void	ft_usleep(u_int64_t time_to_do_sth)
{
	u_int64_t	start_timestamp;

	start_timestamp = get_current_timestamp_in_ms();
	while (get_current_timestamp_in_ms() - start_timestamp < time_to_do_sth)
		usleep(100);
}

void	sleeping(t_philo *philosopher)
{
	print_mutex_lock(philosopher, "is sleeping");
	ft_usleep(philosopher->time_to_sleep);
}

void	thinking(t_philo *philosopher)
{
	print_mutex_lock(philosopher, "is thinking");
}
