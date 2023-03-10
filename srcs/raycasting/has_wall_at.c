/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:53:02 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/10 16:22:49 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

int	map_has_wall_at(char **map, double x, double y)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	while (map[size])
		size++;
	j = floor(x / TILE_SIZE);
	i = floor(y / TILE_SIZE);
	if (i < 0 || i >= size || j < 0 || j >= (int)ft_strlen(map[i]))
		return (1);
	return (map[i][j] == '1');
}
