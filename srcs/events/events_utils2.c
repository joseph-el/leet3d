/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:38:50 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/14 10:48:54 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void    p_control(t_leet *leet, t_short ret)
{
    if (ret & (CNTRL_A | CONTROL_A))
    {
        leet->cntrl.control_c = 0;
        leet->cntrl.control_b = 0;
        leet->cntrl.control_a = 1;
    }
    else if (ret & (CNTRL_B | CONTROL_B))
    {
        leet->cntrl.control_c = 0;
        leet->cntrl.control_a = 0;
        leet->cntrl.control_b = 1;
    }
    else if (ret & (CNTRL_C | CONTROL_C))
    {
        leet->cntrl.control_a = 0;
        leet->cntrl.control_b = 0;
        leet->cntrl.control_c = 1;
    }
    if (ret & (CNTRL_A | CNTRL_B | CNTRL_C))
        leet->flag = G_PAUSE;
    leet->sound.click = 1;
}

void    set_setting(t_leet *leet, t_short ret)
{
    if (ret & CONTROLS)
        return (p_control(leet, ret));
    else if (ret & (UVOLUME | DVOLUME))
    {
        leet->sound.up = (ret == UVOLUME);
        leet->sound.down = (ret == DVOLUME);
    }
    else if (ret & (MVOLUME | EVOLUME))
        leet->sound.general = (ret == EVOLUME);
    else if (ret & (MSOUND | ESOUND))
        leet->sound.sound = (ret == ESOUND);
    else if (ret & (MSFX | ESFX))
        leet->sound.sfx = (ret == ESFX);
    else if (ret & (SOUND1 | SOUND2 | SOUND3 | SOUND4))
    {
        leet->sound.sound1 = (ret == SOUND1);
        leet->sound.sound2 = (ret == SOUND2);
        leet->sound.sound3 = (ret == SOUND3);
        leet->sound.sound4 = (ret == SOUND4);
        leet->sound.is_run = 0;
    }
    else if (ret & BACK)
        leet->flag = HOME;
    leet->sound.click = 1;
}

void    g_graphics(t_leet *leet, t_short ret)
{
    if (ret & BACK)
        return ((void)(leet->flag = HOME));
    if (leet->flag & MAPS && ret & SET_MAP)
    {
        leet->parser->position = WEST;
        leet->parser->p_indices[0] = (ret == MAP1) * Y_MAP1 + \
            (ret == MAP2) * Y_MAP2 + (ret == MAP3) * Y_MAP3 + \
            (ret == MAP4) * Y_MAP4;
        leet->parser->p_indices[1] = (ret == MAP1) * X_MAP1 + \
            (ret == MAP2) * X_MAP2 + (ret == MAP3) * X_MAP3 + \
            (ret == MAP4) * X_MAP4;
        array_destroyer(&leet->parser->map);
        leet->parser->map = switch_map(ret);
    }
    if (leet->flag & TEXTURE && ret & SET_TEXTURE)
    {
        array_destroyer(&leet->parser->texture);
        leet->parser->texture = NULL;
        leet->parser->texture = switch_texture(ret);
    }
    leet->flag = HOME;
    leet->sound.click = 1;
}

void    g_pause(t_leet *leet, t_short ret)
{
    if (ret & QUIT_G)
        leet->flag = LOADING;
    else if (ret & P_CONTRL)
        leet->flag = P_CONTRL;
    else if (ret & RESUME)
        leet->flag = GAME;
    leet->sound.click = 1;
}






