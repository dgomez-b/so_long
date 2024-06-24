/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:23:55 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:43:29 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*map_line(int fd)
{
	static unsigned int	i = 0;
	char				c;
	char				*s;

	if (read(fd, &c, 1) <= 0)
		return (0x0);
	if (!c || c == '\n')
	{
		if (i == 0)
			return (0x0);
		s = 0x0;
		if (i <= 100)
			s = malloc(sizeof(char) * (i + 1));
		if (!s)
			return (0x0);
		s[i] = 0;
		return (s);
	}
	i++;
	s = map_line(fd);
	i--;
	if (!s)
		return (0x0);
	s[i] = c;
	return (s);
}

char	**build_map(int fd)
{
	static unsigned int	i = 0;
	char				**map;
	char				*s;

	if (i > 50)
		return (0x0);
	s = map_line(fd);
	if (!s)
	{
		if (i == 0)
			build_error(fd);
		map = malloc(sizeof(char *) * (i + 1));
		if (map != 0x0)
			map[i] = 0x0;
		return (map);
	}
	i++;
	map = build_map(fd);
	if (map != 0x0)
		map[--i] = s;
	else
		free(s);
	if (map == 0x0 && --i == 0)
		build_error(fd);
	return (map);
}
