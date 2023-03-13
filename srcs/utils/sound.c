/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:09:18 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/13 23:46:56 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

# define S_KILL "ps -ef | grep -E \"afplay | afplay | afplay afplay\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null"

# define S_SOUND1 "afplay ./sounds/music1.mp3 -v 100 &" 
# define S_SOUND2 "afplay ./sounds/music2.mp3 -v 100 &" 
# define S_SOUND3 "afplay ./sounds/music3.mp3 -v 100 &" 
# define S_SOUND4 "afplay ./sounds/music4.mp3 -v 100 &" 

# define S_RUN "afplay ./sounds/run.wav &" 
# define S_ODOOR "afplay ./sounds/odoor.wav &" 
# define S_CDOOR "afplay ./sounds/cdoor.wav &" 
# define S_SHOT "afplay ./sounds/shoot.wav &" 
# define S_ENEMY_SHOT "afplay ./sounds/enemy_shoot.wav &"
# define S_DAMAGE "afplay ./sounds/damage.wav &"
# define S_CLICK "afplay ./sounds/click.wav &"

void    *sound_(void *ptr)
{
    t_sound *sound;
    
    sound = (t_sound *)ptr;
    while (true)
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
            (system(S_KILL), sound->is_run = 0);
        if (sound->sound && sound->sound1 && !sound->is_run)
            (system(S_KILL), system(S_SOUND1), sound->is_run = 1);
        if (sound->sound && sound->sound2 && !sound->is_run)
            (system(S_KILL), system(S_SOUND2), sound->is_run = 1);
        if (sound->sound && sound->sound3 && !sound->is_run)
            (system(S_KILL), system(S_SOUND3), sound->is_run = 1);
        
        if (sound->sound && sound->sound4 && !sound->is_run)
            (system(S_KILL), system(S_SOUND4), sound->is_run = 1);


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