/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/25 13:56:50 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_input_data	*input_data_init(char **input_argv)
{
	t_input_data	*data;

	data = malloc(1 * sizeof(t_input_data));
	if (data == NULL)
		return (NULL);
	data->nr_of_philos = ft_atoi(input_argv[1]);
	data->number_of_forks = ft_atoi(input_argv[1]);
	data->start_time_program = get_current_timestamp_in_ms();
	data->forks = forks_init(data->number_of_forks);
	data->stop_simulation = 0;
	data->all_eaten = 0;
	return (data);
}

pthread_mutex_t	*forks_init(int nr_of_forks)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * nr_of_forks);
	if (forks == NULL)
		return (NULL);
	while (i < nr_of_forks)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}
