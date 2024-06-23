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

#endif
