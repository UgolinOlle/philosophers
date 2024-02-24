/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:38 by uolle             #+#    #+#             */
/*   Updated: 2024/02/24 22:25:32 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_checker(int argc, char **argv)
{
	int	i;
	int	tmp;

	if (argc - 1 < 4 || argc - 1 > 5)
		ft_exit(NULL, PHILO_USAGE, EXIT_FAILURE);
	i = 1;
	while (i <= argc - 1)
	{
		if (!ft_is_digit(argv[i]))
			ft_exit(NULL, PHILO_INPUT_ERROR, EXIT_FAILURE);
		tmp = ft_atoi(argv[i]);
		if (i == 1 && (tmp <= 0 || tmp > 250))
			ft_exit(NULL, PHILO_INPUT_ERROR, EXIT_FAILURE);
		if (i != 1 && tmp == -1)
			ft_exit(NULL, PHILO_INPUT_ERROR, EXIT_FAILURE);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_global	*global;

	global = NULL;
	ft_checker(argc, argv);
	global = ft_init_global(argc, argv);
	if (global->nb_philo == 1)
	{
		ft_alone(global);
		ft_alone_stop(global);
	}
	else
		ft_launch_routine(global);
	return (EXIT_SUCCESS);
}
