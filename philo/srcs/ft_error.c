/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:24:18 by ugolin-olle       #+#    #+#             */
/*   Updated: 2024/02/16 10:24:48 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief Print error message and exit the program.
 *
 * @param msg char * - Error message.
 * @param status int - Exit status.
 * @return void
*/
void    ft_error(char *msg, int status)
{
    printf("Error: %s\n", msg);
    exit(status);
}
