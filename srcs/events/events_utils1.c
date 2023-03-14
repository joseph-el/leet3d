/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:36:24 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/14 11:24:05 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void    key_events(int key, t_leet *leet)
{
    int ret;

    if (key == 53)
        exit(47);
    ret = 0;
    if (leet->cntrl.control_a)
    {
        ret = (key == A_KEY) * _MOVE_LEFT + (key == D_KEY) * _MOVE_RIGHT + \
              (key == S_KEY) * _MOVE_DOWN + (key == W_KEY) * _MOVE_UP + \
              (key == LEFT_KEY) * ROTATE_LEFT + (key == RIGHT_KEY) * ROTATE_RIGHT;
    }
    else if (leet->cntrl.control_b)
    {
        ret = (key == LEFT_KEY) * _MOVE_LEFT + (key == RIGHT_KEY) * _MOVE_RIGHT + \
              (key == DOWN_KEY) * _MOVE_DOWN + (key == UP_KEY) * _MOVE_UP + \
              (key == A_KEY) * ROTATE_LEFT + (key == D_KEY) * ROTATE_RIGHT;
    }
    if (ret)
        g_moving(leet, ret);
}

void    mouse_move(int button, int x, int y, t_leet *leet)
{
    t_short ret;

    if (button == 3 || leet->flag != GAME || !leet->cntrl.control_c)
        return ;
    if (button == 4)
        return (g_moving(leet, _MOVE_UP)); // move up
    else if (button == 5)
        return (g_moving(leet, _MOVE_DOWN)); // move down
    ret = get_button(leet->flag, x, y);
    if (button == 2 && ret & MOVE_RIGHT)
        return (g_moving(leet, _MOVE_RIGHT)); //move right
    else if (button == 2 && ret & MOVE_LEFT)
        return (g_moving(leet, _MOVE_LEFT)); // move left
    if (button == 1 && ret & MOVE_RIGHT)
        return (g_moving(leet, ROTATE_LEFT)); // rotate left
    else if (button == 1 && ret & MOVE_LEFT)
        return (g_moving(leet, ROTATE_RIGHT)); // rotate  right
}

void    mouse_button(int button, int x, int y, t_leet *leet)
{
    t_short ret;

    if (leet->flag & GAME)
        mouse_move(button, x, y, leet);
    if (button != 1)
        return ;
    ret = get_button(leet->flag, x, y);
    if (leet->flag & HOME && ret & (HOME_PAGE | G_EXIT))
        (leet->sound.click = 1, leet->flag = ret);
    if (leet->flag & (MAPS | TEXTURE) && ret & (SET_MAP | SET_TEXTURE | BACK))
        g_graphics(leet, ret);
    if (leet->flag & SETTING && ret & (SET_VOLUME | CONTROLS | SOUNDS | BACK))
        set_setting(leet, ret);
    if (leet->flag & G_PAUSE && ret & (RESUME | QUIT_G | P_CONTRL))
        g_pause(leet, ret);
    if (leet->flag & P_CONTRL && ret & (CNTRL_A | CNTRL_B | CNTRL_C))
        p_control(leet, ret);
    if (leet->flag & GAME && ret & G_PAUSE)
        leet->flag = G_PAUSE;
}

void    mouse_events(int x, int y, t_leet *leet)
{
    t_short ret;
    int     img;

    if (leet->flag != HOME)
        return ;
    ret = get_button(HOME, x, y);
    img = (ret == MAPS) * 6 + (ret == G_EXIT) * 9 + \
            (ret == TEXTURE) * 7 + (ret == SETTING) * 8;
    if (ret & (SETTING | MAPS | G_EXIT | TEXTURE))
        mlx_put_image_to_window(leet->mlx, leet->window, leet->img[img], 0, 0);
    else
        mlx_put_image_to_window(leet->mlx, leet->window, *leet->img, 0, 0);
}