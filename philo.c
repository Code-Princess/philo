/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/21 19:04:52 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// #include "dev_helper_functions.h"

int	main(int argc, char	*argv[])
{
	static t_input_data		*data;
	if (argc == 5 || argc == 6)
	{
		if (input_check(argc, argv) == 0)
		{
			data = input_data_init(argv);
			data->philos = philos_init(data->number_of_philosophers, argc, argv, data);
			create_dead_checker_thread(data);
			if (one_philo_died(data) == 1)
			{
printf("IF: one philo died\n");	
				return (0);
			}
				
			// free_data(data); TODO: free functions
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
