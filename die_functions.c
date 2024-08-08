/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:14:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/08 13:21:02 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_dead_mutex_lock(t_philo philosopher)
{
	if (pthread_mutex_trylock(&philosopher.dead_mutex) == 0)
	{
		philosopher.has_died = 1;
		pthread_mutex_unlock(&philosopher.dead_mutex);
	}
}
