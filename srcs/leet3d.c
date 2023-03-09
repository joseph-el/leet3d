/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:18:01 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/09 22:34:32 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

/**
 * @brief Get the assets object
 * @ 7 * (4) = 28 img
 * img += 10
 * @param leet 
 */

void    get_assets(t_leet *leet)
{
    int height;
    int width;
    
    leet->img[0] = mlx_xpm_file_to_image(leet->mlx, "./assets/home.xpm", &width, &height);
    leet->img[1] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    leet->img[2] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    leet->img[3] = mlx_xpm_file_to_image(leet->mlx, "./assets/settings.xpm", &width, &height);
    leet->img[4] = mlx_xpm_file_to_image(leet->mlx, "./assets/effmap.xpm", &width, &height);
    leet->img[6] = mlx_xpm_file_to_image(leet->mlx, "./assets/efftextu.xpm", &width, &height);
    leet->img[5] = mlx_xpm_file_to_image(leet->mlx, "./assets/effsetting.xpm", &width, &height);
    leet->img[7] = mlx_xpm_file_to_image(leet->mlx, "./assets/effexit.xpm", &width, &height);
    leet->img[8] = mlx_xpm_file_to_image(leet->mlx, "./assets/pause.xpm", &width, &height);
    leet->img[9] = mlx_xpm_file_to_image(leet->mlx, "./assets/cntrl_pause.xpm", &width, &height);
    // <=> loading images :
    // leet->img[0] = mlx_xpm_file_to_image(leet->mlx, "./assets/home.xpm", &width, &height);
    // leet->img[1] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    // leet->img[2] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    // leet->img[3] = mlx_xpm_file_to_image(leet->mlx, "./assets/settings.xpm", &width, &height);
    // leet->img[4] = mlx_xpm_file_to_image(leet->mlx, "./assets/effmap.xpm", &width, &height);
    // leet->img[6] = mlx_xpm_file_to_image(leet->mlx, "./assets/efftextu.xpm", &width, &height);
    // leet->img[5] = mlx_xpm_file_to_image(leet->mlx, "./assets/effsetting.xpm", &width, &height);
    // leet->img[7] = mlx_xpm_file_to_image(leet->mlx, "./assets/effexit.xpm", &width, &height);
    // leet->img[8] = mlx_xpm_file_to_image(leet->mlx, "./assets/pause.xpm", &width, &height);
    // leet->img[9] = mlx_xpm_file_to_image(leet->mlx, "./assets/cntrl_pause.xpm", &width, &height);
    // leet->img[0] = mlx_xpm_file_to_image(leet->mlx, "./assets/home.xpm", &width, &height);
    // leet->img[1] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    // leet->img[2] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    // leet->img[3] = mlx_xpm_file_to_image(leet->mlx, "./assets/settings.xpm", &width, &height);
    // leet->img[4] = mlx_xpm_file_to_image(leet->mlx, "./assets/effmap.xpm", &width, &height);
    // leet->img[6] = mlx_xpm_file_to_image(leet->mlx, "./assets/efftextu.xpm", &width, &height);
    // leet->img[5] = mlx_xpm_file_to_image(leet->mlx, "./assets/effsetting.xpm", &width, &height);
    // leet->img[7] = mlx_xpm_file_to_image(leet->mlx, "./assets/effexit.xpm", &width, &height);
    // leet->img[8] = mlx_xpm_file_to_image(leet->mlx, "./assets/pause.xpm", &width, &height);
    // leet->img[9] = mlx_xpm_file_to_image(leet->mlx, "./assets/cntrl_pause.xpm", &width, &height);
    // leet->img[0] = mlx_xpm_file_to_image(leet->mlx, "./assets/home.xpm", &width, &height);
    // leet->img[1] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    // leet->img[2] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    // leet->img[3] = mlx_xpm_file_to_image(leet->mlx, "./assets/settings.xpm", &width, &height);
    // leet->img[4] = mlx_xpm_file_to_image(leet->mlx, "./assets/effmap.xpm", &width, &height);
    // leet->img[6] = mlx_xpm_file_to_image(leet->mlx, "./assets/efftextu.xpm", &width, &height);
    // leet->img[5] = mlx_xpm_file_to_image(leet->mlx, "./assets/effsetting.xpm", &width, &height);
    // leet->img[7] = mlx_xpm_file_to_image(leet->mlx, "./assets/effexit.xpm", &width, &height);
}

void    *sound(void *ptr)
{
    t_leet *leet;
    
    leet = (t_leet *)ptr;
    while (true)
    {
        if (!leet->sound.general)
            system("osascript -e set volume output volume 0");
        if (leet->sound.general_on)
            system("osascript -e set volume output volume 50");
        if (leet->sound.up)
            system("osascript -e set volume output volume (output volume of (get volume settings) + 10)");
        if (leet->sound.down)
            system("osascript -e set volume output volume (output volume of (get volume settings) - 10)");
        
        if (leet->sound.sound1 && leet->sound.sound)
            system("afplay /sounds/sound1.mp4");

    }
    return (NULL);
}


int main(int argc, char **argv)
{
    t_leet      leet;
    pthread_t   pid;

    if (argc != 2)
        error_(ERR_ARGS, 0, ERROR);
    argv ++;
    leet.parser = parser(*argv);
    get_assets(&leet);
    leet.mlx = mlx_init();
    leet.window = mlx_new_window(leet.mlx, 1280, 720, "Cub3d");
    
    
    
    pthread_create(&pid, NULL, sound, &leet);
    
    mlx_put_image_to_window(leet.mlx, leet.window, *leet.img, 0, 0);
    mlx_loop_hook(leet.mlx, (void *)g_render, &leet);
    mlx_loop(leet.mlx);
    exit(EXIT_SUCCESS);
}