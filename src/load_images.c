/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:32:16 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:32:25 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_program *program)
{
	program->images[0].pnt = mlx_xpm_file_to_image(program->mlx,
			"./resources/textures/wall.xpm", &(program->images[0].width),
			&(program->images[0].height));
	program->images[1].pnt = mlx_xpm_file_to_image(program->mlx,
			"./resources/textures/exit.xpm", &(program->images[1].width),
			&(program->images[1].height));
	program->images[2].pnt = mlx_xpm_file_to_image(program->mlx,
			"./resources/textures/floor.xpm", &(program->images[2].width),
			&(program->images[2].height));
	program->images[3].pnt = mlx_xpm_file_to_image(program->mlx,
			"./resources/textures/coin.xpm", &(program->images[3].width),
			&(program->images[3].height));
	program->images[4].pnt = mlx_xpm_file_to_image(program->mlx,
			"./resources/textures/player.xpm", &(program->images[4].width),
			&(program->images[4].height));
}
