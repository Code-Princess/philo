/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:46:59 by linda             #+#    #+#             */
/*   Updated: 2024/08/04 21:01:39 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_state_log(philo->id_nr, "has taken a fork");
	print_state_log(philo->id_nr, "is eating");
	print_state_log(philo->id_nr, "is sleeping");
	print_state_log(philo->id_nr, "is thinking");
	print_state_log(philo->id_nr, "died");
	return (NULL);
}
