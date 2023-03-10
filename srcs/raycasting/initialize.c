/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 01:37:10 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/10 16:03:35 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void	textures_initialize(t_leet *leet, t_parser *parser)
{
	int		size;

	size = TEXTURE_DIMENTION;
	leet->ray.map._north.img = mlx_xpm_file_to_image
		(leet->mlx, parser->texture[0], &size, &size);
	leet->ray.map._north.addr = mlx_get_data_addr(leet->ray.map._north.img,
			&leet->ray.map._north.bits_per_pixel, &leet->ray.map._north.line_length,
			&leet->ray.map._north.endian);
	leet->ray.map._south.img = mlx_xpm_file_to_image
		(leet->mlx, parser->texture[1], &size, &size);
	leet->ray.map._south.addr = mlx_get_data_addr(leet->ray.map._south.img,
			&leet->ray.map._south.bits_per_pixel, &leet->ray.map._south.line_length,
			&leet->ray.map._south.endian);
	leet->ray.map._west.img = mlx_xpm_file_to_image
		(leet->mlx, parser->texture[2], &size, &size);
	leet->ray.map._west.addr = mlx_get_data_addr(leet->ray.map._west.img,
			&leet->ray.map._west.bits_per_pixel, &leet->ray.map._west.line_length,
			&leet->ray.map._west.endian);
	leet->ray.map._east.img = mlx_xpm_file_to_image
		(leet->mlx, parser->texture[3], &size, &size);
	leet->ray.map._east.addr = mlx_get_data_addr(leet->ray.map._east.img,
			&leet->ray.map._east.bits_per_pixel, &leet->ray.map._east.line_length,
			&leet->ray.map._east.endian);
}

void	map_initialize(t_leet *leet, t_parser *parser)
{
	textures_initialize(leet, parser);
	leet->ray.map._floor.r = parser->c_floor[0];
	leet->ray.map._floor.g = parser->c_floor[1];
	leet->ray.map._floor.b = parser->c_floor[2];
	leet->ray.map._ceil.r = parser->c_ceiling[0];
	leet->ray.map._ceil.g = parser->c_ceiling[1];
	leet->ray.map._ceil.b = parser->c_ceiling[2];
	leet->ray.map.map = parser->map;
}

void	initialize(t_leet *leet, t_parser *parser)
{
	map_initialize(leet, parser);
	leet->ray.player.vector.x = parser->p_indices[0] * TILE_SIZE;
	leet->ray.player.vector.y = parser->p_indices[1] * TILE_SIZE;
	leet->ray.player.fov = 60 * (M_PI / 180);
	leet->ray.player.rays = 0x0;
	if (parser->position == NORTH)
		leet->ray.player.angle = 1.5 * M_PI;
	else if (parser->position == SOUTH)
		leet->ray.player.angle = 0.5 * M_PI;
	else if (parser->position == WEST)
		leet->ray.player.angle = M_PI;
	else if (parser->position == EAST)
		leet->ray.player.angle = 0;
}
