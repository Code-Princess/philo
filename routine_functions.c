/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:46:59 by linda             #+#    #+#             */
/*   Updated: 2024/08/22 22:46:09 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	while (stop_simulation_mutex_check(philo) == 0)
	{
		
		if (philo->id_nr % 2 == 0)
		{
			thinking(philo);
			ft_usleep(philo->time_to_eat / 2);
		}
		while (philo->has_died == 0)
		{
			if (stop_simulation_mutex_check(philo) == 1)
					return (NULL);
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
		return;
	pthread_mutex_lock(philosopher->fork_left);
	print_mutex_lock(philosopher, "has taken a fork");
	if (philosopher->number_of_philosophers == 1)
	{
		ft_usleep(philosopher->time_to_die);
		pthread_mutex_unlock(philosopher->fork_left);
		return;
	}
	pthread_mutex_lock(philosopher->fork_right);
	print_mutex_lock(philosopher, "has taken a fork");
	pthread_mutex_lock(&philosopher->eat_mutex);
	print_mutex_lock(philosopher, "is eating");
	ft_usleep(philosopher->time_to_eat);
	philosopher->time_of_last_meal = get_current_timestamp_in_ms();
	philosopher->nr_of_meals++;
	pthread_mutex_unlock(&philosopher->eat_mutex);
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
}

int stop_simulation_mutex_check(t_philo *philo)
{
	int	result;
	
	pthread_mutex_lock(&philo->stop_simulation_mutex);
	if (*philo->stop_simulation == 1)
		result = 1;
	else 
		result = 0;
	pthread_mutex_unlock(&philo->stop_simulation_mutex);
	return (result);
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
	if (stop_simulation_mutex_check(philosopher) == 1)
		return;
	print_mutex_lock(philosopher, "is sleeping");
	ft_usleep(philosopher->time_to_sleep);
}

void	thinking(t_philo *philosopher)
{	if (stop_simulation_mutex_check(philosopher) == 1)
		return;
	print_mutex_lock(philosopher, "is thinking");
}
