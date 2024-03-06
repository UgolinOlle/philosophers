/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:58:58 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/03/04 14:58:00 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Lock forks.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
void	ft_lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->forks_mutex[philo->right_fork]);
	pthread_mutex_lock(&philo->global->forks_mutex[philo->left_fork]);
}

/**
 * @brief Unlock forks.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->global->forks_mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->global->forks_mutex[philo->right_fork]);
}
