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

#include "so_long.h"
#include <fcntl.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./minilibx-linux/mlx.h"

#include <stdio.h>

unsigned int	string_length(char *s)
{
	if (!*s)
		return (0);
	return (string_length(s + 1) + 1);
}

void	putstr_fd(char *s, int fd)
{
	write(fd, s, string_length(s));
}

void	putnbr_fd(int n, int fd)
{
	char	c;

	c = '0';
	if (n < 0)
	{
		c = '0' + ((n % 10) * -1);
		n /= 10;
		if (write(fd, "-", 1) == -1)
			return ;
		if (n != 0)
			putnbr_fd(n * -1, fd);
	}
	else if (n > 0)
	{
		c = '0' + (n % 10);
		n /= 10;
		if (n != 0)
			putnbr_fd(n, fd);
	}
	if (write(fd, &c, 1) == -1)
		return ;
}

void	general_error(char **map)
{
	unsigned int	i;

	if (map)
	{
		i = 0;
		while (map[i])
			free(map[i++]);
		free(map);
	}
	putstr_fd("Error : Something went wrong\n", 1);
	exit (0);
}

void	file_path_error(void)
{
	putstr_fd("Error : The program requires a file to display a map\n", 1);
	exit (0);
}

void	file_extension_error(void)
{
	putstr_fd("Error : The map file should have '.ber' as its extension\n", 1);
	exit (0);
}

void	private_file_error(void)
{
	putstr_fd("Error : The file shouldn't be private\n", 1);
	exit (0);
}

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

void	path_error(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	putstr_fd("Error : The map has no valid path\n", 1);
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

	s = map_line(fd);
	if (!s)
	{
		if (i == 0)
			build_error();
		map = malloc(sizeof(char *) * (i + 1));
		if (!map)
			return (0x0);
		map[i] = 0x0;
		return (map);
	}
	i++;
	map = build_map(fd);
	if (!map)
	{
		if (--i == 0)
			build_error();
		return (0x0);
	}
	map[--i] = s;
	return (map);
}

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

char	*string_dup(char *s)
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

unsigned int	*find_end(char **map)
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

void	toggle_next(unsigned int x, unsigned int y, char **map)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	toggle_next(x, y + 1, map);
	toggle_next(x - 1, y, map);
	toggle_next(x + 1, y, map);
	toggle_next(x, y - 1, map);
}

t_bool	no_cep(char **map)
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

t_dimensions	get_dimensions(char **map)
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

void	exit_door(t_program *program)
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

void	move_player(t_program *program, t_direction direction)
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

void	load_images(t_program *program)
{
	program->images[0].pnt = mlx_xpm_file_to_image(program->mlx,
			"./textures/wall.xpm", &(program->images[0].width),
			&(program->images[0].height));
	program->images[1].pnt = mlx_xpm_file_to_image(program->mlx,
			"./textures/exit.xpm", &(program->images[1].width),
			&(program->images[1].height));
	program->images[2].pnt = mlx_xpm_file_to_image(program->mlx,
			"./textures/floor.xpm", &(program->images[2].width),
			&(program->images[2].height));
	program->images[3].pnt = mlx_xpm_file_to_image(program->mlx,
			"./textures/coin.xpm", &(program->images[3].width),
			&(program->images[3].height));
	program->images[4].pnt = mlx_xpm_file_to_image(program->mlx,
			"./textures/player.xpm", &(program->images[4].width),
			&(program->images[4].height));
}

void	draw_map(t_program program)
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

void	chk_file_path(char *file_path)
{
	unsigned int	i;

	i = string_length(file_path);
	if (i < 4)
		file_extension_error();
	if (file_path[i - 1] != 'r' || file_path[i - 2] != 'e' ||
		file_path[i - 3] != 'b' || file_path[i - 4] != '.')
		file_extension_error();
	i--;
	while (i > 0 && file_path[i] != '/')
		i--;
	if ((i == 0 && file_path[i] == '.') || (file_path[i + 1] == '.'))
		private_file_error();
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
