/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:09:18 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/14 11:22:52 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void    setting_sounds(t_sound *sound)
{
    if (sound->up)
        (system(UP), sound->up = 0);
    if (sound->down)
        (system(DOWN), sound->down = 0);
    if (!sound->general)
        (system(MUTE));
    if (sound->general)
        (system(UNMUTE));
    if (!sound->sound)
        (system(KILL_SOUND), sound->is_run = 0);
    if (sound->sound && sound->sound1 && !sound->is_run)
        (system(S_KILL), system(S_SOUND1), sound->is_run = 1);
    if (sound->sound && sound->sound2 && !sound->is_run)
        (system(S_KILL), system(S_SOUND2), sound->is_run = 1);
    if (sound->sound && sound->sound3 && !sound->is_run)
        (system(S_KILL), system(S_SOUND3), sound->is_run = 1);
    if (sound->sound && sound->sound4 && !sound->is_run)
        (system(S_KILL), system(S_SOUND4), sound->is_run = 1);
    return ;
}


void    *sound_(void *ptr)
{
    t_sound *sound;
    
    sound = (t_sound *)ptr;
    while (true)
    {
        setting_sounds(sound);
        if (sound->sfx && sound->click)
            (system(S_CLICK), sound->click = 0);
        if (sound->cdoor && sound->sfx)
            (system(S_CDOOR), sound->cdoor = 0);
        if (sound->odoor && sound->sfx)
            (system(S_ODOOR), sound->odoor = 0);
        if (sound->run && sound->sfx)
            (system(S_RUN), sound->run = 0);
        if (sound->sfx && sound->damage)
            (system(S_DAMAGE), sound->run = 0);
        if (sound->shot && sound->sfx)
            (system(S_SHOT), sound->shot = 0);
        if (sound->enemy_shot && sound->sfx)
            (system(S_ENEMY_SHOT), sound->enemy_shot = 0);
    }
    return (NULL);
}