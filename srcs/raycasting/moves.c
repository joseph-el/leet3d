/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:49:07 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/19 00:47:00 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	g_moving(t_leet *leet, int flag)
{
	if (flag & _MOVE_UP)
		_move(leet, leet->ray.player.angle, 1);
	else if (flag & _MOVE_DOWN)
		_move(leet, leet->ray.player.angle, -1);
	else if (flag & _MOVE_RIGHT)
		_move(leet, leet->ray.player.angle + 0.5 * M_PI, 1);
	else if (flag & _MOVE_LEFT)
		_move(leet, leet->ray.player.angle + 0.5 * M_PI, -1);
	else if (flag & ROTATE_LEFT)
		_rotate(leet, -1);
	else if (flag & ROTATE_RIGHT)
		_rotate(leet, 1);
	else
		return ;
	leet->sound.run = 1;
}

void	_rotate(t_leet *leet, int sign)
{
	leet->ray.player.angle = _angle(leet->ray.player.angle + (ROTATE_SPEED / 360
				* M_PI * 2 * sign));
}

void	_move(t_leet *leet, double angle, int sign)
{
	double	new_x;
	double	new_y;

	new_x = leet->ray.player.vector.x + (cos(angle) * MOVE_SPEED * sign);
	new_y = leet->ray.player.vector.y + (sin(angle) * MOVE_SPEED * sign);
	if ((map_has_wall_at(leet->ray.map.map, new_x, new_y) == _SPACE
			|| map_has_wall_at(leet->ray.map.map, new_x, new_y) == _EXIT))
	{
		leet->ray.player.vector.x = new_x;
		leet->ray.player.vector.y = new_y;
	}
	else
		wall_collisions(leet, angle, sign);
}
