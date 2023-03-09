/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:57:14 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/09 20:20:35 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/leet3d.h"

void    mouse_events(int x, int y, t_leet *leet)
{
    t_short ret;
    int     img;

    if (leet->flag & ~HOME)
        return ;
    ret = get_button(HOME, x, y);
    img = (ret == MAPS) * 4 + (ret == G_EXIT) * 7 + \
            (ret == TEXTURE) * 6 + (ret == SETTING) * 5;
    if (ret & (SETTING | MAPS | G_EXIT | TEXTURE))
        mlx_put_image_to_window(leet->mlx, leet->window, leet->img[img], 0, 0);
    else
        mlx_put_image_to_window(leet->mlx, leet->window, *leet->img, 0, 0);
}

void    mouse_button(int button, int x, int y, t_leet *leet)
{
    t_short ret;

    if (button != 1)
        return ;
    ret = get_button(leet->flag, x, y);
    if (leet->flag & HOME && ret & (HOME_PAGE | G_EXIT))
        leet->flag = ret;
    if (leet->flag & GAME && ret & (G_PAUSE | MOVE_RIGHT | MOVE_LEFT))
        set_gaming(leet, ret);
    if (leet->flag & (MAPS | TEXTURE) && ret & (SET_MAP | SET_TEXTURE | BACK))
        game_style(leet, ret);
    if (leet->flag & SETTING && ret & (SET_VOLUME | CONTROLS | SOUNDS))
        set_setting(leet, ret);
    if (leet->flag & G_PAUSE && ret & (RESUME | QUIT_G | CONTROLS))
        g_pause(leet, ret);
}

void    game_events(t_leet *leet, t_flag flag)
{
    int img;

    img = log2(flag);
    if (flag & ~HOME)
        mlx_put_image_to_window(leet->mlx, leet->window, leet->img[img], 0, 0);
    mlx_hook(leet->window, 6, 1L << 2, (void *)mouse_events, leet);
    mlx_mouse_hook(leet->window, (void *)mouse_button, leet);
}

void    g_render(t_leet *leet)
{
    if (leet->flag & LOADING)
        g_loading(leet);
    if (leet->flag & (HOME_PAGE | HOME | G_PAUSE))
        game_events(leet, leet->flag);
    else if (leet->flag & G_EXIT)
        exit(EXIT_SUCCESS);
}