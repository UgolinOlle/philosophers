/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:24:58 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/25 11:26:54 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// -- Libraries
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// -- Defines
# define PHILO_USAGE "Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"
# define PHILO_INPUT_ERROR "Invalid input"
# define PHILO_MALLOC_ERROR "An error occured, malloc failed."
# define PHILO_MUTEX_ERROR "An error occured, mutex init failed."
# define PHILO_THREAD_ERROR "An error occured, thread creation failed."

// -- Structures
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meal;
	int				meal_count;
	time_t			t_last_meal;
	unsigned int	left_fork;
	unsigned int	right_fork;
	pthread_mutex_t	meal_mutex;
	struct s_global	*global;
}					t_philo;

typedef struct s_global
{
	time_t			t_start;
	int				nb_philo;
	time_t			tt_die;
	time_t			tt_eat;
	time_t			tt_sleep;
	int				max_meal_count;
	int				philo_dead;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	pthread_t		monitor;
	t_philo			*philo;
}					t_global;

// -- Actions
void				ft_action_sleep(t_philo *philo);
void				ft_action_eat(t_philo *philo);
void				ft_action_think(t_philo *philo);

// -- Alone routine
void				ft_alone(t_global *global);
void				ft_alone_stop(t_global *global);

// -- Cleaner
void				ft_exit(t_global *global, char *msg, int status);
void				*ft_clean_global(t_global *global);

// -- Init
t_global			*ft_init_global(int argc, char **argv);

// -- Monitor
void				*ft_monitor(void *arg);

// -- Rountines
void				ft_launch_routine(t_global *global);
void				ft_stop_routine(t_global *global);
void				*ft_routine(void *arg);

// -- Utils
int					ft_is_digit(char *c);
int					ft_atoi(const char *str);
time_t				ft_get_time(void);
void				ft_status(t_philo *philo, char *status);
int					ft_is_dead(t_philo *philo);

#endif
