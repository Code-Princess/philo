/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/07/31 16:57:02 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	*argv[])
{
	t_input_data	*data;

	if (argc != 5)
	{
		printf("Error\nWrong input number! To run the program please use:\n./philo [number_of_philosophers] [time_to_die] \
	[time_to_eat] [time_to_sleep]\n");
		return (1);
	}
	else
	{
		data = malloc(1 * sizeof(t_input_data));
		input_data_init(data, argv);
		return (0);
	}
}
