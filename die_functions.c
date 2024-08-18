/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/18 13:39:35 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_check_one_philo_died(void *arg)
{
	t_input_data	*data;

	data = (t_input_data *)arg;
	int		i;
	
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->philos[i]->has_died == 1)
			return ((void	*)1);
		else
			i++;
	}
	return ((void	*)0);
	
}

void	set_dead_mutex_lock(t_philo philosopher)
{
	if (pthread_mutex_trylock(&philosopher.dead_mutex) == 0)
	{
		philosopher.has_died = 1;
		pthread_mutex_unlock(&philosopher.dead_mutex);
	}
}
void create_dead_checker_thread(t_input_data *data)
{
	pthread_t dead_checker_thread;
	
	pthread_create(&dead_checker_thread, NULL, &routine_check_one_philo_died, data);
	pthread_join(dead_checker_thread, NULL);
}

