/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:40:09 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/03/04 16:08:23 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Monitor check death of philosophers.
 *
 * @param t_global *global - Global structure.
 * @param int i - Index of the philosopher.
 * @return void
 */
static void	ft_monitor_check_death(t_global *global, int i)
{
	time_t	current;

	pthread_mutex_lock(&global->philo[i].meal_mutex);
	current = ft_get_time();
	if (current > (global->philo[i].t_last_meal + global->tt_die))
	{
		pthread_mutex_lock(&global->dead_mutex);
		global->philo_dead = 1;
		pthread_mutex_unlock(&global->dead_mutex);
		ft_status(&global->philo[i], "died");
	}
	else
		pthread_mutex_unlock(&global->philo[i].meal_mutex);
}

/**
 * @brief Monitor check if philosopher is full.
 *
 * @param t_global *global - Global structure.
 * @param int i - Index of the philosopher.
 * @return void
 */
static void	ft_monitor_check_full(t_global *global, int i)
{
	if (global->max_meal_count != -1
		&& global->philo[i].meal_count == global->max_meal_count)
		global->philo_full++;
}

/**
 * @brief Check if all philo are full by number of philos
 *
 * @param t_global *global - Global structure.
 * @return int - 1 if all philo are full, 0 if not.
 */
static int	ft_monitor_check_health(t_global *global)
{
	if (global->philo_full >= global->nb_philo)
	{
		usleep(1000);
		return (1);
	}
	return (0);
}

/**
 * @brief Monitor the philosophers.
 *
 * @param void *arg - Global structure.
 * @return void
 */
void	*ft_monitor(void *arg)
{
	t_global	*global;
	int			i;

	global = (t_global *)arg;
	while (global->philo_dead != 1)
	{
		i = 0;
		while (i < global->nb_philo)
		{
			ft_monitor_check_death(global, i);
			if (global->philo_dead == 1)
				return (NULL);
			ft_monitor_check_full(global, i);
			i++;
			if (ft_monitor_check_health(global) == 1)
				return (NULL);
		}
		if (ft_monitor_check_health(global) == 1)
			return (NULL);
	}
	return (NULL);
}
