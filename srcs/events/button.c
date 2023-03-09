/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:58:06 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/09 19:59:16 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

t_short setting_button(int x, int y)
{
    t_short button;
    
    button =  (x > 281 && x < 400 && y > 165 && y < 205) * EVOLUME + \
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
    return (button);
}

t_short graphics_button(t_flag flag, int x, int y)
{
    t_short butt;
    
    if (flag & MAPS)
    {
        butt = (x > 0 && x < 439 && y > 0 && y < 445) * MAP1 + \
                (x > 440 && x < 879 && y > 0 && y < 445) * MAP2 + \
                (x > 0 && x < 439 && y > 450 && y < 719) * MAP3 + \
                (x > 440 && x < 879 && y > 450 && y < 719) * MAP4;
        return (butt);
    }
    butt = (x > 0 && x < 439 && y > 0 && y < 445) * TEXT1 + \
             (x > 440 && x < 879 && y > 0 && y < 445) * TEXT2 + \
             (x > 0 && x < 439 && y > 450 && y < 719) * TEXT3 + \
             (x > 440 && x < 879 && y > 450 && y < 719) * TEXT4 + \
             (x > 49 && x < 220 && y > 620 && y < 675) * BACK;
    return (butt);
}

t_short game_button(int x, int y, int flag)
{
    t_short butt;

    if (flag & P_GAME)
    {
        butt = (x > 5 && x < 97 && y > 11 && y < 55) * G_PAUSE + \
               (x > 0 && x < 0 && y > 0 && y < 0) * MOVE_RIGHT + \
               (x > 0 && x < 0 && y > 0 && y < 0) * MOVE_LEFT;
        return (butt);
    }
    if (flag & PAUSE)
    {
        butt = (x > 536 && x < 758 && y > 231 && y < 306) * RESUME + \
               (x > 536 && x < 758 && y > 343 && y < 419) * P_CONTRL + \
               (x > 536 && x < 758 && y >  456 && y < 526) * QUIT_G;
        return (butt);
    }
    if (flag & P_CNTRL)
    {
        butt =  (x > 332 && x < 604 && y > 204 && y < 342) * CNTRL_A + \
                (x > 675 && x < 951 && y > 200 && y < 340) * CNTRL_B + \
                (x > 530 && x < 820 && y > 375 && y < 593) * CNTRL_C;
        return (butt);
    }
    butt = (x > 1035 && x < 1193 && y > 455 && y < 486) * GAME + \
           (x > 1037 && x < 1121 && y > 510 && y < 526) * MAPS + \
           (x > 1037 && x < 1213 && y > 528 && y < 574) * TEXTURE + \
           (x > 1037 && x < 1188 && y > 607 && y < 622) * SETTING + \
           (x > 1037 && x < 1123 && y > 656 && y < 669) * G_EXIT; 
    return (butt);
}

t_short get_button(t_flag flag, int x, int y)
{
    t_short ret;

    if (flag & SETTING)
        ret = setting_button(x, y);
    else if (flag & (MAPS | TEXTURE))
        ret = graphics_button(flag, x, y);
    else if (flag & GAME)
        ret = game_button(x, y, P_GAME);
    else if (flag & G_PAUSE)
        ret = game_button(x, y, PAUSE);
    else if (flag & P_CONTRL)
        ret = game_button(x, y, P_CNTRL);
    else if (flag & HOME)
        ret = game_button(x, y, G_HOME);
    return (ret);
}
