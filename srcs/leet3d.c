/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:09:12 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/09 16:00:25 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"


void    g_render(t_data *data);

void    get_path(t_data *data)
{
    int height;
    int width;

    /**
     * ret = log2(flag);
     *          0 1 2 3
     */
    data->imgs[0] = mlx_xpm_file_to_image(data->mlx, "./pictures/home.xpm", &width, &height);
    data->imgs[1] = mlx_xpm_file_to_image(data->mlx, "./pictures/map.xpm", &width, &height);
    data->imgs[2] = mlx_xpm_file_to_image(data->mlx, "./pictures/map.xpm", &width, &height);
    data->imgs[3] = mlx_xpm_file_to_image(data->mlx, "./pictures/settings.xpm", &width, &height);
    
    data->imgs[4] = mlx_xpm_file_to_image(data->mlx, "./pictures/effmap.xpm", &width, &height);
    data->imgs[6] = mlx_xpm_file_to_image(data->mlx, "./pictures/efftextu.xpm", &width, &height);
    data->imgs[5] = mlx_xpm_file_to_image(data->mlx, "./pictures/effsetting.xpm", &width, &height);
    data->imgs[7] = mlx_xpm_file_to_image(data->mlx, "./pictures/effexit.xpm", &width, &height);
    
    data->imgs[8] = mlx_xpm_file_to_image(data->mlx, "./pictures/pause.xpm", &width, &height);
    data->imgs[9] = mlx_xpm_file_to_image(data->mlx, "./pictures/cntrl_pause.xpm", &width, &height);
}


int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
        error_(ERR_ARGS, 0, ERROR);
    ft_memset(&data, 0, sizeof(t_data));
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1280, 720, "leet3d");
    
    get_path(&data);
    // void *usa;
    // int test, seg;
    // usa = mlx_xpm_file_to_image(data.mlx, "./assets/lol.xpm", &test, &seg);

    mlx_put_image_to_window(data.mlx, data.win, *data.imgs, 0, 0);
    
    // data.flag = LOADING;
    mlx_loop_hook(data.mlx, (void *)g_render, &data);
    mlx_loop(data.mlx);
    exit(EXIT_SUCCESS);
}