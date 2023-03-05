/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:07:29 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/05 20:48:18 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/leet3d.h"

void    get_path(t_data *data)
{
    int seg;
    int seg1;
    
    data->imgs[0] = mlx_xpm_file_to_image(data->mlx, "./assets/start1.xpm", &seg1, &seg);
    data->imgs[1] = mlx_xpm_file_to_image(data->mlx, "./assets/start2.xpm", &seg1, &seg);
    data->imgs[2] = mlx_xpm_file_to_image(data->mlx, "./assets/start3.xpm", &seg1, &seg);
    data->imgs[3] = mlx_xpm_file_to_image(data->mlx, "./assets/start4.xpm", &seg1, &seg);
    data->imgs[4] = mlx_xpm_file_to_image(data->mlx, "./assets/start5.xpm", &seg1, &seg);
    data->imgs[5] = mlx_xpm_file_to_image(data->mlx, "./assets/start6.xpm", &seg1, &seg);
    data->imgs[6] = mlx_xpm_file_to_image(data->mlx, "./assets/start7.xpm", &seg1, &seg);
}

int     loading(t_data *data)
{
    static clock_t  l_time;
    static int      crr_img;
    clock_t         r_time;

    r_time = clock();
    l_time = 0;
    if (r_time - l_time / CLOCKS_PER_SEC > 4)
    {
        if (crr_img == 8)
            return (crr_img = 0, data->flag = HOME);
        mlx_clear_window(data->mlx, data->win);
        mlx_put_image_to_window(data->mlx, data->win, data->imgs[crr_img++], 0, 0);
    }
    sleep(1);
    l_time = clock();
    return (EXIT_SUCCESS);
}

typedef enum s_slection
{
    MAP1 = 1 << 0,
    MAP2 = 1 << 1,
    MAP3 = 1 << 2,
    MAP4 = 1 << 3,
    TEXTURE1 = 1 << 4,
    TEXTURE2 = 1 << 5,
    TEXTURE3 = 1 << 6,
    TEXTURE4 = 1 << 7,
    MOVE_LEFT = 1 << 8,
    START_GAME = 1 << 9,
    MOVE_RIGHT = 1 << 10,
    SELECT_BACK = 1 << 11,
    SELECT_EXIT = 1 << 12,
    SELECT_MAPS = 1 << 13,
    SELECT_ABOUT = 1 << 14,
    SELECT_PAUSE = 1 << 15,
    SELECT_RESUME = 1 << 16,
    SELECT_TEXTURES = 1 << 17
}           t_slection;

void    mouse_button(int button, int x, int y, t_data *data)
{
    t_slection mode;
    
    if (button != 1 || button != 2)
        return ;
    mode =   (x > 500 && y < 500) * MAP1 + \
             (x > 500 && y < 500) * MAP2 + \
             (x > 500 && y < 500) * MAP3 + \
             (x > 500 && y < 500) * MAP4 + \
             (x > 500 && y < 500) * TEXTURE1 + \
             (x > 500 && y < 500) * TEXTURE2 + \
             (x > 500 && y < 500) * TEXTURE3 + \
             (x > 500 && y < 500) * TEXTURE4 + \
             (x > 1123 && y > 360) * SELECT_MAPS + \
             (x > 1123 && y < 360) * START_GAME + \
             (x > 1123 && y > 360) * SELECT_ABOUT + \
             (x > 1123 && y > 360) * SELECT_TEXTURES + \


             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * SELECT_PAUSE + \
             (x >= 144 && x <= 500 && y >= 200 && y <= 600) * MOVE_LEFT + \
             (x >= 144 && x <= 500 && y >= 200 && y <= 600) * MOVE_RIGHT + \
             (x >= 111 && x < 255 && y > 122 && y < 123) * SELECT_RESUME + \
             (x >= 650 && x <= 122 && y >= 444 && y < 155) * SELECT_BACK;
    
    if (data->flag & HOME && mode & (START_GAME | SELECT_ABOUT | SELECT_TEXTURES | SELECT_MAPS))
        data->flag = (mode == START_GAME) * GAME + (mode == SELECT_ABOUT) * ABOUT;
    if (data->flag & GAME && mode & (SELECT_PAUSE | MOVE_LEFT | MOVE_RIGHT))
        game_controler(data, mode);
    if (data->flag & TEXTURE && mode & (TEXTURE1 | TEXTURE2 | TEXTURE3 | TEXTURE4))
        data->flag = TEXTURE;
    if (data->flag & ABOUT && mode & SELECT_BACK)
        data->flag = HOME;
    if (data->flag & MAPS && mode & (MAP1 | MAP2 | MAP3 | MAP4))
        maps_controler(data, mode);
}



























void    mouse_effects(int x, int y, t_data *data)
{
    unsigned int ret;

    if (data->flag & HOME)
    {
        // ret = (A START GAME) | (A MAPS | ABOOUT TEXTURES);
        
    }
    if (data->flag & START)
    {

    }
    if (data->flag & TEXTURE)
    {

    }
    if (data->flag & ABOUT)
    {

    }
}


void    home(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[7], 0, 0);
    mlx_hook(data->win, 6, 1L << 2, (void *)mouse_effects, data);
    mlx_mouse_hook(data->win, (void *)mouse_button, data);
}







void    starting(t_data *data)
{
    if (data->flag & LOADING)
        loading(data);
    else if (data->flag & HOME)
        home(data);
    else if (data->flag & GAME)
        game(data);
    else if (data->flag & START)
        pause_game(data);
    else if (data->flag & ABOUT)
        about(data);
    else if (data->flag & EXIT)
        exit(177);
    else if (data->flag & (TEXTURE | MAPS))
        game_mode(data);
}