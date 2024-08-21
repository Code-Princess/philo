/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/21 13:28:55 by llacsivy         ###   ########.fr       */
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
	
	pthread_create(&dead_checker_thread, NULL, &routine_set_philosopher_dead, data);
	pthread_join(dead_checker_thread, NULL);
}

void	*routine_set_philosopher_dead(void *arg)
{
	t_input_data	*data;

	data = (t_input_data *)arg;

	int	 i;

	while(1)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			if (get_current_timestamp_in_ms() - data->philos[i].time_of_last_meal >= data->philos[i].time_to_die)
			{
				print_mutex_lock(&data->philos[i], "died", data->start_time_program);
				if (pthread_mutex_lock(&(data->philos[i].dead_mutex)) == 0)
				{
					data->philos[i].has_died = 1;
					data->stop_simulation = 1;
					pthread_mutex_unlock(&(data->philos[i].dead_mutex));
					return (NULL);
				}
			}
			i++;
		}
		usleep(10);
	}
}
