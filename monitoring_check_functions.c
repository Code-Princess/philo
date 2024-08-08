/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_check_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:02:24 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/08 13:09:55 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_philosophers_ate(t_philo *philos, t_input_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (philos[i].nr_of_meals >= \
			philos[i].number_of_times_each_philosopher_must_eat)
			i++;
		else
			return (1);
	}
	return (0);
}
