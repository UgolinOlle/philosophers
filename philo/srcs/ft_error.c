/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:10 by uolle             #+#    #+#             */
/*   Updated: 2024/02/12 15:20:18 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Free all allocated memory.
 *
 * @param *philo t_philo - Pointer to the philo struct.
 * @return void
 */
void	*ft_free(t_global *global)
{
	unsigned int	i;

	if (!global)
		return ;
	if (global->fork_locked != NULL)
		free(global->fork_locked);
	if (global->philos != NULL)
	{
		i = 0;
		while (i < global->n_philo)
		{
			if (global->philos[i] != NULL)
				free(global->philos[i]);
			i++;
		}
		free(global->philos);
	}
	return ;
}

/**
 * @brief Destroy all mutexes.
 *
 * @param *philo t_philo - Pointer to the philo struct.
 * @return void
 */
void	ft_destroy_mutex(t_global *global)
{
	unsigned int	i;

	i = 0;
	while (i < global->n_philo)
	{
		pthread_mutex_destroy(&global->fork_locked[i]);
		i++;
	}
	return ;
}

/**
 * @brief Exit the program with a message.
 *
 * @param *philo t_philo - Pointer to the philo struct.
 * @param *content char - Message to print.
 * @return void
 */
void	ft_exit(t_global *global, char *content)
{
	ft_free(global);
	printf("%s\n", content);
	exit(1);
}
