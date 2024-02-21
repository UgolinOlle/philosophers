/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:53:08 by uolle             #+#    #+#             */
/*   Updated: 2024/02/21 21:49:30 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Initialize forks
 *
 * @param t_global *global - Pointer to the global struct.
 * @return void
 */
static void	ft_init_forks(t_global *global)
{
	int	i;

	global->forks = malloc(sizeof(int) * global->nb_philo);
	if (!global->forks)
		ft_exit(global, PHILO_MALLOC_ERROR, EXIT_FAILURE);
	global->forks_mutex = malloc(sizeof(pthread_mutex_t) * global->nb_philo);
	if (!global->forks_mutex)
		ft_exit(global, PHILO_MUTEX_ERROR, EXIT_FAILURE);
	i = 0;
	while (i < global->nb_philo)
	{
		global->forks[i] = 1;
		if (pthread_mutex_init(&global->forks_mutex[i], NULL) != 0)
			ft_exit(global, PHILO_MUTEX_ERROR, EXIT_FAILURE);
		i++;
	}
}

/**
 * @brief Initialize mutex
 *
 * @param t_global *global - Pointer to the global struct.
 * @return void
 */
static void	ft_init_mutex(t_global *global)
{
	if (pthread_mutex_init(&global->dead_mutex, NULL))
		ft_exit(global, PHILO_MUTEX_ERROR, EXIT_FAILURE);
	if (pthread_mutex_init(&global->write_mutex, NULL))
		ft_exit(global, PHILO_MUTEX_ERROR, EXIT_FAILURE);
}

/**
 * @brief Initialize philos struct.
 *
 * @param t_global *global - Pointer to the global struct.
 * @return void
 */
static void	ft_init_philos(t_global *global)
{
	int	i;

	i = 0;
	global->philos = malloc(sizeof(t_philo *) * global->nb_philo);
	if (!global->philos)
		ft_exit(global, PHILO_MALLOC_ERROR, EXIT_FAILURE);
	while (i < global->nb_philo)
	{
		global->philos[i] = malloc(sizeof(t_philo));
		if (!global->philos[i])
			ft_exit(global, PHILO_MALLOC_ERROR, EXIT_FAILURE);
		global->philos[i]->id = i;
		global->philos[i]->meal = 0;
		global->philos[i]->meal_count = 0;
		global->philos[i]->t_last_meal = 0;
		global->philos[i]->left_fork = i;
		global->philos[i]->right_fork = (i + 1) % global->nb_philo;
		global->philos[i]->global = global;
		if (pthread_mutex_init(&global->philos[i]->meal_mutex, NULL))
			ft_exit(global, PHILO_MUTEX_ERROR, EXIT_FAILURE);
		i++;
	}
}

/**
 * @brief Initialize global.
 *
 * @param global t_global - Pointer to the global struct.
 * @param argc int - Number of arguments.
 * @param argv char ** - Arguments.
 * @return void
 */
t_global	*ft_init_global(int argc, char **argv)
{
	t_global	*global;
	int			i;

	global = malloc(sizeof(t_global));
	if (!global)
		ft_exit(NULL, PHILO_INPUT_ERROR, EXIT_FAILURE);
	i = 1;
	global->nb_philo = ft_atoi(argv[i++]);
	global->tt_die = ft_atoi(argv[i++]);
	global->tt_eat = ft_atoi(argv[i++]);
	global->tt_sleep = ft_atoi(argv[i++]);
	if (argc == 6)
		global->max_meal_count = ft_atoi(argv[i]);
	else
		global->max_meal_count = -1;
	global->philo_dead = 0;
	ft_init_forks(global);
	ft_init_mutex(global);
	ft_init_philos(global);
	if (!global->philos)
		return (NULL);
	return (global);
}
