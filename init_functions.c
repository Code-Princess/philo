/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:14:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/07/31 15:38:39 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_data_init(t_input_data *data, char **input_argv)
{
	data->number_of_philosophers = ft_atoi(input_argv[1]);
	data->number_of_forks = ft_atoi(input_argv[1]);
	data->time_to_die = ft_atoi(input_argv[2]);
	data->time_to_eat = ft_atoi(input_argv[3]);
	data->time_to_sleep = ft_atoi(input_argv[4]);
}
