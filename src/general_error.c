/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:18:44 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:19:03 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	general_error(char **map)
{
	unsigned int	i;

	if (map)
	{
		i = 0;
		while (map[i])
			free(map[i++]);
		free(map);
	}
	putstr_fd("Error : Something went wrong\n", 1);
	exit (0);
}
