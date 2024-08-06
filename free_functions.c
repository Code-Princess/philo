/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:06:45 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/06 10:39:26 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_input_data	*input_data)
{
	int	i;

	i = 0;
	free(input_data->philos);
	while (i < input_data->number_of_forks)
	{
		pthread_mutex_destroy(&input_data->forks[i]);
		i++;
	}
	free(input_data->forks);
	free(input_data);
	input_data->philos = NULL;
	input_data->forks = NULL;
	input_data = NULL;
}
