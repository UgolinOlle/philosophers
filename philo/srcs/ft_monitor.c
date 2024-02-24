/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:40:09 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/24 23:23:54 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Monitor the philosophers.
 *
 * @param void *arg - Global structure.
 * @return void
 */
void	*ft_monitor(void *arg)
{
	t_global	*global;
	int			i;

	global = (t_global *)arg;
	while (global->philo->dead != 1)
	{
		i = 0;
		while (i < global->nb_philo)
		{
			if (ft_is_dead(&global->philo[i]))
				return (NULL);
			pthread_mutex_unlock(&global->philo[i].meal_mutex);
			i++;
		}
	}
	return (NULL);
}
