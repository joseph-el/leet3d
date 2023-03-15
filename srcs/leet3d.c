/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:27:45 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/15 22:22:49 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

bool is_enemy(t_parser *parser, int p_x, int p_y)
{
    int     i;
    int     j;
    int     cx;
    int     cy;
    bool    ret;

    i = -1;
    while (++i < 10)
    {
        j = -1;
        while (++j < 10)
        {
            cy = i - 5 + (int)floor(p_y / TILE_SIZE);
            cx = j - 5 + (int)floor(p_x / TILE_SIZE);
            ret = (cx >= 0 && cx < parser->width && cy >= 0 && \
                cy < parser->height && parser->map[cy][cx] == 'Z');
            if (ret)
                return (true);
        }
    }
        return (false);
}

void    *enemy_(void *ptr)
{
    t_leet *leet;

    leet = (t_leet *)ptr;
    while (true)
    {
        if (is_enemy(leet->parser, leet->ray.player.vector.x, leet->ray.player.vector.y))
        {
            system(S_ENEMY_SHOT);
            usleep(250);
            system(S_DAMAGE);
            leet->p_health -= 20;
        }
        
    
    }
    return (NULL);
}


int main(int argc, char **argv)
{
    t_leet      leet;
    pthread_t   _sounds;
    pthread_t   _enemy;

    if (argc != 2)
        error_(ERR_ARGS, 0, ERROR);
    argv ++;
    leet.parser = parser(*argv);

    leet.mlx = mlx_init();
    leet.window = mlx_new_window(leet.mlx, 1280, 720, "Cub3d");
    default_setting(&leet);
    
    leet.l_time = clock();
    
    
    
    pthread_create(&_enemy, NULL, enemy_, &leet);
    pthread_create(&_sounds, NULL, sound_, &leet.sound);
    mlx_loop_hook(leet.mlx, (void *)g_render, &leet);
    mlx_loop(leet.mlx);
    exit(EXIT_SUCCESS);
}