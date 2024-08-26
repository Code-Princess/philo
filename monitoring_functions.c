/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:29:55 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/26 15:43:10 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state_log(int id, char	*state_log, \
	u_int64_t start_time_program)
{
	long long	timestamp_in_ms;

	timestamp_in_ms = get_current_timestamp_in_ms() - start_time_program;
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
	if (stop_simulation_mutex_check(philo) == 1)
		return ;
	pthread_mutex_lock(philo->print_mutex);
	print_state_log(philo->id_nr, state_log, philo->start_time_program);
	pthread_mutex_unlock(philo->print_mutex);
}

void	ft_usleep(u_int64_t time_to_do_sth)
{
	u_int64_t	start_timestamp;

	start_timestamp = get_current_timestamp_in_ms();
	while (get_current_timestamp_in_ms() - start_timestamp < time_to_do_sth)
		usleep(100);
}
