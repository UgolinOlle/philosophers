/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:37:38 by uolle             #+#    #+#             */
/*   Updated: 2024/02/16 10:23:59 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_checker(int argc, char **argv)
{
	int	i;
	int	tmp;

	if (argc - 1 < 4 || argc - 1 > 5)
		ft_error(PHILO_USAGE, EXIT_FAILURE);
	i = 0;
	while (++i < argc)
	{
		if (!ft_is_digit(argv[i]))
			ft_error(PHILO_INPUT_ERROR, EXIT_FAILURE);
		tmp = ft_atoi(argv[i]);
		if (i == 1 && (tmp <= 0 || tmp > 250))
			ft_error(PHILO_INPUT_ERROR, EXIT_FAILURE);
		if (i != 1 && tmp == -1)
			ft_error(PHILO_INPUT_ERROR, EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_global	*global;

	global = NULL;
	ft_checker(argc, argv);
	global = ft_init_global(argc, argv);
	ft_print_global(global);
}
