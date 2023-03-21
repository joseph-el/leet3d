/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sync.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:11:46 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/19 22:28:24 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

static void	draw_hlt(t_leet *leet)
{
	void	*healt;
	int		s;

	healt = mlx_xpm_file_to_image(leet->mlx, "assets/hlt+.xpm", &s, &s);
	mlx_put_image_to_window(leet->mlx, leet->window, healt, 80, 80);
}

void	is_medkit(t_leet *leet, int x, int y)
{
	int	i;
	int	j;
	int	p_x;
	int	p_y;

	i = -1;
	p_x = (int)floor(x / TILE_SIZE);
	p_y = (int)floor(y / TILE_SIZE);
	while (leet->parser->map[++i])
	{
		j = -1;
		while (leet->parser->map[i][++j])
		{
			if (leet->parser->map[i][j] == 'K' && \
				((j == p_x && i == p_y + 1) || \
				(j == p_x && i == p_y - 1) || \
				(i == p_y && j == p_x - 1) || (i == p_y && j == p_x + 1)))
			{
				draw_hlt(leet);
				if (leet->p_health <= 995)
					leet->p_health += 5;
			}
		}
	}
}

void	is_enemy(t_leet *leet, int p_x, int p_y)
{
	int	i;
	int	j;
	int	cx;
	int	cy;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			cy = i - 5 + (int)floor(p_y / TILE_SIZE);
			cx = j - 5 + (int)floor(p_x / TILE_SIZE);
			if (cx >= 0 && cx < leet->parser->width && cy >= 0
				&& cy < leet->parser->height)
			{
				if (leet->parser->map[cy][cx] == 'Z')
				{
					leet->sound.enemy_shot = 1;
					leet->p_health -= 2;
					leet->sound.damage = 1;
				}
			}
		}
	}
}
