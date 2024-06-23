/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:20:32 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:23:30 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	build_error(void)
{
	putstr_fd("Error : Map couldn't be builded\n", 1);
	exit (0);
}

void	rectangle_error(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	putstr_fd("Error : The map should be a rectangle\n", 1);
	exit (0);
}

void	char_error(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	putstr_fd("Error : The map has non valid characters\n", 1);
	exit (0);
}

void	min_max_error(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	putstr_fd("Error : Invalid amount of collectionables, players and/or ", 1);
	putstr_fd("exits\n", 1);
	exit (0);
}

void	closed_map_error(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	putstr_fd("Error : The map should be closed\n", 1);
	exit (0);
}
