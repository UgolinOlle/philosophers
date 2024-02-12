/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:47 by uolle             #+#    #+#             */
/*   Updated: 2024/02/12 15:31:30 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_P
# define PHILO_P

// ------------------------------------------------- //
// -- Libs                                           //
// ------------------------------------------------- //
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// ------------------------------------------------- //
// -- Variable                                       //
// ------------------------------------------------- //
# define PHILO_NAME "philo:"
# define PHILO_USAGE \
	"%s usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]\n"

// ------------------------------------------------- //
// -- Structures                                     //
// ------------------------------------------------- //
typedef struct s_philo
{
	time_t			s_time;
	time_t			tt_die;
	time_t			tt_eat;
	time_t			tt_sleep;
	unsigned int	t_ate;
	unsigned int	t_last_ate;
}					t_philo;

typedef struct s_global
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	n_philo;
	pthread_mutex_t	*fork_locked;
	t_philo			**philos;
}					t_global;

// ------------------------------------------------- //
// -- Prototypes                                     //
// ------------------------------------------------- //

// -- Error handling
void				*ft_free(t_global *global);
void				ft_destroy_mutex(t_global *global);
void				ft_exit(t_global *global, char *content);

// -- Utils
int					ft_write(char *content, int code);

#endif
