/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/03 22:02:58 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	*argv[])
{
	static t_input_data		*data;
	static t_philo			*philosophers;

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
			data = malloc(1 * sizeof(t_input_data));
			if (data == NULL)
				return (1);
			input_data_init(data, argv);
			philosophers = philos_init(data->number_of_philosophers);
			return (free(data), data = NULL, \
				free(philosophers), philosophers = NULL, 0);
		}
		else
			return (printf("Error\nInvalid input arguments\n"), 1);
	}
}
