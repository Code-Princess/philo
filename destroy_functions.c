/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:06:45 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/26 12:45:16 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(int number_of_forks, pthread_mutex_t	*forks)
{
	int	i;

	i = 0;
	while (i < number_of_forks)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
