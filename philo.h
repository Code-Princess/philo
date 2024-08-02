/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:41:05 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/02 13:58:26 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_philo
{
	int	id_nr;	
}	t_philo;

typedef struct s_input_data
{
	int	number_of_philosophers;
	int	number_of_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_input_data;

long long	get_current_timestamp_in_ms(void);
void		print_state_log(int id, char	*state_log);
void		input_data_init(t_input_data *data, char **input_argv);
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
long		ft_atol(char *str);
int			input_check(char **input_argv);
t_philo		*philos_init(int nbr_of_philos);
#endif