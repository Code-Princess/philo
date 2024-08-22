/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:41:05 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/22 23:00:35 by llacsivy         ###   ########.fr       */
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
	pthread_mutex_t nr_of_meals_mutex;
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
	u_int64_t		start_time_program;
	int				times_eaten;
	int				number_of_philosophers;
	int				*stop_simulation;
	pthread_mutex_t	stop_simulation_mutex;
	int				minimum_number_of_meals;
}	t_philo;

typedef struct s_input_data
{
	int				number_of_philosophers;
	int				number_of_forks;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	u_int64_t		start_time_program;
	pthread_t		dead_checker_thread;
	int				stop_simulation;
	int				all_eaten;
	pthread_t		checker_thread;
}	t_input_data;

u_int64_t			get_current_timestamp_in_ms();
void				print_state_log(int id, char	*state_log, u_int64_t start_time_program);
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
int					all_philosophers_ate_nbr_of_meals(t_philo *philos);
void				*routine_set_philosopher_dead(void *arg);
void				create_dead_checker_thread(t_input_data *data);
void				print_philo(t_philo *philo);
void				join_philo_threads(t_philo *philos, int nr_of_philos);
int					stop_simulation_mutex_check(t_philo *philo);
void 				create_checker_thread(t_input_data *data);
void 				*routine_set_all_philos_eaten(void *arg);
void				*routine_stop_simulation_check(void *arg);
void 				check_all_philos_ate(t_input_data	*data);

#endif