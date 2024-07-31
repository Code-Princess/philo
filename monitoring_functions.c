/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:29:55 by llacsivy          #+#    #+#             */
/*   Updated: 2024/07/31 15:13:14 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state_log(int id, char	*state_log)
{
	long long	timestamp_in_ms;

	timestamp_in_ms = get_current_timestamp_in_ms();
	printf("%lld %d %s\n", timestamp_in_ms, id, state_log);
}

long long	get_current_timestamp_in_ms(void)
{
	struct timeval	timestamp;
	long long		timestamp_in_ms;

	gettimeofday(&timestamp, NULL);
	timestamp_in_ms = timestamp.tv_sec * 1000 + timestamp.tv_usec / 1000;
	return (timestamp_in_ms);
}
