/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:21:33 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/23 04:21:33 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	draw_map(t_program program)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (program.map.vec[y])
	{
		x = 0;
		while (program.map.vec[y][x])
		{
			if (program.map.vec[y][x] == '1')
				mlx_put_image_to_window(program.mlx, program.window,
					program.images[0].pnt, x * 32, y * 32);
			else if (program.map.vec[y][x] == 'E')
				mlx_put_image_to_window(program.mlx, program.window,
					program.images[1].pnt, x * 32, y * 32);
			else if (program.map.vec[y][x] == 'C')
				mlx_put_image_to_window(program.mlx, program.window,
					program.images[3].pnt, x * 32, y * 32);
			else
				mlx_put_image_to_window(program.mlx, program.window,
					program.images[2].pnt, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 2 || *(argv[1]) == '\0')
		file_path_error();
	chk_file_path(argv[1]);
	program.map = generate_map(argv[1]);
	program.mlx = mlx_init();
	program.window = mlx_new_window(program.mlx,
			32 * program.map.dimensions.width,
			32 * program.map.dimensions.height, "Game");
	get_player_position(&program);
	program.player.moves = 0;
	load_images(&program);
	draw_map(program);
	draw_player(program);
	mlx_hook(program.window, 17, 1L << 0, close_program, &program);
	mlx_hook(program.window, 2, 1L << 0, key_hook, &program);
	mlx_loop(program.mlx);
	return (0);
}
