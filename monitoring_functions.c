/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:29:55 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/20 12:37:59 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state_log(int id, char	*state_log)
{
	long long	timestamp_in_ms;

	timestamp_in_ms = get_current_timestamp_in_ms();
	printf("%lld %d %s\n", timestamp_in_ms, id, state_log);
}

u_int64_t	get_current_timestamp_in_ms(void)
{
	struct timeval	timestamp;
	u_int64_t		timestamp_in_ms;

	gettimeofday(&timestamp, NULL);
	timestamp_in_ms = (timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000);
	return (timestamp_in_ms);
}

void	print_mutex_lock(t_philo *philo, char *state_log)
{
	if (philo->has_died == 0)
	{
		if (pthread_mutex_trylock(&philo->print_mutex) == 0)
		{
			print_state_log(philo->id_nr, state_log);
			pthread_mutex_unlock(&philo->print_mutex);
		}
	}
}
