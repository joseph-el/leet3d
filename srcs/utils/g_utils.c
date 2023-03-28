/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:47:48 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/28 00:03:10 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

int	open_maps(t_short ret)
{
	int	fd_map;

	fd_map = 0;
	if (ret & MAP1)
		fd_map = open(C_MAP1, O_RDONLY);
	else if (ret & MAP2)
		fd_map = open(C_MAP2, O_RDONLY);
	else if (ret & MAP3)
		fd_map = open(C_MAP3, O_RDONLY);
	else
		fd_map = open(C_MAP4, O_RDONLY);
	return (fd_map);
}

int	choose_number(void)
{
	int	numbers[3];
	int	index;

	numbers[0] = 17;
	numbers[1] = 24;
	numbers[2] = 31;
	index = rand() % 3;
	return (numbers[index]);
}

int	can_move(char **map, double x, double y)
{
	return (map_has_wall_at(map, x, y) == _SPACE || map_has_wall_at(map, x,
			y) == _EXIT);
}

int	get_random(int min, int max)
{
	int	random_num;

	srand(time(NULL));
	while (1)
	{
		random_num = rand() % (max - min + 1) + min;
		if (random_num % 2 == 0)
			break ;
	}
	return (random_num);
}

int	get_height(char **map)
{
	int	i;
	int	height;

	i = 0;
	height = ft_strlen(*map);
	while (map && map[i])
	{
		if ((int)ft_strlen(map[i]) > height)
			height = ft_strlen(map[i]);
		i++;
	}
	return (height);
}
