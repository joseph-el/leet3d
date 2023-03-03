/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_leet3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:40:40 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/03 21:38:57 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"
# include <mlx.h>
# include <time.h>

# include <pthread.h>

typedef struct s_start
{
    void        *mlx;
    void        *win;
    void        *img;
    void        *s_image[4];
    int         flag;
}               t_data;



void    get_path(t_data *data)
{
    int seg;
    int test;
    
    data->s_image[0] = mlx_xpm_file_to_image(data->mlx, "./assets/start1.xpm", &test, &seg);
    data->s_image[1] = mlx_xpm_file_to_image(data->mlx, "./assets/start2.xpm", &test, &seg);
    data->s_image[2] = mlx_xpm_file_to_image(data->mlx, "./assets/start3.xpm", &test, &seg);
    data->s_image[3] = mlx_xpm_file_to_image(data->mlx, "./assets/game_start.xpm", &test, &seg);
}


typedef unsigned long long r_time;

# define LOADING 1
# define GAME 4
# define TEXTURES 3
# define HOME 2




void loading(t_data *data)
{
    
}
int starting(t_data *data)
{
    r_time t_time;

    t_time = time(NULL);

    if (data->flag == 1)
    {
        mlx_loop_hook(data->mlx, loading, data);
    }
    else if (data->flag == 2)
    {
        // home
    }
    else if (data->flag == 3)
    {
        // textures
    }
    else
        //game

    
    
}



int main(int argc, char **argv)
{
    t_data data;

    ft_memset(&data, 0, sizeof(t_data));

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1280, 720, "leet3d");
    data.win = mlx_new_window(data.mlx, 1280, 720, "leet3d");
    
    get_path(&data);
    data.flag = 1;
    
    mlx_loop_hook(data.mlx, starting, &data);


    mlx_loop(data.mlx);
    exit(EXIT_SUCCESS);
}








