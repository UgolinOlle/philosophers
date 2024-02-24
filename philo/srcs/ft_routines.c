/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:54:54 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/25 00:25:00 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Launch routine for philosophers.
 *
 * @param t_global *global - Global structure.
 * @return void
 */
void	ft_launch_routine(t_global *global)
{
	int	i;

	i = 0;
	global->t_start = ft_get_time();
	while (i < global->nb_philo)
	{
		pthread_create(&global->philo[i].thread, NULL, &ft_routine,
			&global->philo[i]);
		i++;
	}
	pthread_create(&global->monitor, NULL, &ft_monitor, global);
}

/**
 * @brief Stop routine for philosophers.
 *
 * @param t_global *global - Global structure.
 * @return void
 */
void	ft_stop_routine(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		pthread_join(global->philo[i].thread, NULL);
		i++;
	}
	pthread_join(global->monitor, NULL);
	ft_clean_global(global);
}

/**
 * @brief Routine for philosophers.
 *
 * @param void *arg - Philosopher structure.
 * @return void
 */
void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0 && philo->meal_count == 0)
		usleep(philo->global->tt_eat * 1000 + 1000);
	while (1)
	{
		if (ft_is_dead(philo))
			break ;
		pthread_mutex_lock(&philo->global->forks_mutex[philo->left_fork]);
		pthread_mutex_lock(&philo->global->forks_mutex[philo->right_fork]);
		if (ft_is_dead(philo))
			break ;
		ft_action_eat(philo);
		pthread_mutex_unlock(&philo->global->forks_mutex[philo->left_fork]);
		pthread_mutex_unlock(&philo->global->forks_mutex[philo->right_fork]);
		if (ft_is_dead(philo))
			break ;
		ft_action_sleep(philo);
		ft_action_think(philo);
	}
	return (NULL);
}
