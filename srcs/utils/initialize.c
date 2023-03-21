/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:25:36 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/19 21:58:19 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	default_setting(t_leet *leet)
{
	get_assets(leet);
	leet->flag = LOADING;
	leet->cntrl.control_a = 1;
	leet->cntrl.control_b = 0;
	leet->cntrl.control_c = 0;
	ft_memset(&leet->sound, 0, sizeof(t_sound));
	leet->sound.sfx = 1;
	leet->sound.sound = 1;
	leet->sound.sound1 = 1;
	leet->sound.general = 1;
	leet->enemy.indexs = NULL;
	leet->enemy.ret = NULL;
	leet->crr_img = 0;
	leet->enemy.last_time = clock();
	leet->l_time = clock();
	leet->p_health = 1000;
	leet->flag_img = G_HOME;
	leet->cntrl.shoot = 0;
	leet->textures = 0;
	leet->is_run = 0;
	leet->ray.map.fire = NULL;
}

void	init_tab(t_parser **container)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		(*container)->c_ceiling[i] = -1;
		(*container)->c_floor[i] = -1;
	}
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

void	init_ceil_floor(t_leet *leet, int ret)
{
	char	**packages;
	int		i;

	i = (ret == TEXT1) * 0 + (ret == TEXT2) * 1 + \
		(ret == TEXT3) * 2 + (ret == TEXT4) * 3;
	packages = ft_split(CEIL_FLOR, 32);
	if (!packages)
		error_(NULL, ENOMEM, FATAL);
	leet->ray.ceil = img_init(leet, packages[i]);
	leet->ray.floor = img_init(leet, packages[i]);
	array_destroyer(&packages);
}

void	initialize(t_leet *leet, t_parser *parser)
{
	map_initialize(leet, parser);
	leet->ray.player.vector.x = parser->p_indices[1] * TILE_SIZE;
	leet->ray.player.vector.y = parser->p_indices[0] * TILE_SIZE;
	leet->ray.player.fov = 60 * (M_PI / 180);
	leet->ray.player.rays = 0x0;
	leet->ray.player.frame = 0;
	if (parser->position == NORTH)
		leet->ray.player.angle = 1.5 * M_PI;
	else if (parser->position == SOUTH)
		leet->ray.player.angle = 0.5 * M_PI;
	else if (parser->position == WEST)
		leet->ray.player.angle = M_PI;
	else if (parser->position == EAST)
		leet->ray.player.angle = 0;
	leet->is_run = 1;
}
