/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 08:07:10 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/14 13:46:24 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void    draw_grid(t_img *src, int map_y, int map_x)
{
    int i;
    int x;
    int y;
    int s_x;
    int s_y;

    y = -1;
    while (++y < map_y)
    {
        x = -1;
        while (++x < map_x)
        {
            s_x = x * SCOPE;
            s_y = y * SCOPE;
            i = s_x - 1;
            while (i++ < s_x + SCOPE)
                put_pixel(src, i, s_y, 0x000000);
            i = s_y - 1;
            while (i++ < s_y + SCOPE)
                put_pixel(src, s_x, i, 0x000000);
        }
    }
}

void    draw_squares(t_leet *leet)
{
    int x;
    int y;
    int s_x;
    int s_y;

    y = -1;
    while (leet->parser->map[++y])
    {
        x = -1;
        while (leet->parser->map[y][++x])
        {
            s_x = x * SCOPE;
            s_y = y * SCOPE;
            if (leet->parser->map[y][x] == '1')
                draw_square(&leet->minimap.build, s_y, s_x, 0xFFFFFF);
            else if (ft_strchr("NSWE0", leet->parser->map[y][x]))
                draw_square(&leet->minimap.build, s_y, s_x, 0x222222);
            else if (leet->parser->map[y][x] == 'Z')
                draw_square(&leet->minimap.build, s_y, s_x, 0x00A346);
        }
    }
}

void    draw_minimap(t_minimap *minimap)
{
    int             x;
    int             y;
    int             s_x;
    int             s_y;
    bool            ret;
    unsigned int    color;
    
    s_x = minimap->p_x + SCOPE;
    s_y = minimap->p_y + SCOPE;
    y = -(MINIMAP_H / 2);
    while (y < MINIMAP_H / 2)
    {
        x = -(MINIMAP_W / 2);
        while (x < MINIMAP_W / 2)
        {
            color = 0x000000;
            ret = (s_x + x >= 0 && s_y + y >= 0 && s_x + x < minimap->img_width \
                && s_y + y < minimap->img_height);
            if (ret)
                color = get_colors(&minimap->build, y + s_y, x + s_x);
			put_pixel(&minimap->img, y + 100, x + 100, color);
            x ++;
        }
        y ++;
    }
}

void    minimap_(t_leet *leet)
{
    t_minimap   *minimap;

    minimap = &leet->minimap;
    ft_memset(minimap, 0, sizeof(t_minimap));
    ft_memset(&minimap->build, 0, sizeof(t_img));
    ft_memset(&minimap->img, 0, sizeof(t_img));
    minimap->img_width = leet->parser->width * SCOPE + 1;
    minimap->img_height = leet->parser->height * SCOPE + 1;
    minimap->build.img = mlx_new_image(leet->mlx, minimap->img_width, minimap->img_height);
    minimap->build.addr = mlx_get_data_addr(minimap->build.img, &minimap->build.bits_per_pixel, \
    &minimap->build.line_length, &minimap->build.endian);
    minimap->p_x = (int)floor(leet->ray.player.vector.x / TILE_SIZE);
	minimap->p_y = (int)floor(leet->ray.player.vector.y / TILE_SIZE); 
    draw_squares(leet);
    draw_grid(&minimap->build, leet->parser->height, leet->parser->width);
    draw_player(&minimap->build, minimap->p_x, minimap->p_y);
    minimap->img.img = mlx_new_image(leet->mlx, 200, 200);
    minimap->img.addr = mlx_get_data_addr(minimap->img.img, &minimap->img.bits_per_pixel, \
    &minimap->img.line_length, &minimap->img.endian);
    draw_minimap(minimap);
    mlx_put_image_to_window(leet->mlx, leet->window, leet->minimap.img.img, 0, 0);
    free(leet->minimap.img.img);
    free(leet->minimap.build.img);
}


// int	get_colors(t_img *src, int x, int y)
// {
// 	char	*dest;
// 	int		color;

// 	dest = src->addr + (y * src->line_size + x * (src->bits_per_pixel / 8));
// 	color = *(unsigned int *)dest;
// 	return (color);
// }

// void	put_pixel(t_img *src, int width, int height, int color)
// {
// 	char	*dest;

// 	dest = src->addr + (height * src->line_size + width * (src->bits_per_pixel / 8));
// 	*(unsigned int *)dest = color;
// }

// void    draw_player(t_img *src, int p_x, int p_y)
// {
//     int i;
//     int j;
//     int s_x;
//     int s_y;
    
//     i = -1;
//     s_x = p_x * SCOPE;
//     s_y = p_y * SCOPE;
//     while (++i < 8)
//     {
//         j = -1;
//         while (++j < 6)
//             put_pixel(src, s_y + j, s_x + i, 0xFF0000);
//     }
// }

// void    draw_square(t_img *img, int s_x, int s_y, unsigned int color)
// {
//     int i;
//     int j;

//     i = s_y;
//     while (i < s_y + SCOPE)
//     {
//         j = s_x;
//         while (j < s_x + SCOPE)
//         {
//             put_pixel(img, i, j, color);
//             j ++;
//         }
//         i ++;
//     }
// }

// void    draw_grid(t_img *src, int map_y, int map_x)
// {
//     int i;
//     int x;
//     int y;
//     int s_x;
//     int s_y;

//     y = -1;
//     while (++y < map_y)
//     {
//         x = -1;
//         while (++x < map_x)
//         {
//             s_x = x * SCOPE;
//             s_y = y * SCOPE;
//             i = s_x - 1;
//             while (i++ < s_x + SCOPE)
//                 put_pixel(src, i, s_y, 0x000000);
//             i = s_y - 1;
//             while (i++ < s_y + SCOPE)
//                 put_pixel(src, s_x, i, 0x000000);
//         }
//     }
// }

// void    draw_squares(t_mlx_data *leet)
// {
//     int x;
//     int y;
//     int s_x;
//     int s_y;

//     y = -1;
//     while (leet->map_data.map[++y])
//     {
//         x = -1;
//         while (leet->map_data.map[y][++x])
//         {
//             s_x = x * SCOPE;
//             s_y = y * SCOPE;
//             if (leet->map_data.map[y][x] == '1')
//                 draw_square(&leet->minimap.build, s_y, s_x, 0xFFFFFF);
//             else if (ft_strchr("NSWE0", leet->map_data.map[y][x]))
//                 draw_square(&leet->minimap.build, s_y, s_x, 0x222222);
//         }
//     }
// }



// void    draw_minimap(t_minimap *minimap)
// {
//     int             x;
//     int             y;
//     int             s_x;
//     int             s_y;
//     int            ret;
//     unsigned int    color;
    
//     s_x = minimap->p_x * SCOPE;
//     s_y = minimap->p_y * SCOPE;
//     y = -(MINIMAP_H / 2);
//     while (y < MINIMAP_H / 2)
//     {
//         x = -(MINIMAP_W / 2);
//         while (x < MINIMAP_W / 2)
//         {
//             color = 0x000000;
//             ret = (s_x + x >= 0 && s_y + y >= 0 && s_x + x < minimap->img_height && s_y + y < minimap->img_width);
//             if (ret)
//                 color = get_colors(&minimap->build, y + s_y, x + s_x);
// 			put_pixel(&minimap->img, y + 100, x + 100, color);
//             x ++;
//         }
//         y ++;
//     }
// }


// void    minimap_(t_mlx_data *leet)
// {
//     t_minimap   *minimap;

//     minimap = &leet->minimap;
//     ft_memset(minimap, 0, sizeof(t_minimap));
//     ft_memset(&minimap->build, 0, sizeof(t_img));
//     ft_memset(&minimap->img, 0, sizeof(t_img));


	
//     minimap->img_width = leet->map_data.longest_line * SCOPE + 1;
//     minimap->img_height = 48 * SCOPE + 1;

	
//     minimap->build.img = mlx_new_image(leet->mlx_ptr, minimap->img_width, minimap->img_height);

//     minimap->build.addr = mlx_get_data_addr(minimap->build.img, &minimap->build.bits_per_pixel, \
// 	&minimap->build.line_size, &minimap->build.endian);
    
	
// 	minimap->p_x = (int)floor(leet->player.y / 64);
// 	minimap->p_y = (int)floor(leet->player.x / 64); 
    


// 	draw_squares(leet);

// 	// fprintf(stderr, "check |%d|\n", leet->map_data.longest_line);
//     draw_grid(&minimap->build, 48,  leet->map_data.longest_line );
//     draw_player(&minimap->build, minimap->p_x, minimap->p_y);


	
//     minimap->img.img = mlx_new_image(leet->mlx_ptr, 200, 200);
	
//     minimap->img.addr = mlx_get_data_addr(minimap->img.img, &minimap->img.bits_per_pixel, \
//     &minimap->img.line_size, &minimap->img.endian);
    
	
	
// 	draw_minimap(minimap);
//     mlx_put_image_to_window(leet->mlx_ptr, leet->window, leet->minimap.img.img, 0, 0);
//     free(leet->minimap.img.img);
//     free(leet->minimap.build.img);
// }
