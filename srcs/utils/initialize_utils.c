/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:28:23 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/19 17:54:29 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

t_img	img_init(t_leet *leet, char *texture)
{
	t_img	img;
	int		size;

	size = TEXTURE_DIMENTION;
	img.img = mlx_xpm_file_to_image(leet->mlx, texture, &size, &size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

void	textures_initialize(t_leet *leet, t_parser *parser)
{
	leet->ray.map._north = img_init(leet, parser->texture[0]);
	leet->ray.map._south = img_init(leet, parser->texture[1]);
	leet->ray.map._west = img_init(leet, parser->texture[2]);
	leet->ray.map._east = img_init(leet, parser->texture[3]);
	if (leet->textures)
		init_ceil_floor(leet, leet->parser->n_texture);
	leet->ray.map._enemy = img_init(leet, "./assets/enemy1.xpm");
	leet->ray.map.medkit = img_init(leet, "./assets/med1.xpm");
	leet->ray.map._door = img_init(leet, "./assets/door.xpm");
	if (leet->ray.map.fire)
		free(leet->ray.map.fire);
	leet->ray.map.fire = malloc(sizeof(t_img) * 4);
	leet->ray.map.fire[0] = img_init(leet, "./assets/med1.xpm");
	leet->ray.map.fire[1] = img_init(leet, "./assets/med2.xpm");
	leet->ray.map.fire[2] = img_init(leet, "./assets/med3.xpm");
	leet->ray.map.fire[3] = img_init(leet, "./assets/med4.xpm");
}
