/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:53:08 by uolle             #+#    #+#             */
/*   Updated: 2024/01/29 22:00:43 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Indexing the forks.
 *
 * @param *philo t_philo - Struct of the philosopher.
 * @return void
 */
static void ft_index_forks(t_philo *philo) {
  philo->data->fork[0] = philo->id;
  philo->data->fork[1] = philo->id + 1 % philo->data->n_philo;
  if (philo->id % 2) {
    philo->data->fork[0] = philo->id + 1 % philo->data->n_philo;
    philo->data->fork[1] = philo->id;
  }
}
