/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:53:08 by uolle             #+#    #+#             */
/*   Updated: 2024/02/16 13:54:39 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Initialize forks
 *
 * @param t_global *global - Pointer to the global struct.
 * @return void
 */
static pthread_mutex_t	*ft_init_forks(t_global *global)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * global->n_philo);
	if (!forks)
		ft_exit(PHILO_MALLOC_ERROR, EXIT_FAILURE);
	i = 0;
	while (i < global->n_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			ft_exit(PHILO_MUTEX_ERROR, EXIT_FAILURE);
		i++;
	}
	return (forks);
}

/**
 * @brief Initialize forks to philosophers
 *
 * @param t_philo *philos - Pointer to the philos struct.
 * @return void
 */
static void	ft_give_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->global->n_philo;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->global->n_philo;
		philo->fork[1] = philo->id;
	}
}

/**
 * @brief Initialize philos struct.
 *
 * @param global t_global - Pointer to the global struct.
 * @return t_philo **
 */
static t_philo	**ft_init_philos(t_global *global)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * global->n_philo);
	if (!philos)
		ft_exit("An error occured, philos malloc failed.", EXIT_FAILURE);
	i = 0;
	while (i < global->n_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			ft_exit("An error occured, philo malloc failed.", EXIT_FAILURE);
		philos[i]->id = i;
		philos[i]->t_ate = 0;
		philos[i]->global = global;
		ft_give_forks(philos[i]);
		i++;
	}
	return (philos);
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
		ft_exit("An error occured, global malloc failed.", EXIT_FAILURE);
	i = 1;
	global->n_philo = ft_atoi(argv[i++]);
	global->tt_die = ft_atoi(argv[i++]);
	global->tt_eat = ft_atoi(argv[i++]);
	global->tt_sleep = ft_atoi(argv[i++]);
	if (argc == 6)
		global->n_must_eat = ft_atoi(argv[i]);
	else
		global->n_must_eat = -1;
	global->philos = ft_init_philos(global);
	if (!global->philos)
		return (NULL);
	global->forks_locked = ft_init_forks(global);
	if (!global->forks_locked)
		return (NULL);
	return (global);
}
