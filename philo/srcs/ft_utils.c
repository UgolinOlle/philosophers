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
 * @brief Exit program with error message and free all allocated memory.
 *
 * @param content str - Error message.
 * @param philo t_philo - Struct with all data.
 */
void ft_error(char *content, t_philo *philo) {
  int i;

  if (!philo->data)
    return (NULL);
  if (philo->data->fork_locked)
    free(philo->data->fork_locked);
  if (philo != NULL) {
    i = 0;
    while (i < philo->data->n_philo) {
      free(philo);
      i++;
    }
  }
}
