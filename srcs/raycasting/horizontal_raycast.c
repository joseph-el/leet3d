/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_raycast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:22:54 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/10 16:03:31 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

t_vector	get_horizontal_intercept(t_leet *leet, double rayAngle)
{
	t_vector	intercept;

	intercept.y = floor(leet->ray.player.vector.y / TILE_SIZE) * TILE_SIZE;
	if (_direction(rayAngle, FACING_DOWN))
		intercept.y += TILE_SIZE;
	intercept.x = leet->ray.player.vector.x + (intercept.y
			- leet->ray.player.vector.y) / tan(rayAngle);
	return (intercept);
}

t_vector	get_horizontal_steps(double rayAngle)
{
	t_vector	step;

	step.y = TILE_SIZE;
	if (_direction(rayAngle, FACING_UP))
		step.y *= -1;
	step.x = TILE_SIZE / tan(rayAngle);
	if (_direction(rayAngle, FACING_LEFT) && step.x > 0)
		step.x *= -1;
	if (_direction(rayAngle, FACING_RIGHT) && step.x < 0)
		step.x *= -1;
	return (step);
}

void	set_horz_check(t_vector *to_check, t_vector next_touch, double rayAngle)
{
	to_check->x = next_touch.x;
	to_check->y = next_touch.y;
	if (_direction(rayAngle, FACING_UP))
		to_check->y--;
}

t_vector	horizontal_raycast(t_leet *leet, double rayAngle)
{
	t_vector	step;
	t_vector	intercept;
	t_vector	next_touch;
	t_vector	to_check;

	next_touch.x = -1;
	next_touch.y = -1;
	intercept = get_horizontal_intercept(leet, rayAngle);
	step = get_horizontal_steps(rayAngle);
	next_touch.x = intercept.x;
	next_touch.y = intercept.y;
	while (next_touch.x >= 0 && next_touch.x <= WINDOW_WIDTH
		&& next_touch.y >= 0 && next_touch.y <= WINDOW_HEIGHT)
	{
		set_horz_check(&to_check, next_touch, rayAngle);
		if (map_has_wall_at(leet->ray.map.map, to_check.x, to_check.y))
			return (next_touch);
		else
		{
			next_touch.x += step.x;
			next_touch.y += step.y;
		}
	}
	return (next_touch);
}
