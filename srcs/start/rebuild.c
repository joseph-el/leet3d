/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:47:34 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/08 23:40:47 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/leet3d.h"

t_short get_mode(int x, int y)
{
    t_short ret;

    ret = (x > 1035 && x < 1193 && y > 455 && y < 486) * GAME + \
          (x > 1037 && x < 1121 && y > 510 && y < 526) * MAPS + \
          (x > 1037 && x < 1213 && y > 528 && y < 574) * TEXTURE + \
          (x > 1037 && x < 1188 && y > 607 && y < 622) * SETTING + \
          (x > 1037 && x < 1123 && y > 656 && y < 669) * G_EXIT + \
        // SETTING
          (x > 281 && x < 400 && y > 165 && y < 205) * EVOLUME + \
          (x > 404 && x < 522 && y > 165 && y < 205) * MVOLUME + \
          (x > 281 && x < 400 && y > 265 && y < 300) * ESOUND + \
          (x > 404 && x < 522 && y > 265 && y < 300) * MSOUND + \
          (x > 281 && x < 400 && y > 360 && y < 397) * ESFX + \
          (x > 281 && x < 522 && y > 397 && y < 397) * MSFX + \
          (x > 299 && x < 355 && y > 447 && y < 488) * UVOLUME + \
          (x > 444 && x < 497 && y > 446 && y < 489) * DVOLUME + \
          (x > 236 && x < 308 && y > 536 && y < 588) * SOUND1 + \
          (x > 314 && x < 378 && y > 536 && y < 588) * SOUND2 + \
          (x > 385 && x < 446 && y > 536 && y < 588) * SOUND3 + \
          (x > 453 && x < 520 && y > 536 && y < 588) * SOUND4 + \
          (x > 584 && x < 872 && y > 286 && y < 432) * CONTROL_A + \
          (x > 945 && x < 1236 && y > 284 && y < 431) * CONTROL_B + \
          (x > 792 && x < 1099 && y > 463 && y < 696) * CONTROL_C + \
          (x > 49 && x < 220 && y > 620 && y < 675) * BACK + \
        // SELECT MAP | TEXTURES
          (x > 0 && x < 439 && y > 0 && y < 445) * MAP1 + \
          (x > 440 && x < 879 && y > 0 && y < 445) * MAP2 + \
          (x > 0 && x < 439 && y > 450 && y < 719) * MAP3 + \
          (x > 440 && x < 879 && y > 450 && y < 719) * MAP4 + \
          (x > 0 && x < 439 && y > 0 && y < 445) * TEXT1 + \
          (x > 440 && x < 879 && y > 0 && y < 445) * TEXT2 + \
          (x > 0 && x < 439 && y > 450 && y < 719) * TEXT3 + \
          (x > 440 && x < 879 && y > 450 && y < 719) * TEXT4 + \
        // IN GAME
          (x > 5 && x < 97 && y > 11 && y < 55) * G_PAUSE + \
          (x > 0 && x < 0 && y > 0 && y < 0) * MOVE_RIGHT + \
          (x > 0 && x < 0 && y > 0 && y < 0) * MOVE_LEFT + \
        // PAUSE GAME
          (x > 536 && x < 758 && y > 231 && y < 306) * RESUME + \
          (x > 536 && x < 758 && y > 343 && y < 419) * P_CONTRL + \
          (x > 536 && x < 758 && y >  456 && y < 526) * QUIT_G + \
          (x > 332 && x < 604 && y > 204 && y < 342) * CNTRL_A + \
          (x > 675 && x < 951 && y > 200 && y < 340) * CNTRL_B + \
          (x > 530 && x < 820 && y > 375 && y < 593) * CNTRL_C;
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





t_short get_mode(t_flag flag, int x, int y)
{
    t_short home;
    t_short sett;
    t_short map_tex;
    t_short game;
    t_short pause;
    t_short p_cntrl;
    t_short ret;

    home = (x > 1035 && x < 1193 && y > 455 && y < 486) * GAME + \
          (x > 1037 && x < 1121 && y > 510 && y < 526) * MAPS + \
          (x > 1037 && x < 1213 && y > 528 && y < 574) * TEXTURE + \
          (x > 1037 && x < 1188 && y > 607 && y < 622) * SETTING + \
          (x > 1037 && x < 1123 && y > 656 && y < 669) * G_EXIT;

    sett =   (x > 281 && x < 400 && y > 165 && y < 205) * EVOLUME + \
            (x > 404 && x < 522 && y > 165 && y < 205) * MVOLUME + \
            (x > 281 && x < 400 && y > 265 && y < 300) * ESOUND + \
            (x > 404 && x < 522 && y > 265 && y < 300) * MSOUND + \
            (x > 281 && x < 400 && y > 360 && y < 397) * ESFX + \
            (x > 281 && x < 522 && y > 397 && y < 397) * MSFX + \
            (x > 299 && x < 355 && y > 447 && y < 488) * UVOLUME + \
            (x > 444 && x < 497 && y > 446 && y < 489) * DVOLUME + \
            (x > 236 && x < 308 && y > 536 && y < 588) * SOUND1 + \
            (x > 314 && x < 378 && y > 536 && y < 588) * SOUND2 + \
            (x > 385 && x < 446 && y > 536 && y < 588) * SOUND3 + \
            (x > 453 && x < 520 && y > 536 && y < 588) * SOUND4 + \
            (x > 584 && x < 872 && y > 286 && y < 432) * CONTROL_A + \
            (x > 945 && x < 1236 && y > 284 && y < 431) * CONTROL_B + \
            (x > 792 && x < 1099 && y > 463 && y < 696) * CONTROL_C + \
            (x > 49 && x < 220 && y > 620 && y < 675) * BACK;
        
    map_tex = (x > 0 && x < 439 && y > 0 && y < 445) * MAP1 + \
          (x > 440 && x < 879 && y > 0 && y < 445) * MAP2 + \
          (x > 0 && x < 439 && y > 450 && y < 719) * MAP3 + \
          (x > 440 && x < 879 && y > 450 && y < 719) * MAP4 + \
          (x > 0 && x < 439 && y > 0 && y < 445) * TEXT1 + \
          (x > 440 && x < 879 && y > 0 && y < 445) * TEXT2 + \
          (x > 0 && x < 439 && y > 450 && y < 719) * TEXT3 + \
          (x > 440 && x < 879 && y > 450 && y < 719) * TEXT4 + \
          (x > 49 && x < 220 && y > 620 && y < 675) * BACK;
    
    game = (x > 5 && x < 97 && y > 11 && y < 55) * G_PAUSE + \
          (x > 0 && x < 0 && y > 0 && y < 0) * MOVE_RIGHT + \
          (x > 0 && x < 0 && y > 0 && y < 0) * MOVE_LEFT;


    pause = (x > 536 && x < 758 && y > 231 && y < 306) * RESUME + \
          (x > 536 && x < 758 && y > 343 && y < 419) * P_CONTRL + \
          (x > 536 && x < 758 && y >  456 && y < 526) * QUIT_G;
    
    p_cntrl = (x > 332 && x < 604 && y > 204 && y < 342) * CNTRL_A + \
                (x > 675 && x < 951 && y > 200 && y < 340) * CNTRL_B + \
                (x > 530 && x < 820 && y > 375 && y < 593) * CNTRL_C;

    ret = (flag == HOME) * home + (flag == SETTING) * sett + (flag == MAPS || flag == TEXTURE)\
     * map_tex + (flag == GAME) * game + (flag == G_PAUSE) * pause + (flag == P_CONTRL) * p_cntrl;
    return (ret);
}
