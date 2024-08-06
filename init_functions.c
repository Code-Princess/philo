/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/06 10:50:29 by llacsivy         ###   ########.fr       */
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
	data->time_to_die = ft_atoi(input_argv[2]);
	data->time_to_eat = ft_atoi(input_argv[3]);
	data->time_to_sleep = ft_atoi(input_argv[4]);
	data->start_time = get_current_timestamp_in_ms();
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

t_philo	*philos_init(int nbr_of_philos)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * nbr_of_philos);
	if (philos == NULL)
		return (NULL);
	while (i < nbr_of_philos)
	{
		philos[i].id_nr = i + 1;
		philos[i].has_died = 0;
		philos[i].nr_of_meals = 0;
		i++;
	}
	create_philo_threads(philos, nbr_of_philos);
	return (philos);
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
