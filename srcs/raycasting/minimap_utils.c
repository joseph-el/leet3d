/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:06:45 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/15 21:41:30 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

int	get_colors(t_img *src, int x, int y)
{
	char	*dest;
	int		color;

	dest = src->addr + (y * src->line_length + x * (src->bits_per_pixel / 8));
	color = *(unsigned int *)dest;
	return (color);
}

void	put_pixel(t_img *src, int width, int height, int color)
{
	char	*dest;

	dest = src->addr + (height * src->line_length + width * (src->bits_per_pixel
				/ 8));
	*(unsigned int *)dest = color;
}

void	draw_player(t_img *src, int p_x, int p_y)
{
	int	i;
	int	j;
	int	s_x;
	int	s_y;

	i = -1;
	s_x = p_x * SCOPE;
	s_y = p_y * SCOPE;
	while (++i < 8)
	{
		j = -1;
		while (++j < 6)
			put_pixel(src, s_y + j, s_x + i, 0xFF0000);
	}
}

void	draw_square(t_img *img, int s_x, int s_y, unsigned int color)
{
	int	i;
	int	j;

	i = s_y;
	while (i < s_y + SCOPE)
	{
		j = s_x;
		while (j < s_x + SCOPE)
		{
			put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}
