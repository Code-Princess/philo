/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/04 22:15:55 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_data_init(t_input_data *data, char **input_argv)
{
	data->number_of_philosophers = ft_atoi(input_argv[1]);
	data->number_of_forks = ft_atoi(input_argv[1]);
	data->time_to_die = ft_atoi(input_argv[2]);
	data->time_to_eat = ft_atoi(input_argv[3]);
	data->time_to_sleep = ft_atoi(input_argv[4]);
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
	philos = malloc(sizeof(t_philo) * nbr_of_philos); // TODO LEAKS
	if (philos == NULL)
		return (NULL);
	while (i < nbr_of_philos)
	{
		philos[i].id_nr = i + 1;
		i++;
	}
	create_philo_threads(philos, nbr_of_philos);
	return (philos);
}
