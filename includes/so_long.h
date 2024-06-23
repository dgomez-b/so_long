/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 04:22:37 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/23 04:22:37 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <minilibx-linux/mlx.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef enum e_direction
{
	UP = 0,
	LEFT = 1,
	RIGHT = 2,
	DOWN = 3
}	t_direction;

typedef struct s_dimensions
{
	unsigned int	width;
	unsigned int	height;
}	t_dimensions;

typedef struct s_map
{
	char			**vec;
	unsigned int	**chars;
	t_dimensions	dimensions;
}	t_map;

typedef struct s_image
{
	void	*pnt;
	int		width;
	int		height;
}	t_image;

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
	int				moves;
}	t_player;

typedef struct s_program
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_image		images[5];
	t_player	player;
}	t_program;

char			**build_map(int fd);
void			chk_file_path(char *file_path);
void			file_path_error(void);
void			file_extension_error(void);
void			private_file_error(void);
void			path_error(char **map);
void			general_error(char **map);
t_map			generate_map(char *file_path);
void			load_images(t_program *program);
t_bool			is_rectangle(char **map);
t_bool			has_valid_chars(char **map);
t_bool			is_closed(char **map);
t_bool			min_max_chars(char **map);
t_bool			has_valid_path(char **map);
void			build_error(void);
void			rectangle_error(char **map);
void			char_error(char **map);
void			min_max_error(char **map);
void			closed_map_error(char **map);
char			**map_dup(char **map);
void			get_player_position(t_program *program);
void			draw_player(t_program program);
int				key_hook(int keycode, t_program	*program);
void			putstr_fd(char *s, int fd);
void			putnbr_fd(int n, int fd);
unsigned int	string_length(char *s);
int				close_program(t_program	*program);

#endif
