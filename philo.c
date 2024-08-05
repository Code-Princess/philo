/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/05 12:48:23 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	*argv[])
{
	static t_input_data		*data;

	if (argc != 5)
	{
		printf("Error\nWrong number of arguments! To run the program please use:\n./philo [number_of_philosophers] [time_to_die] \
	[time_to_eat] [time_to_sleep]\n");
		return (1);
	}
	else
	{
		if (input_check(argv) == 0)
		{
			data = input_data_init(argv);
			data->philos = philos_init(data->number_of_philosophers);
			data->forks = forks_init(data->number_of_forks);
			return (free(data), data = NULL, \
				free(data->philos), data->philos = NULL, 0);
		}
		else
			return (printf("Error\nInvalid input arguments\n"), 1);
	}
}
