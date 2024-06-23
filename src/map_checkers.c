/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:24:36 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:26:25 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_bool	is_rectangle(char **map)
{
	unsigned int	i;
	unsigned int	l;

	i = 1;
	l = string_length(map[0]);
	while (map[i])
		if (string_length(map[i++]) != l)
			return (FALSE);
	return (TRUE);
}

t_bool	has_valid_chars(char **map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' &&
				map[y][x] != 'E' && map[y][x] != 'P')
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

t_bool	is_closed(char **map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (map[0][x])
		if (map[0][x++] != '1')
			return (FALSE);
	x--;
	y = 1;
	while (map[y + 1])
	{
		if (map[y][0] != '1' || map[y][x] != '1')
			return (FALSE);
		y++;
	}
	x = 0;
	while (map[y][x])
		if (map[y][x++] != '1')
			return (FALSE);
	return (TRUE);
}

t_bool	min_max_chars(char **map)
{
	unsigned int	cep[3];
	unsigned int	position[2];

	cep[0] = 0;
	cep[1] = 0;
	cep[2] = 0;
	position[1] = 0;
	while (map[position[1]])
	{
		position[0] = 0;
		while (map[position[1]][position[0]])
		{
			if (map[position[1]][position[0]] == 'C')
				cep[0]++;
			else if (map[position[1]][position[0]] == 'E')
				cep[1]++;
			else if (map[position[1]][position[0]] == 'P')
				cep[2]++;
			position[0]++;
		}
		position[1]++;
	}
	if (cep[0] == 0 || cep[1] != 1 || cep[2] != 1)
		return (FALSE);
	return (TRUE);
}
