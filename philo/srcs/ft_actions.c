/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:06:54 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/21 19:07:37 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Philosopher sleep.
 *
 * @param time_t time - Time to sleep.
 * @return void
 */
void	ft_action_sleep(time_t time)
{
	time_t	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(100);
}
