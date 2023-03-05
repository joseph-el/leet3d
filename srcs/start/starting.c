/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:45:36 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/05 23:45:31 by yoel-idr         ###   ########.fr       */
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

void    mouse_button(int button, int x, int y, t_data *data)
{
    unsigned short ret;

    /**
     * @brief Gen click position [x][y];
    **/
    ret =    (x > 1123 && y > 360) * MAPS + \
             (x > 1123 && y < 360) * GAME + \
             (x > 1123 && y > 360) * ABOUT + \
             (x > 1123 && y > 360) * TEXTURE + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START + \
             (x >= 0 && x <= 20 && y >= 0 && y <= 20) * START;

    if (data->flag & HOME && ret & (HOME_PAGE | EXIT_G))
        data->flag = ret;
    else if (data->flag & TEXTURE && ret & (SET_TEXTURE | BACK))
        set();
    else if (data->flag & MAPS && ret & (SET_MAP | BACK))
        set();
    else if (data->flag & GAME && ret & (START | MOVE_LEFT | MOVE_RIGHT))
        set();
    else if (data->flag & START && ret & (QUIT_G | RESUME))
        set();
    else if (data->flag & SETTING && ret & (CONTROLS | SET_VOLUME | SOUNDS | BACK))
        set();
}

void    set_textures(t_data *data, t_select flag)
{
    if (flag & BACK)
        return ((void)(data->flag = HOME));
    if (flag & TEXT1)
    {
        
    }
    if (flag & TEXT2)
    {

    }
    if (flag & TEXT3)
    {

    }
    if (flag & TEXT4)
    {
        
    }
    return ((void)(data->flag = HOME));
}

void    set_map(t_data *data, t_select flag)
{
    if (flag & BACK)
        return ((void)(data->flag = HOME));
    if (flag & MAP1)
    {
        
    }
    if (flag & MAP2)
    {

    }
    if (flag & MAP3)
    {

    }
    if (flag & MAP4)
    {
        
    }
    return ((void)(data->flag = HOME));
}

void    game_control(t_data *data, t_select flag)
{
    if (flag & START)
        data->flag = START;
    
    // if (flag & (MOVE_LEFT | MOVE_RIGHT))
    // edit on postion of player;
}

void    game_pause(t_data *data, t_select flag)
{
    if (flag & RESUME)
        data->flag = GAME;
    else if (flag & QUIT_G)
        loading(data);
} 

void    set_setting(t_data *data, t_select flag)
{
    if (flag & BACK)
        data->flag = HOME;
    if (flag & SOUNDS)
    {
        // set system() sound
    }
    if (flag & CONTROLS)
    {
        // set_controls
    }
    if (flag & SET_VOLUME)
    {
        // set system voulume
    }
}


void    mouse_events(int x, int y, t_data *data)
{
    unsigned short  ret;

    // ret = get_square of {x, y};
    if (data->flag & HOME && ret & (HOME_PAGE | G_EXIT))
    {
        ret = log2(ret);
        // puts image
    }
    else if (data->flag & SETTING && ret & (CONTROLS | SET_VOLUME | SOUNDS | BACK))
    {
        ret = log2(ret);
        // puts image
    }
    else if (data->flag & TEXTURE && ret & (BACK | SET_TEXTURE))
    {
        ret = log2(ret);
        // puts image
    }
    else if (data->flag & MAPS && ret & (BACK | SET_MAP))
    {
        ret = log2(ret);
        // puts image
    }
    else if (data->flag & ABOUT && ret & BACK)
    {
        ret = log2(ret);
        // puts image
    }
}


void    home(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[7], 0, 0);
    mlx_hook(data->win, 6, 1L << 2, (void *)mouse_events, data);
    mlx_mouse_hook(data->win, (void *)mouse_button, data);
}

void    starting(t_data *data)
{
    if (data->flag & LOADING)
        loading(data);
    else if (data->flag & HOME)
        home(data);
    else if (data->flag & (MAPS | ABOUT | TEXTURE))
        mode_game(data, data->flag);
    else if (data->flag & SETTING)
        setting();
    else if (data->flag & START)
        start();
    else if (data->flag & GAME)
        game();
}