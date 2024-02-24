/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:54:54 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/24 23:59:24 by ugolin-olle      ###   ########.fr       */
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
 * @brief Routine for philosophers.
 *
 * @param void *arg - Philosopher structure.
 * @return void
 */
void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
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
		ft_action_sleep(philo->global->tt_sleep);
		ft_action_think(philo);
	}
	return (NULL);
}
