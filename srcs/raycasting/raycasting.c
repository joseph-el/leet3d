/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:37:34 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/10 16:25:11 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

double	horizontal_distance(t_leet *leet, t_vector horizontal_hit)
{
	double	horz_hit_distance;

	if (horizontal_hit.x != -1 && horizontal_hit.y != -1)
		horz_hit_distance = _distance(leet->ray.player.vector, horizontal_hit);
	else
		horz_hit_distance = INT_MAX;
	return (horz_hit_distance);
}

double	vertical_distance(t_leet *leet, t_vector vertical_hit)
{
	double	vert_hit_distance;

	if (vertical_hit.x != -1 && vertical_hit.y != -1)
		vert_hit_distance = _distance(leet->ray.player.vector, vertical_hit);
	else
		vert_hit_distance = INT_MAX;
	return (vert_hit_distance);
}

void	setup_ray(t_leet *leet, t_ray *ray, t_vector horizontal_hit, t_vector vertical_hit)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	horz_hit_distance = horizontal_distance(leet, horizontal_hit);
	vert_hit_distance = vertical_distance(leet, vertical_hit);
	if (vert_hit_distance < horz_hit_distance)
	{
		ray->x_wall_hit = vertical_hit.x;
		ray->y_wall_hit = vertical_hit.y;
		ray->distance = vert_hit_distance;
		ray->hit_side = VERTICAL_HIT;
	}
	else
	{
		ray->x_wall_hit = horizontal_hit.x;
		ray->y_wall_hit = horizontal_hit.y;
		ray->distance = horz_hit_distance;
		ray->hit_side = HORIZONTAL_HIT;
	}
}

t_ray	cast_ray(t_leet *leet, double ray_angle)
{
	t_ray		ray;
	t_vector	horizontal_hit;
	t_vector	vertical_hit;

	ray.angle = _angle(ray_angle);
	horizontal_hit = horizontal_raycast(leet, ray_angle);
	vertical_hit = vertical_raycast(leet, ray_angle);
	setup_ray(leet, &ray, horizontal_hit, vertical_hit);
	return (ray);
}

void	raycasting(t_leet *leet)
{
	double	ray_angle;
	int		i;

	ray_angle = leet->ray.player.angle - (leet->ray.player.fov / 2);
	leet->ray.player.rays = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!leet->ray.player.rays)
		exit(1);
	i = 0;
	while (i < NUM_RAYS)
	{
		ray_angle = _angle(ray_angle);
		leet->ray.player.rays[i] = cast_ray(leet, ray_angle);
		ray_angle += leet->ray.player.fov / NUM_RAYS;
		i++;
	}
}
