/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:19:50 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/09 21:12:52 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/leet3d.h"

int     g_loading(t_leet *leet)
{
    static clock_t  l_time;
    static int      crr_img;
    clock_t         r_time;

    r_time = clock();
    l_time = 0;
    if (r_time - l_time / CLOCKS_PER_SEC > 4)
    {
        if (crr_img == 8)
            return (crr_img = 0, leet->flag = HOME);
        mlx_clear_window(leet->mlx, leet->window);
        mlx_put_image_to_window(leet->mlx, leet->window, leet->img[crr_img++], 0, 0);
    }
    sleep(1);
    l_time = clock();
    return (EXIT_SUCCESS);
}

void    g_graphics(t_leet *leet, t_short ret)
{
    if (ret & BACK)
        return ((void)(leet->flag = HOME));
    if (leet->flag & MAPS && ret & SET_MAP)
    {
        array_destroyer(leet->parser->map);
        leet->parser->map = switch_map(&leet, ret);
    }
    if (leet->flag & TEXTURE && ret & SET_TEXTURE)
    {
        array_destroyer(leet->parser->texture);
        leet->parser->texture = switch_texture(ret);
    }
    leet->flag = HOME;
}

void    g_pause(t_leet *leet, t_short ret)
{
    if (ret & QUIT_G)
        leet->flag = LOADING;
    else if (ret & P_CONTRL)
        leet->flag = P_CONTRL;
    else if (ret & RESUME)
        leet->flag = GAME;
}

void    set_setting(t_leet *leet, t_short ret)
{
    if (ret & CONTROLS)
        return; // set_moving
    else if (ret & (UVOLUME | DVOLUME))
        system("up down");
    else if (ret & (MVOLUME | EVOLUME))
        system("OFF ON");
    else if (ret & (MSOUND | ESOUND))
        system("ON | OFF sound");
    else if (ret & (MSFX | ESFX))
        system("ON | OFF SFX");
    else if (ret & (SOUND1 | SOUND2 | SOUND3 | SOUND4))
        system("set sound");
    else if (ret & BACK)
        leet->flag = HOME;
}