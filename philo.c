/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/26 15:36:04 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	*argv[])
{
	t_input_data		*data;

	if (argc == 5 || argc == 6)
	{
		if (input_check(argc, argv) == 0)
		{
			data = input_data_init(argv);
			data->philos = philos_init(data->nr_of_philos, argc, argv, data);
			create_checker_thread(data);
			pthread_join(data->checker_thread, NULL);
			join_philo_threads(data->philos, data->nr_of_philos);
			destroy_forks(data->number_of_forks, data->forks);
			free(data->forks);
			free(data->philos);
			free(data);
		}
		else
			return (printf("Error\nInvalid input arguments\n"), 1);
	}
	else
	{
		printf("Error\nWrong number of arguments!\n");
		return (1);
	}
}
