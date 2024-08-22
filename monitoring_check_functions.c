/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_check_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:02:24 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/21 19:53:26 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_philosophers_ate_nbr_of_meals(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->number_of_times_each_philosopher_must_eat)
	{
		if (philos[i].nr_of_meals >= \
			philos[i].number_of_times_each_philosopher_must_eat)
			i++;
		else
			return (0);
	}
	return (1);
}
