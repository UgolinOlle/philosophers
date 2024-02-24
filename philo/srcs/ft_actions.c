/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:06:54 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/25 00:24:10 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Action get forks.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
static void	ft_action_forks(t_philo *philo)
{
	if (philo->global->forks[philo->left_fork] == 1
		&& philo->global->forks[philo->right_fork] == 1)
	{
		philo->global->forks[philo->left_fork] = 0;
		ft_status(philo, "has taken left fork.");
		philo->global->forks[philo->right_fork] = 0;
		ft_status(philo, "as taken right fork.");
	}
}

/**
 * @brief Action drop forks.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
static void	ft_action_drop_forks(t_philo *philo)
{
	if (philo->global->forks[philo->left_fork] == 0)
		philo->global->forks[philo->left_fork] = 1;
	else if (philo->global->forks[philo->right_fork] == 0)
		philo->global->forks[philo->right_fork] = 1;
}

/**
 * @brief Philosopher sleep.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
void	ft_action_sleep(t_philo *philo)
{
	ft_status(philo, "is sleeping.");
	usleep(philo->global->tt_sleep * 1000);
}

/**
 * @brief Lock, unlock and eat action.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
void	ft_action_eat(t_philo *philo)
{
	ft_action_forks(philo);
	if (philo->global->forks[philo->left_fork] == 0
		&& philo->global->forks[philo->right_fork] == 0)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		philo->t_last_meal = ft_get_time();
		philo->meal = 1;
		philo->meal_count++;
		pthread_mutex_unlock(&philo->meal_mutex);
		ft_status(philo, "is eating.");
		usleep(philo->global->tt_eat * 1000);
		ft_action_drop_forks(philo);
	}
}

/**
 * @brief Action think.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
void	ft_action_think(t_philo *philo)
{
	ft_status(philo, "is thinking.");
}
