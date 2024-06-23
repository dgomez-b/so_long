/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:27:44 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:29:00 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static unsigned int	*find_end(char **map)
{
	static unsigned int	position[2];

	position[1] = 0;
	while (map[position[1]])
	{
		position[0] = 0;
		while (map[position[1]][position[0]])
		{
			if (map[position[1]][position[0]] == 'E')
				return (position);
			position[0]++;
		}
		position[1]++;
	}
	return (0x0);
}

static t_bool	no_cep(char **map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P')
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

static void	toggle_next(unsigned int x, unsigned int y, char **map)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	toggle_next(x, y + 1, map);
	toggle_next(x - 1, y, map);
	toggle_next(x + 1, y, map);
	toggle_next(x, y - 1, map);
}

t_bool	has_valid_path(char **map)
{
	unsigned int	*end;
	char			**nm;
	unsigned int	i;
	t_bool			chk;

	nm = map_dup(map);
	if (!nm)
		general_error(map);
	end = find_end(map);
	toggle_next(end[0], end[1], nm);
	chk = no_cep(nm);
	i = 0;
	while (nm[i])
		free(nm[i++]);
	free(nm);
	return (chk);
}
