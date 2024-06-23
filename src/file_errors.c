/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:19:30 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:21:54 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	file_path_error(void)
{
	putstr_fd("Error : The program requires a file to display a map\n", 1);
	exit (0);
}

void	file_extension_error(void)
{
	putstr_fd("Error : The map file should have '.ber' as its extension\n", 1);
	exit (0);
}

void	private_file_error(void)
{
	putstr_fd("Error : The file shouldn't be private\n", 1);
	exit (0);
}

void	path_error(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	putstr_fd("Error : The map has no valid path\n", 1);
	exit (0);
}
