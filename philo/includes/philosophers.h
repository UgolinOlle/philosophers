/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:47 by uolle             #+#    #+#             */
/*   Updated: 2024/01/29 15:25:36 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_P
#define PHILO_P

// -- Libs
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// -- Structures
typedef struct s_data {
  time_t s_time;
  time_t tt_die;
  time_t tt_eat;
  time_t tt_sleep;
  pthread_mutex_t *fork_locked;
  unsigned int n_philo;
} t_data;

typedef struct s_philo {
  pthread_t thread;
  unsigned int id;
  unsigned int t_ate;
  unsigned int t_last_ate;
  unsigned int fork[2];
  t_data *data;
} t_philo;

#endif
