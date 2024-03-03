/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:24:18 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/28 16:37:39 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Print error message and exit the program.
 *
 * @param t_global *global - Global structure.
 * @param msg char * - Error message.
 * @param status int - Exit status.
 * @return void
 */
void	ft_exit(t_global *global, char *msg, int status)
{
	if (global != NULL)
		ft_clean_global(global);
	printf("Error: %s\n", msg);
	exit(status);
}

/**
 * @brief Free global structure.
 *
 * @param t_global *global - Global structure.
 * @return void
 */
void	ft_clean_global(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		pthread_mutex_destroy(&global->forks_mutex[i]);
		pthread_mutex_destroy(&global->philo[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&global->write_mutex);
	pthread_mutex_destroy(&global->dead_mutex);
	free(global->forks);
	free(global->forks_mutex);
	free(global->philo);
	free(global);
}
