/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:19:17 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/14 18:01:29 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "leet3d.h"

typedef enum e_hit
{
	_SPACE,
	WALL,
	DOOR,
	ENEMY,
	OUT_RANGE,
	HORIZONTAL_HIT,
	VERTICAL_HIT,
}	t_hit;

enum e_direction
{
	FACING_UP,
	FACING_DOWN,
	FACING_RIGHT,
	FACING_LEFT,
};

enum e_key
{
	ESC_KEY = 53,
	W_KEY = 13,
	S_KEY = 1,
	A_KEY = 0,
	D_KEY = 2,
	RIGHT_KEY = 124,
	LEFT_KEY = 123,
	UP_KEY = 126,
	DOWN_KEY = 125
};

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	double		angle;
	t_vector	wall_hit;
	double		distance;
	int			wall_height;
	t_hit		hit_side;
	t_hit		hit_content;
}	t_ray;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_player
{
	double		angle;
	double		fov;
	t_ray		*rays;
	t_vector	vector;
	int			frame;
}	t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_map
{
	t_img	_north;
	t_img	_south;
	t_img	_west;
	t_img	_east;
	t_img	_enemy;
	t_img	_door;
	t_img	*fire;
	t_rgb	_floor;
	t_rgb	_ceil;
	char	**map;
}	t_map;

typedef struct s_raycasting
{
	t_map		map;
	t_img		img;
	t_player	player;
}	t_raycasting;

#endif