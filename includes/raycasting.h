/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:59:38 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/10 16:15:58 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RAYCASTING_H
# define RAYCASTING_H

# include "leet3d.h"

# define TILE_SIZE 32
# define NUM_RAYS 1280
# define MOVE_SPEED 5.0
# define ROTATE_SPEED 5.0
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TEXTURE_DIMENTION 32
# define _MOVE_UP 4
# define _MOVE_DOWN 16
# define _MOVE_LEFT 64
# define _MOVE_RIGHT 32
# define ROTATE_LEFT 2
# define ROTATE_RIGHT 1

enum e_hit
{
	HORIZONTAL_HIT,
	VERTICAL_HIT,
};

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
}	            t_vector;

typedef struct s_ray
{
	double	angle;
	double	x_wall_hit;
	double	y_wall_hit;
	double	distance;
	int		hit_side;
	int		wall_height;
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
	t_rgb	_floor;
	t_rgb	_ceil;
	char	**map;
}	t_map;

typedef struct s_raycasting
{
    t_map       map;
    t_img       img;
    t_player    player;
}               t_raycasting;

# endif