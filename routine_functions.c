/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:46:59 by linda             #+#    #+#             */
/*   Updated: 2024/08/26 17:08:07 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (stop_simulation_mutex_check(philo) == 0)
	{
		if (philo->id_nr % 2 == 0)
		{
			thinking(philo);
			ft_usleep(philo->time_to_eat / 2);
		}
		while (stop_simulation_mutex_check(philo) == 0)
		{
			eating(philo);
			sleeping(philo);
			thinking(philo);
		}
	}
	return (NULL);
}

void	eating(t_philo *philosopher)
{
	if (stop_simulation_mutex_check(philosopher) == 1)
		return ;
	pthread_mutex_lock(philosopher->fork_left);
	print_mutex_lock(philosopher, "has taken a fork");
	if (*philosopher->nr_of_philos == 1)
	{
		ft_usleep(philosopher->time_to_die);
		pthread_mutex_unlock(philosopher->fork_left);
		return ;
	}
	pthread_mutex_lock(philosopher->fork_right);
	print_mutex_lock(philosopher, "has taken a fork");
	print_mutex_lock(philosopher, "is eating");
	set_last_meal_time(philosopher);
	ft_usleep(philosopher->time_to_eat);
	philosopher->nr_of_meals++;
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
}

void	sleeping(t_philo *philosopher)
{
	if (stop_simulation_mutex_check(philosopher) == 1)
		return ;
	print_mutex_lock(philosopher, "is sleeping");
	ft_usleep(philosopher->time_to_sleep);
}

void	thinking(t_philo *philosopher)
{
	if (stop_simulation_mutex_check(philosopher) == 1)
		return ;
	print_mutex_lock(philosopher, "is thinking");
}
