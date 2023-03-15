/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:27:45 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/15 11:05:26 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

int main(int argc, char **argv)
{
    t_leet      leet;
    pthread_t   _sounds;

    if (argc != 2)
        error_(ERR_ARGS, 0, ERROR);
    argv ++;
    leet.parser = parser(*argv);

    leet.mlx = mlx_init();
    leet.window = mlx_new_window(leet.mlx, 1280, 720, "Cub3d");
    default_setting(&leet);
    
    
    leet.l_time = clock();
    pthread_create(&_sounds, NULL, sound_, &leet.sound);
    mlx_loop_hook(leet.mlx, (void *)g_render, &leet);
    mlx_loop(leet.mlx);
    exit(EXIT_SUCCESS);
}