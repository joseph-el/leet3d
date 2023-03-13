/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:45:18 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/13 21:50:15 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"


int main(int argc, char **argv)
{
    t_leet      leet;
    pthread_t   _sounds;

    (void)argv;
    if (argc != 2)
        error_(ERR_ARGS, 0, ERROR);
    argv ++;
    leet.parser = parser(*argv);
    leet.mlx = mlx_init();
    leet.window = mlx_new_window(leet.mlx, 1280, 720, "Cub3d");
    
    
    get_assets(&leet);
    default_setting(&leet);
    pthread_create(&_sounds, NULL, sound, &leet);
    
    mlx_loop_hook(leet.mlx, (void *)g_render, &leet.sound);
    mlx_loop(leet.mlx);



    
    exit(EXIT_SUCCESS);
}