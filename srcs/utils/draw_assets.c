/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:31:25 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/19 16:42:36 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	is_die(t_leet *leet)
{
	static clock_t	l_time = 0;
	double			elapsed_time;

	if (!l_time)
	{
		system(KILL_SHOT);
		leet->sound.over = 1;
		l_time = clock();
	}
	elapsed_time = (double)(clock() - l_time) / CLOCKS_PER_SEC;
	mlx_put_image_to_window(leet->mlx, leet->window, leet->img[53], 0, 0);
	if (elapsed_time >= 3)
	{
		leet->flag = LOADING;
		leet->flag_img = P_GAME;
		leet->p_health = 1000;
		l_time = 0;
	}
}

void	draw_gun(t_leet *leet)
{
	static int	gun_img = 2;
	float		elapsed_time;

	elapsed_time = (float)(clock() - leet->l_time) / CLOCKS_PER_SEC;
	if (!leet->cntrl.shoot)
		return (draw_(leet, GUN_1), destroy_(leet, 0));
	if (elapsed_time < 0.1 && leet->cntrl.shoot)
		return ;
	if (gun_img & GUN_2)
		(system(S_SHOT), draw_(leet, GUN_2), gun_img += 2);
	else if (gun_img & GUN_3)
		(draw_(leet, GUN_3), gun_img += 4);
	else if (gun_img & GUN_4)
		(draw_(leet, GUN_4), gun_img += 8);
	else if (gun_img & GUN_5)
		(draw_(leet, GUN_5), gun_img += 16);
	else if (gun_img & GUN_6)
		(system(S_RELOAD), draw_(leet, GUN_6), gun_img += 32);
	else if (gun_img & GUN_7)
		(draw_(leet, GUN_7), gun_img += 64);
	else if (gun_img & GUN_8)
		(draw_(leet, GUN_8), gun_img = 2, leet->cntrl.shoot = 0);
	destroy_(leet, 0);
	leet->l_time = clock();
}

void	draw_healty(t_leet *leet)
{
	get_action(leet, HEALT1);
	mlx_put_image_to_window(leet->mlx, leet->window, leet->img[52], 5, 5);
	if (leet->p_health >= 900 && leet->p_health <= 1000)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[46], 12, 30);
	else if (leet->p_health >= 700 && leet->p_health <= 900)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[47], 12, 30);
	else if (leet->p_health >= 500 && leet->p_health <= 700)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[48], 12, 30);
	else if (leet->p_health >= 300 && leet->p_health <= 500)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[49], 12, 30);
	else if (leet->p_health >= 200 && leet->p_health <= 300)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[50], 12, 30);
	else if (leet->p_health >= 0 && leet->p_health <= 100)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[51], 12, 30);
	destroy_(leet, HEALT5);
}

void	draw_(t_leet *leet, int flag)
{
	get_action(leet, GUN_4);
	if (flag & GUN_1)
	{
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[38], MX, MY);
		return ;
	}
	if (flag & GUN_2)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[39], MX, MY);
	else if (flag & GUN_3)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[40], MX, MY);
	else if (flag & GUN_4)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[41], MX, MY);
	else if (flag & GUN_5)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[42], MX, MY);
	else if (flag & GUN_6)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[43], MX, MY);
	else if (flag & GUN_7)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[44], MX, MY);
	else if (flag & GUN_8)
		mlx_put_image_to_window(leet->mlx, leet->window, leet->img[45], MX, MY);
}
