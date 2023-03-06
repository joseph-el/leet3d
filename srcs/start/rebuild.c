/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:47:34 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/06 12:38:51 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/leet3d.h"

t_short get_mode(int x, int y)
{
    t_short ret;
    /**
     * @brief HOME PAGE
     */
    ret = (x > 1123 && x < 1200 && y >= 0 && y <= 360) * GAME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAPS + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * ABOUT + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * G_EXIT + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SETTING + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXTURE +\
    /**
     * @brief SETTING PAGES
     */
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * BACK + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MSOUND + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * USOUND + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND1 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND2 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND3 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND4 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * DVOLUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * UVOLUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MVOLUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * UEFFCTS + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MEFFCTS + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_A + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_B + \
    /**
     * @brief TEXTURES PAGE | MAPS PAGES
     */
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT1 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT2 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT3 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT4 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP1 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP2 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP3 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP4 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * BACK + \
    /**
     * @brief GAME PAGE
     */
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * G_PAUSE + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MOVE_RIGHT + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MOVE_LEFT + \
    /**
     * @brief G_PAUSE PAGES
     */
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * RESUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * QUIT_G + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_A + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_B;

    return (ret);
}

int     g_loading(t_data *data)
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

void    g_exit(t_data *data)
{
    exit(14);
}

void    set_gaming(t_data *data, t_short ret)
{
    if (ret & (MOVE_LEFT | MOVE_RIGHT))
        return ; // move raycasting LEFT | RIGHT
    data->flag = G_PAUSE;
}

void    game_style(t_data *data, t_short ret)
{
    // const char *tex[];
    // const char *map[];
    if (ret & TEXTURE)
    {
        // free textures
        // replace textures 
    }
    if (ret & MAPS)
    {
        // free maps
        // replace maps
    }
    if (ret & BACK)
        data->flag = HOME;
}

void    set_setting(t_data *data, t_short ret)
{
    if (ret & (CONTROL_A | CONTROL_B))
        return ; // set global control to ret;
    else if (ret & (DVOLUME | UVOLUME | MVOLUME))
        return (system("string of volume"));
    else if (ret & (MSOUND | MEFFCTS))
        return ; // set Var of palying sound | sound_effects;
    else if (ret & SOUNDS)
        return ; // paly some sound by log2(ret);
}

void    g_pause(t_data *data, t_short ret)
{
    if (ret & QUIT_G)
        data->flag = LOADING;
    else if (ret & (CONTROL_A | CONTROL_B))
        return ; // set global control to ret;
    else if (ret & RESUME)
        data->flag = GAME;
}

void    mouse_button(int button, int x, int y, t_data *data)
{
    t_short ret;

    if (button != 1)
        return ;
    ret = get_mode(x, y);
    if (data->flag & HOME && ret & (HOME_PAGE | G_EXIT))
        data->flag = ret;
    if (data->flag & GAME && ret & (G_PAUSE | MOVE_RIGHT | MOVE_LEFT))
        set_gaming(data, ret);
    if (data->flag & (MAPS | TEXTURE) && ret & (SET_MAP | SET_TEXTURE | BACK))
        game_style(data, ret);
    if (data->flag & ABOUT && ret & BACK)
        data->flag = HOME;
    if (data->flag & SETTING && ret & (SET_VOLUME | CONTROLS | SOUNDS))
        set_setting(data, ret);
    if (data->flag & G_PAUSE && ret & (RESUME | QUIT_G | CONTROLS))
        g_pause(data, ret);
}

void    mouse_events(int x, int y, t_data *data)
{
    t_short ret;
    t_flag  flag;
    int     img;
    
    ret = get_mode(x, y);
    if (!ret)
        return ;
    img = log2(ret);
    if (flag & HOME)
        mlx_put_image_to_window(data->mlx, data->win, data->imgs[img], 0, 0);
    else if (flag & SETTING)
        mlx_put_image_to_window(data->mlx, data->win, data->imgs[img], 0, 0);
    else if (flag & G_PAUSE)
        mlx_put_image_to_window(data->mlx, data->win, data->imgs[img], 0, 0);
    else if (flag & (TEXTURE | MAPS | ABOUT))
        mlx_put_image_to_window(data->mlx, data->win, data->imgs[img], 0, 0);
}

void    game_events(t_data *data, t_flag flag)
{
    int image;

    image = log2(flag);
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[image], 0, 0);
    mlx_hook(data->win, 6, 1L << 2, (void *)mouse_events, data);
    mlx_mouse_hook(data->win, (void *)mouse_button, data);
}

void    g_render(t_data *data)
{
    if (data->flag & LOADING)
        g_loading(data);
    else if (data->flag & (HOME_PAGE | HOME | G_PAUSE))
        game_events(data, data->flag);
    else if (data->flag & G_EXIT)
        g_exit(data);
}