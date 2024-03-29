/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:20:47 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/25 11:27:46 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Check if the parameters is a digit.
 *
 * @param c char * - Character
 * @return int
 */
int	ft_is_digit(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Atoi function.
 *
 * @param str char * - String to convert.
 * @return int
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * neg);
}

/**
 * @brief Get time in milliseconds.
 *
 * @return time_t
 */
time_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * @brief Print philisophers status
 *
 * @param philo t_philo * - Philosopher structure.
 * @param status char * - Status.
 * @return void
 */
void	ft_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->global->write_mutex);
	printf("%ldms %d %s\n", ft_get_time() - philo->global->t_start, philo->id
		+ 1, status);
	pthread_mutex_unlock(&philo->global->write_mutex);
}

/**
 * @brief Check if the philosopher is dead.
 *
 * @param philo t_philo * - Philosopher structure.
 * @return int
 */
int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->dead_mutex);
	if (philo->global->philo_dead == 1)
	{
		pthread_mutex_unlock(&philo->global->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->dead_mutex);
	return (0);
}
