/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation_check_functions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/26 16:31:52 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_checker_thread(t_input_data *data)
{
	pthread_create(&data->checker_thread, NULL, \
		&routine_stop_simulation_check, data);
}

void	*routine_stop_simulation_check(void *arg)
{
	t_input_data	*data;

	data = (t_input_data *)arg;
	usleep(100);
	while (data->stop_simulation == 0)
	{
		check_one_philo_died(data);
		check_all_philos_ate(data);
	}
	return (NULL);
}

void	check_one_philo_died(t_input_data *data)
{
	int				i;
	u_int64_t		last_meal_time;

	i = 0;
	while (i < data->nr_of_philos)
	{
		last_meal_time = get_last_meal_time(&data->philos[i]);
		if (get_current_timestamp_in_ms() - last_meal_time >= \
			data->philos[i].time_to_die)
		{
			print_mutex_lock(&data->philos[i], "died");
			pthread_mutex_lock(&data->stop_simulation_mutex);
			data->stop_simulation = 1;
			pthread_mutex_unlock(&data->stop_simulation_mutex);
			return ;
		}
		i++;
	}
}

void	check_all_philos_ate(t_input_data	*data)
{
	int	i;
	int	number_of_full_philos;

	while (data->stop_simulation == 0)
	{
		i = 0;
		number_of_full_philos = 0;
		while (i < data->nr_of_philos)
		{
			if (data->philos[i].minimum_number_of_meals == -1)
				return ;
			pthread_mutex_lock(&data->nr_of_meals_mutex);
			if (data->philos[i].nr_of_meals >= \
			data->philos[i].minimum_number_of_meals)
				number_of_full_philos++;
			pthread_mutex_unlock(&data->nr_of_meals_mutex);
			i++;
		}
		if (number_of_full_philos == data->nr_of_philos)
		{
			pthread_mutex_lock(&data->stop_simulation_mutex);
			data->stop_simulation = 1;
			pthread_mutex_unlock(&data->stop_simulation_mutex);
		}
	}
}
