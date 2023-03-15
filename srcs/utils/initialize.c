/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 01:37:10 by mtellami          #+#    #+#             */
/*   Updated: 2023/03/15 20:58:13 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void    default_setting(t_leet *leet)
{
    get_assets(leet);
    leet->flag = LOADING;
    leet->cntrl.control_a = 1;
    leet->cntrl.control_b = 0;
    leet->cntrl.control_c = 0;
    leet->cntrl.loading = 1;
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
    leet->p_health = 100;
    leet->flag_img = G_HOME;
}

t_img	img_init(t_leet *leet, char *texture)
{
	t_img	img;
	int		size;

	size = TEXTURE_DIMENTION;
	img.img = mlx_xpm_file_to_image(leet->mlx, texture, &size, &size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	textures_initialize(t_leet *leet, t_parser *parser)
{
	leet->ray.map._north = img_init(leet, parser->texture[0]);
	leet->ray.map._south = img_init(leet, parser->texture[1]);
	leet->ray.map._west = img_init(leet, parser->texture[2]);
	leet->ray.map._east = img_init(leet, parser->texture[3]);
	// leet->ray.map._door = img_init(leet, "textures/door.xpm");
	// leet->ray.map.fire = malloc(sizeof(t_img) * 9);
	// leet->ray.map.fire[0] = img_init(leet, "textures/fire01.xpm");
	// leet->ray.map.fire[1] = img_init(leet, "textures/fire02.xpm");
	// leet->ray.map.fire[2] = img_init(leet, "textures/fire03.xpm");
	// leet->ray.map.fire[3] = img_init(leet, "textures/fire04.xpm");
	// leet->ray.map.fire[4] = img_init(leet, "textures/fire05.xpm");
	// leet->ray.map.fire[5] = img_init(leet, "textures/fire06.xpm");
	// leet->ray.map.fire[6] = img_init(leet, "textures/fire07.xpm");
	// leet->ray.map.fire[7] = img_init(leet, "textures/fire08.xpm");
	// leet->ray.map.fire[8] = img_init(leet, "textures/fire09.xpm");
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
}


void    get_loading_assets(t_leet *leet)
{
    int height;
    int width;
    
    leet->img[17] = mlx_xpm_file_to_image(leet->mlx, "./assets/2L1.xpm", &width, &height);
    leet->img[18] = mlx_xpm_file_to_image(leet->mlx, "./assets/2L2.xpm", &width, &height);
    leet->img[19] = mlx_xpm_file_to_image(leet->mlx, "./assets/2L3.xpm", &width, &height);
    leet->img[20] = mlx_xpm_file_to_image(leet->mlx, "./assets/2L4.xpm", &width, &height);
    leet->img[21] = mlx_xpm_file_to_image(leet->mlx, "./assets/2L5.xpm", &width, &height);
    leet->img[22] = mlx_xpm_file_to_image(leet->mlx, "./assets/2L6.xpm", &width, &height);
    leet->img[23] = mlx_xpm_file_to_image(leet->mlx, "./assets/2L7.xpm", &width, &height);
    leet->img[24] = mlx_xpm_file_to_image(leet->mlx, "./assets/3L1.xpm", &width, &height);
    leet->img[25] = mlx_xpm_file_to_image(leet->mlx, "./assets/3L2.xpm", &width, &height);
    leet->img[26] = mlx_xpm_file_to_image(leet->mlx, "./assets/3L3.xpm", &width, &height);
    leet->img[27] = mlx_xpm_file_to_image(leet->mlx, "./assets/3L4.xpm", &width, &height);
    leet->img[28] = mlx_xpm_file_to_image(leet->mlx, "./assets/3L5.xpm", &width, &height);
    leet->img[29] = mlx_xpm_file_to_image(leet->mlx, "./assets/3L6.xpm", &width, &height);
    leet->img[30] = mlx_xpm_file_to_image(leet->mlx, "./assets/3L7.xpm", &width, &height);
    leet->img[31] = mlx_xpm_file_to_image(leet->mlx, "./assets/r1.xpm", &width, &height);
    leet->img[32] = mlx_xpm_file_to_image(leet->mlx, "./assets/r2.xpm", &width, &height);
    leet->img[33] = mlx_xpm_file_to_image(leet->mlx, "./assets/r3.xpm", &width, &height);
    leet->img[34] = mlx_xpm_file_to_image(leet->mlx, "./assets/r4.xpm", &width, &height);
    leet->img[35] = mlx_xpm_file_to_image(leet->mlx, "./assets/r5.xpm", &width, &height);
    leet->img[36] = mlx_xpm_file_to_image(leet->mlx, "./assets/r6.xpm", &width, &height);
    leet->img[37] = mlx_xpm_file_to_image(leet->mlx, "./assets/r7.xpm", &width, &height);
}

void    get_assets(t_leet *leet)
{
    int height;
    int width;

    leet->img[0] = mlx_xpm_file_to_image(leet->mlx, "./assets/home.xpm", &width, &height);
    leet->img[1] = mlx_xpm_file_to_image(leet->mlx, "./assets/map_page.xpm", &width, &height);
    leet->img[2] = mlx_xpm_file_to_image(leet->mlx, "./assets/page_textures.xpm", &width, &height);
    leet->img[3] = mlx_xpm_file_to_image(leet->mlx, "./assets/settings.xpm", &width, &height);
    leet->img[4] = mlx_xpm_file_to_image(leet->mlx, "./assets/pause.xpm", &width, &height);
    leet->img[5] = mlx_xpm_file_to_image(leet->mlx, "./assets/cntrl_pause.xpm", &width, &height);
    leet->img[6] = mlx_xpm_file_to_image(leet->mlx, "./assets/effmap.xpm", &width, &height);
    leet->img[7] = mlx_xpm_file_to_image(leet->mlx, "./assets/efftextu.xpm", &width, &height);
    leet->img[8] = mlx_xpm_file_to_image(leet->mlx, "./assets/effsetting.xpm", &width, &height);
    leet->img[9] = mlx_xpm_file_to_image(leet->mlx, "./assets/effexit.xpm", &width, &height);
    leet->img[10] = mlx_xpm_file_to_image(leet->mlx, "./assets/1L1.xpm", &width, &height);
    leet->img[11] = mlx_xpm_file_to_image(leet->mlx, "./assets/1L2.xpm", &width, &height);
    leet->img[12] = mlx_xpm_file_to_image(leet->mlx, "./assets/1L3.xpm", &width, &height);
    leet->img[13] = mlx_xpm_file_to_image(leet->mlx, "./assets/1L4.xpm", &width, &height);
    leet->img[14] = mlx_xpm_file_to_image(leet->mlx, "./assets/1L5.xpm", &width, &height);
    leet->img[15] = mlx_xpm_file_to_image(leet->mlx, "./assets/1L6.xpm", &width, &height);
    leet->img[16] = mlx_xpm_file_to_image(leet->mlx, "./assets/1L7.xpm", &width, &height);
    get_loading_assets(leet);
}