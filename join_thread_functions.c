/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:24:20 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/23 15:27:35 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philo_threads(t_philo *philos, int nr_of_philos)
{
	int			i;

	i = 0;
	while (i < nr_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
