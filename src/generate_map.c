/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:34:40 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:34:51 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_dimensions	get_dimensions(char **map)
{
	static t_dimensions	dimensions;

	dimensions.width = string_length(map[0]);
	dimensions.height = 0;
	while (map[dimensions.height])
		dimensions.height++;
	return (dimensions);
}

t_map	generate_map(char *file_path)
{
	static t_map	map;
	int				fd;

	fd = open(file_path, O_RDONLY);
	map.vec = build_map(fd);
	if (!map.vec)
		build_error(fd);
	close(fd);
	if (!is_rectangle(map.vec))
		rectangle_error(map.vec);
	if (!has_valid_chars(map.vec))
		char_error(map.vec);
	if (!min_max_chars(map.vec))
		min_max_error(map.vec);
	if (!is_closed(map.vec))
		closed_map_error(map.vec);
	if (!has_valid_path(map.vec))
		path_error(map.vec);
	map.dimensions = get_dimensions(map.vec);
	return (map);
}
