/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:25:36 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:26:03 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static char	*string_dup(char *s)
{
	unsigned int	l;
	char			*ns;

	if (!s)
		return (0x0);
	l = string_length(s);
	ns = malloc(sizeof(char) * (l + 1));
	if (!ns)
		return (0x0);
	ns[l] = 0;
	while (l-- >= 1)
		ns[l] = s[l];
	return (ns);
}

char	**map_dup(char **map)
{
	static unsigned int	i = 0;
	char				*line;
	char				**new_map;

	line = string_dup(map[i]);
	if (!line)
	{
		if (i == 0)
			return (0x0);
		new_map = malloc(sizeof(char *) * (i + 1));
		if (!new_map)
			return (0x0);
		new_map[i] = 0x0;
		return (new_map);
	}
	i++;
	new_map = map_dup(map);
	i--;
	if (!new_map)
		return (0x0);
	new_map[i] = line;
	return (new_map);
}
