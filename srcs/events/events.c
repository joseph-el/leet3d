/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:37:31 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/21 21:33:11 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	game(t_leet *leet)
{
	// enemy(leet);
	// open_door(leet);
	raycasting(leet);
	render(leet);
	minimap_(leet);
	draw_gun(leet);
	// is_enemy(leet, leet->ray.player.vector.x, leet->ray.player.vector.y);
	// is_medkit(leet, leet->ray.player.vector.x, leet->ray.player.vector.y);
	draw_healty(leet);
	mlx_destroy_image(leet->mlx, leet->ray.img.img);
	mlx_destroy_image(leet->mlx, leet->minimap.build.img);
	mlx_destroy_image(leet->mlx, leet->minimap.img.img);
	if (leet->p_health < 0)
	{
		usleep(1000000);
		leet->flag = DIE;
	}
}

void	game_events(t_leet *leet, t_flag flag)
{
	int	img;

	img = (flag == HOME) * 0 + (flag == MAPS) * 1 + \
		(flag == TEXTURE) * 2 + (flag == SETTING) * 3 + \
		(flag == G_PAUSE) * 4 + (flag == P_CONTRL) * 5;
	if (flag & HOME && leet->flag_img)
	{
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[img], 0, 0);
		leet->flag_img = 0;
	}
	if (flag & ~(GAME | HOME))
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[img], 0, 0);
	if (flag & GAME)
		game(leet);
	mlx_hook(leet->window, 17, 0, (void *)ft_exit, leet);
	mlx_hook(leet->window, 6, 1L << 2, (void *)mouse_events, leet);
	mlx_hook(leet->window, 2, 0, (void *)key_events, leet);
	mlx_mouse_hook(leet->window, (void *)mouse_button, leet);
}

void	g_render(t_leet *leet)
{
	if (leet->flag & HOME && !leet->is_run)
		initialize(leet, leet->parser);
	if (leet->flag & DIE)
		is_die(leet);
	if (leet->flag & LOADING)
		g_loading(leet, leet->flag_img);
	else if (leet->flag & (HOME_PAGE | HOME | G_PAUSE | P_CONTRL))
		game_events(leet, leet->flag);
	else if (leet->flag & G_EXIT)
		(system(S_KILL), exit(EXIT_SUCCESS));
}
