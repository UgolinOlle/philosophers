/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:06:54 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/25 12:58:08 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
 * @brief Action think.
 *
 * @param t_philo *philo - Philosopher structure.
 * @return void
 */
void	ft_action_think(t_philo *philo)
{
	ft_status(philo, "is thinking.");
}
