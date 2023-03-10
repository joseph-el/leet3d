/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:45:18 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/10 23:46:15 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void    get_assets(t_leet *leet)
{
    int height;
    int width;

    leet->img[0] = mlx_xpm_file_to_image(leet->mlx, "./assets/home.xpm", &width, &height);
    leet->img[1] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    leet->img[2] = mlx_xpm_file_to_image(leet->mlx, "./assets/map.xpm", &width, &height);
    leet->img[3] = mlx_xpm_file_to_image(leet->mlx, "./assets/settings.xpm", &width, &height);
    leet->img[4] = mlx_xpm_file_to_image(leet->mlx, "./assets/pause.xpm", &width, &height);
    leet->img[5] = mlx_xpm_file_to_image(leet->mlx, "./assets/cntrl_pause.xpm", &width, &height);
    leet->img[6] = mlx_xpm_file_to_image(leet->mlx, "./assets/effmap.xpm", &width, &height);
    leet->img[7] = mlx_xpm_file_to_image(leet->mlx, "./assets/efftextu.xpm", &width, &height);
    leet->img[8] = mlx_xpm_file_to_image(leet->mlx, "./assets/effsetting.xpm", &width, &height);
    leet->img[9] = mlx_xpm_file_to_image(leet->mlx, "./assets/effexit.xpm", &width, &height);

    // <=> loading images :

    leet->img[10] = mlx_xpm_file_to_image(leet->mlx, "./assets/start1.xpm", &width, &height);
    leet->img[11] = mlx_xpm_file_to_image(leet->mlx, "./assets/start2.xpm", &width, &height);
    leet->img[12] = mlx_xpm_file_to_image(leet->mlx, "./assets/start3.xpm", &width, &height);
    leet->img[13] = mlx_xpm_file_to_image(leet->mlx, "./assets/start4.xpm", &width, &height);
    leet->img[14] = mlx_xpm_file_to_image(leet->mlx, "./assets/start5.xpm", &width, &height);
    leet->img[15] = mlx_xpm_file_to_image(leet->mlx, "./assets/start6.xpm", &width, &height);
    leet->img[16] = mlx_xpm_file_to_image(leet->mlx, "./assets/start7.xpm", &width, &height);
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

void default_setting(t_leet *leet)
{
    leet->flag = LOADING;
    leet->cntrl.control_a = 0;
    leet->cntrl.control_b = 0;
    leet->cntrl.control_c = 1;
    ft_memset(&leet->sound, 0, sizeof(t_sound));
    leet->sound.sfx = 1;
    leet->sound.sound = 1;
    leet->sound.sound1 = 1;
    leet->sound.general = 1;
}

void	game(t_leet *leet)
{
	raycasting(leet);
	render(leet);
}


# define UP "osascript -e \"set volume output volume (output volume of (get volume settings) + 10)\""
# define DOWN "osascript -e \"set volume output volume (output volume of (get volume settings) - 10)\""
# define MUTE "osascript -e \"set volume with output muted\""
# define UNMUTE "osascript -e \"set volume without output muted\""
void    *sound(void *ptr)
{
    t_leet *leet;
    
    leet = (t_leet *)ptr;
    while (true)
    {
        if (leet->sound.up)
            (system(UP), leet->sound.up = 0);
        if (leet->sound.down)
            (system(DOWN), leet->sound.down = 0);
        if (!leet->sound.general)
            (system(MUTE));
        if (leet->sound.general)
            (system(UNMUTE));
        if (leet->sound.cdoor && leet->sound.sfx)
            (system("afplay ./sounds/eff1.wav"), leet->sound.cdoor = 0);
        if (leet->sound.odoor && leet->sound.sfx)
            (system("afplay ./sounds/eff2.wav"), leet->sound.odoor = 0);
        if (leet->sound.run && leet->sound.sfx)
            (system("afplay ./sounds/eff2.wav"), leet->sound.run = 0);
        if (leet->sound.shot && leet->sound.sfx)
            (system("afplay ./sounds/eff2.wav"), leet->sound.shot = 0);
        usleep(500);
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
    leet.mlx = mlx_init();
    leet.window = mlx_new_window(leet.mlx, 1280, 720, "Cub3d");
    get_assets(&leet);
    default_setting(&leet);

    pthread_create(&pid, NULL, sound, &leet);
    initialize(&leet, leet.parser);
    mlx_loop_hook(leet.mlx, (void *)g_render, &leet);
    mlx_loop(leet.mlx);
    exit(EXIT_SUCCESS);
}