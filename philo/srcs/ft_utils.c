/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:20:47 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/16 13:59:56 by ugolin-olle      ###   ########.fr       */
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
 * @brief Print all data from the global struct.
 *
 * @param global t_global - Pointer to the global struct.
 * @return void
 */
void	ft_print_global(t_global *global)
{
	int	i;

	i = 0;
	printf("t_start: %ld\n", global->t_start);
	printf("tt_die: %ld\n", global->tt_die);
	printf("tt_eat: %ld\n", global->tt_eat);
	printf("tt_sleep: %ld\n", global->tt_sleep);
	printf("n_philo: %d\n", global->n_philo);
	while (i < global->n_philo)
	{
		printf("philo[%d]: %d\n", i, global->philos[i]->id);
		printf("philo[%d]->fork[0]: %d\n", i, global->philos[i]->fork[0]);
		printf("philo[%d]->fork[1]: %d\n", i, global->philos[i]->fork[1]);
		printf("philo[%d]->ate_count: %d\n", i, global->philos[i]->ate_count);
		printf("philo[%d]->t_ate: %d\n", i, global->philos[i]->t_ate);
		i++;
	}
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
