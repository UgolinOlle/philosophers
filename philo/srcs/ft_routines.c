/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:54:54 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/22 17:36:02 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Routine for one philosopher.
 *
 * @param void *arg - Philosopher structure.
 * @return void
 */
static void	*ft_alone_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_action_sleep(philo->global->tt_die);
	ft_status(philo, "died");
	return (NULL);
}

/**
 * @brief Routine for one philosopher.
 *
 * @param t_global *global - Global structure.
 * @return void
 */
void	ft_alone(t_global *global)
{
	global->t_start = ft_get_time();
	pthread_create(&global->philo[0].thread, NULL, &ft_alone_routine,
		&global->philo[0]);
}

/**
 * @brief Stop routine for one philosopher.
 *
 * @param t_global *global - Global structure.
 * @return void
 */
void	ft_alone_stop(t_global *global)
{
	pthread_join(global->philo[0].thread, NULL);
	ft_clean_global(global);
}
