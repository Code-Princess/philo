/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:28:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/26 17:14:06 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_philo *philos, int nr_of_philos)
{
	int			i;

	i = 0;
	while (i < nr_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
	return (0);
}

t_philo	*philos_init(int nbr_of_philos, int argc, char **in_argv, \
	t_input_data *data)
{
	static t_philo	*philos;

	philos = malloc(sizeof(t_philo) * nbr_of_philos);
	if (philos == NULL)
		return (NULL);
	set_philos_values(argc, in_argv, data, philos);
	create_philo_threads(philos, nbr_of_philos);
	return (philos);
}

void	set_philos_values(int argc, char **in_argv, t_input_data *data, \
	t_philo *philos)
{
	int		i;

	i = 0;
	while (i < data->nr_of_philos)
	{
		philos[i].nr_of_philos = &data->nr_of_philos;
		philos[i].stop_simulation = &data->stop_simulation;
		philos[i].id_nr = i + 1;
		philos[i].nr_of_meals = 0;
		philos[i].time_to_die = ft_atoi(in_argv[2]);
		philos[i].time_to_eat = ft_atoi(in_argv[3]);
		philos[i].time_to_sleep = ft_atoi(in_argv[4]);
		philos[i].start_time_program = data->start_time_program;
		philos[i].minimum_number_of_meals = -1;
		philos[i].time_of_last_meal = get_current_timestamp_in_ms();
		set_philo_mutexes(&philos[i], data);
		if (argc == 6)
			philos[i].minimum_number_of_meals = ft_atoi(in_argv[5]);
		philos[i].fork_left = &data->forks[i];
		if (philos[i].id_nr > 1)
			philos[i].fork_right = &data->forks[i - 1];
		else
			philos[i].fork_right = &data->forks[data->nr_of_philos - 1];
		i++;
	}
}

void	set_philo_mutexes(t_philo *philo, t_input_data *data)
{
	philo->stop_simulation_mutex = &data->stop_simulation_mutex;
	philo->print_mutex = &data->print_mutex;
	philo->nr_of_meals_mutex = &data->nr_of_meals_mutex;
	philo->time_of_last_meal_mutex = &data->time_of_last_meal_mutex;
}
