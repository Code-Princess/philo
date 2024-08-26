/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:40:37 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/26 15:45:56 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(philo->time_of_last_meal_mutex);
	philo->time_of_last_meal = get_current_timestamp_in_ms();
	pthread_mutex_unlock(philo->time_of_last_meal_mutex);
}

u_int64_t	get_last_meal_time(t_philo *philo)
{
	u_int64_t	time_of_last_meal;

	pthread_mutex_lock(philo->time_of_last_meal_mutex);
	time_of_last_meal = philo->time_of_last_meal;
	pthread_mutex_unlock(philo->time_of_last_meal_mutex);
	return (time_of_last_meal);
}

int	stop_simulation_mutex_check(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(philo->stop_simulation_mutex);
	result = *philo->stop_simulation;
	pthread_mutex_unlock(philo->stop_simulation_mutex);
	return (result);
}
