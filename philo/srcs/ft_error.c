/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uolle <uolle@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:10 by uolle             #+#    #+#             */
/*   Updated: 2024/01/29 17:01:30 by uolle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Free all allocated memory.
 *
 * @param *philo t_philo - Pointer to the philo struct.
 * @return void
 */
void ft_free(t_philo *philo) {
  unsigned int i;

  if (!philo->data)
    return;
  if (philo->data->fork_locked)
    free(philo->data->fork_locked);
  if (philo) {
    free(philo);
  }
  return;
}

/**
 * @brief Destroy all mutexes.
 *
 * @param *philo t_philo - Pointer to the philo struct.
 * @return void
 */
void ft_destroy_mutex(t_philo *philo) {
  unsigned int i;

  i = 0;
  while (i < philo->data->n_philo) {
    pthread_mutex_destroy(&philo->data->fork_locked[i]);
    i++;
  }
  return;
}

/**
 * @brief Exit the program with a message.
 *
 * @param *philo t_philo - Pointer to the philo struct.
 * @param *msg char - Message to print.
 * @return void
 */
void ft_exit(t_philo *philo, char *msg) {
  ft_free(philo);
  printf("%s\n", msg);
  exit(1);
}
