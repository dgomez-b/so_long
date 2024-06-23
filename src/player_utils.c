/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:30:10 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:35:45 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	get_player_position(t_program *program)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (program->map.vec[y])
	{
		x = 0;
		while (program->map.vec[y][x])
		{
			if (program->map.vec[y][x] == 'P')
			{
				program->player.x = x;
				program->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_program program)
{
	mlx_put_image_to_window(program.mlx, program.window, program.images[4].pnt,
		program.player.x * 32, program.player.y * 32);
}

static void	exit_door(t_program *program)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	c;

	c = 0;
	y = 0;
	while (program->map.vec[y])
	{
		x = 0;
		while (program->map.vec[y][x])
			if (program->map.vec[y][x++] == 'C')
				c++;
		y++;
	}
	if (c != 0)
		return ;
	close_program(program);
}

static void	move_player(t_program *program, t_direction direction)
{
	unsigned int	position[2];

	position[0] = program->player.x;
	position[1] = program->player.y;
	if (direction == RIGHT)
		position[0]++;
	else if (direction == LEFT)
		position[0]--;
	if (direction == UP)
		position[1]--;
	else if (direction == DOWN)
		position[1]++;
	if (program->map.vec[position[1]][position[0]] == 'C')
		program->map.vec[position[1]][position[0]] = '0';
	else if (program->map.vec[position[1]][position[0]] == '1')
		return ;
	else if (program->map.vec[position[1]][position[0]] == 'E')
		return (exit_door(program));
	mlx_put_image_to_window(program->mlx, program->window,
		program->images[2].pnt, program->player.x * 32,
		program->player.y * 32);
	program->player.x = position[0];
	program->player.y = position[1];
	draw_player(*program);
	program->player.moves++;
}

int	key_hook(int keycode, t_program	*program)
{
	if (keycode == 65307)
		close_program(program);
	else if (keycode == 'w')
		move_player(program, UP);
	else if (keycode == 'a')
		move_player(program, LEFT);
	else if (keycode == 'd')
		move_player(program, RIGHT);
	else if (keycode == 's')
		move_player(program, DOWN);
	else
		return (0);
	putstr_fd("Amount moves -> ", 1);
	putnbr_fd(program->player.moves, 1);
	putstr_fd("\n", 1);
	return (0);
}
