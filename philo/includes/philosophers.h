/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:24:58 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/16 10:54:51 by ugolin-olle      ###   ########.fr       */
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

// -- Structures
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				t_ate;
	int				ate_count;
	int				fork[2];
	struct s_global	*global;
}					t_philo;

typedef struct s_global
{
	int				n_philo;
	time_t			t_start;
	time_t			tt_die;
	time_t			tt_eat;
	time_t			tt_sleep;
	int				n_must_eat;
	pthread_mutex_t	*forks_locked;
	t_philo			**philos;
}					t_global;

// -- Error
void				ft_exit(char *msg, int status);

// -- Init
t_global			*ft_init_global(int argc, char **argv);

// -- Utils
int					ft_is_digit(char *c);
int					ft_atoi(const char *str);
void				ft_print_global(t_global *global);
void				ft_print_args(int argc, char **argv);

#endif
