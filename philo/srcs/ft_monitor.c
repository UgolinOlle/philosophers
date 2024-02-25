/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:40:09 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/25 11:27:22 by ugolin-olle      ###   ########.fr       */
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
	pthread_mutex_lock(&global->philo[i].meal_mutex);
	if (ft_get_time() - global->philo[i].t_last_meal >= global->tt_die)
	{
		pthread_mutex_lock(&global->philo[i].global->dead_mutex);
		global->philo_dead = 1;
		pthread_mutex_unlock(&global->philo[i].global->dead_mutex);
		pthread_mutex_unlock(&global->philo[i].meal_mutex);
		ft_status(&global->philo[i], "died");
	}
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
			pthread_mutex_unlock(&global->philo[i].meal_mutex);
			i++;
		}
	}
	return (NULL);
}
