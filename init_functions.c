/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/18 13:41:11 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_input_data	*input_data_init(char **input_argv)
{
	t_input_data	*data;

	data = malloc(1 * sizeof(t_input_data));
	if (data == NULL)
		return (NULL);
	data->number_of_philosophers = ft_atoi(input_argv[1]);
	data->number_of_forks = ft_atoi(input_argv[1]);
	data->start_time = get_current_timestamp_in_ms();
	data->forks = forks_init(data->number_of_forks);
	return (data);
}

int	create_philo_threads(t_philo *philos, int nr_of_philos)
{
	int			i;

	i = 0;
	while (i < nr_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < nr_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}

t_philo	*philos_init(int nbr_of_philos, int argc, char **input_argv, \
	t_input_data *data)
{
	static t_philo	*philos;

	philos = malloc(sizeof(t_philo) * nbr_of_philos);
	if (philos == NULL)
		return (NULL);
	set_philosophers_init_values(argc, input_argv, data, philos);
	create_philo_threads(philos, nbr_of_philos);
	return (philos);
}

void	set_philosophers_init_values(int argc, char **input_argv, \
	t_input_data *data, t_philo *philos)
{
	int		i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philos[i].id_nr = i + 1;
		philos[i].has_died = 0;
		philos[i].nr_of_meals = 0;
		philos[i].time_to_die = ft_atoi(input_argv[2]);
		philos[i].time_to_eat = ft_atoi(input_argv[3]);
		philos[i].time_to_sleep = ft_atoi(input_argv[4]);
		philos[i].number_of_times_each_philosopher_must_eat = 0;
		if (argc == 6)
			philos[i].number_of_times_each_philosopher_must_eat = \
			ft_atoi(input_argv[5]);
		philos[i].fork_left = &data->forks[i];
		if (philos[i].id_nr >= 1)
			philos[i].fork_right = &data->forks[i - 1];
		else
			philos[i].fork_right = &data->forks[data->number_of_philosophers \
			- 1];
		pthread_mutex_init(&(philos[i].print_mutex), NULL);
		pthread_mutex_init(&(philos[i].eat_mutex), NULL);
		i++;
	}
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
