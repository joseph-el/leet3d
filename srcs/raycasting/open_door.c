/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:19:59 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/19 22:09:59 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

static void	door_sound(t_leet *leet, int i, int j)
{
	leet->ray.map.map[i][j] = 'O';
	leet->sound.odoor = 1;
}

void	open_door(t_leet *leet)
{
	int	i;
	int	j;

	i = -1;
	while (leet->ray.map.map[++i])
	{
		j = -1;
		while (leet->ray.map.map[i][++j])
		{
			if (leet->ray.map.map[i][j] == 'D' && sqrt((j * TILE_SIZE
						- leet->ray.player.vector.x) * (j * TILE_SIZE
						- leet->ray.player.vector.x) + (i * TILE_SIZE
						- leet->ray.player.vector.y) * (i * TILE_SIZE
						- leet->ray.player.vector.y)) < 2 * TILE_SIZE)
				door_sound(leet, i, j);
			else if (leet->ray.map.map[i][j] == 'O' && sqrt((j * TILE_SIZE
							- leet->ray.player.vector.x) * (j * TILE_SIZE
							- leet->ray.player.vector.x) + (i * TILE_SIZE
							- leet->ray.player.vector.y) * (i * TILE_SIZE
							- leet->ray.player.vector.y)) > 2 * TILE_SIZE)
				leet->ray.map.map[i][j] = 'D';
		}
	}
}
