/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/22 19:45:05 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_dead_checker_thread(t_input_data *data)
{
	pthread_create(&data->dead_checker_thread, NULL, &routine_set_philosopher_dead, data);
}

void	*routine_set_philosopher_dead(void *arg)
{
	t_input_data	*data;
	int	 i;

	data = (t_input_data *)arg;
	usleep(100);
	while (data->stop_simulation == 0)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			if (get_current_timestamp_in_ms() - data->philos[i].time_of_last_meal >= data->philos[i].time_to_die)
			{
				print_mutex_lock(&data->philos[i], "died");
				pthread_mutex_lock(&(data->philos[i].dead_mutex));
				data->philos[i].has_died = 1;
				pthread_mutex_unlock(&(data->philos[i].dead_mutex));
				pthread_mutex_lock(&(data->philos[i].stop_simulation_mutex));
				data->stop_simulation = 1;
				pthread_mutex_unlock(&(data->philos[i].stop_simulation_mutex));
				break ;
			}
			i++;
		}
	}
	return (NULL);
}
