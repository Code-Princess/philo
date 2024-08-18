/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:41:05 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/18 13:39:39 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct s_philo
{
	int				id_nr;
	int				nr_of_meals;
	int				has_died;	
	u_int64_t		time_of_last_meal;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	dead_mutex;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}	t_philo;

typedef struct s_input_data
{
	int				number_of_philosophers;
	int				number_of_forks;
	t_philo			**philos;
	pthread_mutex_t	*forks;
	u_int64_t		start_time;
}	t_input_data;

u_int64_t			get_current_timestamp_in_ms(void);
void				print_state_log(int id, char	*state_log);
t_input_data		*input_data_init(char **input_argv);
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
long				ft_atol(char *str);
int					input_check(int argc, char **input_argv);
t_philo				*philos_init(int nbr_of_philos, int argc, \
					char **input_argv, t_input_data *data);
int					create_philo_threads(t_philo *philos, int nr_of_philos);
void				*routine(void *arg);
void				free_data(t_input_data	*input_data);
pthread_mutex_t		*forks_init(int nr_of_forks);
void				print_mutex_lock(t_philo *philo, char *state_log);
void				eating(t_philo *philosopher);
void				ft_usleep(u_int64_t time_to_do_sth);
void				sleeping(t_philo *philosopher);
void				thinking(t_philo *philosopher);
void				set_philosophers_init_values(int argc, char **input_argv, \
					t_input_data *data, t_philo *philos);
int					check_all_philosophers_ate(t_philo *philos, \
					t_input_data *data);
void				set_dead_mutex_lock(t_philo philosopher);
void				*routine_check_one_philo_died(void *arg);
void				create_dead_checker_thread(t_input_data *data);

#endif