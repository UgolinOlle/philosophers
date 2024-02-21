/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:24:18 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/21 21:26:51 by ugolin-olle      ###   ########.fr       */
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
	if (global)
		ft_clean_global(global);
	printf("Error: %s\n", msg);
	exit(status);
}

/**
 * @brief Free the global structure.
 *
 * @param global t_global * - Global structure.
 * @return void
 */
void	*ft_clean_global(t_global *global)
{
	int	i;

	if (!global)
		return (NULL);
	if (global->forks_mutex != NULL)
		free(global->forks_mutex);
	if (global->philos != NULL)
	{
		i = 0;
		while (i < global->nb_philo)
		{
			if (global->philos[i] != NULL)
				free(global->philos[i]);
			i++;
		}
		free(global->philos);
	}
	free(global);
	return (NULL);
}

/**
 * @brief Clean mutex.
 *
 * @param t_global *global - Global structure.
 * @return void
 */
void	ft_clean_mutex(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		pthread_mutex_destroy(&global->forks_mutex[i]);
		pthread_mutex_destroy(&global->philos[i]->meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&global->dead_mutex);
	pthread_mutex_destroy(&global->write_mutex);
}
