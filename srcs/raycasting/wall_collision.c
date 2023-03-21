/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:50:22 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/19 00:54:06 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	forward_shift(t_leet *leet)
{
	double	pa;

	pa = leet->ray.player.angle;
	if ((pa > M_PI + M_PI_2 + M_PI_4 || pa < M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x + COLLISION,
			leet->ray.player.vector.y))
		leet->ray.player.vector.x += COLLISION;
	else if ((pa > M_PI_2 + M_PI_4 && pa < M_PI + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x \
			- COLLISION, leet->ray.player.vector.y))
		leet->ray.player.vector.x -= COLLISION;
	else if ((pa > M_PI_4 && pa < M_PI_2 + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x,
			leet->ray.player.vector.y + COLLISION))
		leet->ray.player.vector.y += COLLISION;
	else if ((pa > M_PI + M_PI_4 && pa < M_PI + M_PI_2 + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x,
			leet->ray.player.vector.y - COLLISION))
		leet->ray.player.vector.y -= COLLISION;
}

void	backward_shift(t_leet *leet)
{
	double	pa;

	pa = leet->ray.player.angle;
	if ((pa > M_PI + M_PI_2 + M_PI_4 || pa < M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x - COLLISION,
			leet->ray.player.vector.y))
		leet->ray.player.vector.x -= COLLISION;
	else if ((pa > M_PI_2 + M_PI_4 && pa < M_PI + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x \
			+ COLLISION, leet->ray.player.vector.y))
		leet->ray.player.vector.x += COLLISION;
	else if ((pa > M_PI_4 && pa < M_PI_2 + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x, \
			leet->ray.player.vector.y - COLLISION))
		leet->ray.player.vector.y -= COLLISION;
	else if ((pa > M_PI + M_PI_4 && pa < M_PI + M_PI_2 + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x,
			leet->ray.player.vector.y + COLLISION))
		leet->ray.player.vector.y += COLLISION;
}

void	right_shift(t_leet *leet)
{
	double	pa;

	pa = leet->ray.player.angle;
	if ((pa > M_PI + M_PI_2) && can_move(leet->ray.map.map,
			leet->ray.player.vector.x + COLLISION, leet->ray.player.vector.y))
			leet->ray.player.vector.x += COLLISION;
	else if ((pa > M_PI_2 && pa < M_PI) && can_move(leet->ray.map.map,
			leet->ray.player.vector.x - COLLISION,
			leet->ray.player.vector.y))
		leet->ray.player.vector.x -= COLLISION;
	else if ((pa < M_PI_2) && can_move(leet->ray.map.map,
			leet->ray.player.vector.x, leet->ray.player.vector.y
			+ COLLISION))
		leet->ray.player.vector.y += COLLISION;
	else if ((pa > M_PI && pa < M_PI + M_PI_2) && can_move(leet->ray.map.map,
			leet->ray.player.vector.x, leet->ray.player.vector.y
			- COLLISION))
		leet->ray.player.vector.y -= COLLISION;
}

void	left_shift(t_leet *leet)
{
	double	pa;

	pa = leet->ray.player.angle;
	if ((pa > M_PI + M_PI_2 + M_PI_4 || pa < M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x + COLLISION,
			leet->ray.player.vector.y))
				leet->ray.player.vector.x += COLLISION;
	else if ((pa > M_PI_2 + M_PI_4 && pa < M_PI + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x
			- COLLISION, leet->ray.player.vector.y))
		leet->ray.player.vector.x -= COLLISION;
	else if ((pa > M_PI_4 && pa < M_PI_2 + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x,
			leet->ray.player.vector.y + COLLISION))
				leet->ray.player.vector.y += COLLISION;
	else if ((pa > M_PI + M_PI_4 && pa < M_PI + M_PI_2 + M_PI_4)
		&& can_move(leet->ray.map.map, leet->ray.player.vector.x,
			leet->ray.player.vector.y - COLLISION))
		leet->ray.player.vector.y -= COLLISION;
}

void	wall_collisions(t_leet *leet, double angle, int sign)
{
	if (leet->ray.player.angle == angle && sign == 1)
		forward_shift(leet);
	else if (leet->ray.player.angle == angle && sign == -1)
		backward_shift(leet);
	else if (leet->ray.player.angle != angle && sign == 1)
		right_shift(leet);
	else if (leet->ray.player.angle != angle && sign == -1)
		left_shift(leet);
}
