/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/01 13:59:53 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	*argv[])
{
	t_input_data	*data;

	if (argc != 5)
	{
		printf("Error\nWrong number of arguments! To run the program please use:\n./philo [number_of_philosophers] [time_to_die] \
	[time_to_eat] [time_to_sleep]\n");
		return (1);
	}
	else
	{
		if(input_check(argv) == 0)
		{
			if (ft_atoi(argv[1]) >= 1)
			{
				data = malloc(1 * sizeof(t_input_data));
				input_data_init(data, argv);
				printf("valid input\n");
				return (0);
			}
		}
		else
			return (printf("Error\nInvalid input arguments\n"), 1);

	}
}
