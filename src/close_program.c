/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:48:11 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:48:25 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	close_program(t_program	*program)
{
	unsigned int	i;

	i = 0;
	while (program->map.vec[i])
		free(program->map.vec[i++]);
	free(program->map.vec);
	i = 0;
	while (i < 5)
		mlx_destroy_image(program->mlx, program->images[i++].pnt);
	mlx_destroy_window(program->mlx, program->window);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit (0);
}
