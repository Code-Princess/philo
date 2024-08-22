/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/22 12:10:25 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_dead_checker_thread(t_input_data *data)
{
	pthread_t dead_checker_thread;
	
	pthread_create(&dead_checker_thread, NULL, &routine_set_philosopher_dead, data);
	pthread_join(dead_checker_thread, NULL);
}

int	one_philo_died(t_input_data *data)
{
printf("HERE IN one_philo_died\n\n\n\n\n");
	int		i;
	
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->philos[i].has_died == 1)
			{
				printf("philo nr: %d has died: %d\n", data->philos[i].id_nr, data->philos[i].has_died);
				return (1);
			}
		else
			i++;
	}
	return (0);
	
}

void	*routine_set_philosopher_dead(void *arg)
{
	t_input_data	*data;

	data = (t_input_data *)arg;

	int	 i;

//printf("routine_set_philosopher_dead\n\n\n\n\n");	
		usleep(1000);
		while (1)
		{
			i = 0;
			while (i < data->number_of_philosophers)
			{
				if (get_current_timestamp_in_ms() - data->philos[i].time_of_last_meal >= data->philos[i].time_to_die)
				{
					//printf("check %llu %llu\n", get_current_timestamp_in_ms() - data->philos[i].time_of_last_meal, data->philos[i].time_to_die);
					//printf("check %llu %llu %llu\n", get_current_timestamp_in_ms(), data->philos[i].time_of_last_meal, data->philos[i].time_to_die);
					print_mutex_lock(&data->philos[i], "died");
					exit(0);
					if (pthread_mutex_lock(&(data->philos[i].dead_mutex)) == 0)
					{
						data->philos[i].has_died = 1;
						pthread_mutex_unlock(&(data->philos[i].dead_mutex));
						return (NULL);
					}
				}
				i++;
			}
			//return (NULL);
		}
}
