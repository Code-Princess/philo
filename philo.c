/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:40:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/07/31 15:43:03 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	*argv[])
{
	t_input_data	*data;

	if (argc != 5)
	{
		printf("Error\nWrong input number! Please use 4 input arguments!");
		return (1);
	}
	else
	{
		data = malloc(1 * sizeof(t_input_data));
		input_data_init(data, argv);
		return (0);
	}
}
