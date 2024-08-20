/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/20 12:50:04 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	*routine_check_one_philo_died(void *arg)
{
	t_input_data	*data;

	data = (t_input_data *)arg;
	int		i;
	
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->philos[i].has_died == 1)
			return ((void	*)1);
		else
			i++;
	}
	return ((void	*)0);
	
} */

void create_dead_checker_thread(t_input_data *data)
{
	pthread_t dead_checker_thread;
	
	// pthread_create(&dead_checker_thread, NULL, &routine_check_one_philo_died, data);
	pthread_create(&dead_checker_thread, NULL, &routine_set_philosopher_dead, data->philos);
	pthread_join(dead_checker_thread, NULL);
}

/* void set_philosopher_dead(t_philo *philo)
{
	if (get_current_timestamp_in_ms() - philo->time_of_last_meal >= philo->time_to_die)
	{
		print_mutex_lock(philo, "died");
		if (pthread_mutex_trylock(&(philo->dead_mutex)) == 0)
		{
			philo->has_died = 1;
			pthread_mutex_unlock(&(philo->dead_mutex));
		}
	}
} */

void	*routine_set_philosopher_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	if (get_current_timestamp_in_ms() - philo->time_of_last_meal >= philo->time_to_die)
	{
		print_mutex_lock(philo, "died");
		if (pthread_mutex_trylock(&(philo->dead_mutex)) == 0)
		{
			philo->has_died = 1;
			pthread_mutex_unlock(&(philo->dead_mutex));
		}
	}
	return (NULL);
}

int one_philo_died(t_input_data *data)
{
	int		i;
	
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->philos[i].has_died == 1)
			return (1);
		else
			i++;
	}
	return (0);
	
}

