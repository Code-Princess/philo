/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/02 13:57:25 by llacsivy         ###   ########.fr       */
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
		i++;
	}
	return (philos);
}
