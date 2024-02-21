/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:01:12 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/16 14:49:18 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Routine for the philosophers.
 *
 * @param philo t_philo * - Pointer to the philo struct.
 * @return void
 */
void	*ft_philo(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&ph->global->forks_locked[ph->fork[0]]);
		ft_print_status(ph, "has taken a fork");
		pthread_mutex_lock(&ph->global->forks_locked[ph->fork[1]]);
		ft_print_status(ph, "has taken a fork");
		ft_print_status(ph, "is eating");
		ph->last_meal = ft_get_time();
		ft_usleep(ph->global->t_eat);
		pthread_mutex_unlock(&ph->global->forks[ph->fork[0]]);
		pthread_mutex_unlock(&ph->global->forks[ph->fork[1]]);
		ft_print_status(ph, "is sleeping");
		ft_usleep(ph->global->t_sleep);
		ft_print_status(ph, "is thinking");
	}
	return (NULL);
}
