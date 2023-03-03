/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:54:59 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/03 23:39:41 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"
# include <time.h>
# include <mlx.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *s_image[10];
    bool flag;
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


typedef enum s_flag
{
    TEXTURE = 1 << 0,
    LOADING = 1 << 1,
    ABOUT   = 1 << 4,
    GAME = 1 << 2,
    HOME = 1 << 3
}               t_flag;

typedef struct timeval	t_time;

unsigned int	get_second(void)
{
	t_time	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec);
}

int   loading(t_data *data)
{
    static unsigned int r_time = 0;
    
    r_time = 0;
    while (r_time < 400)
    {
        if (r_time < 100)
            mlx_put_image_to_window(data->mlx, data->win, data->s_image[0], 0, 0);
        else if (r_time < 200)
            mlx_put_image_to_window(data->mlx, data->win, data->s_image[1], 0, 0);

        else
            mlx_put_image_to_window(data->mlx, data->win, data->s_image[2], 0, 0);
        // if (r_time == 300)
        //     r_time = 0;
        r_time ++;
    }
return 1;
}





int main(int argc, char **argv)
{
    t_data *data = malloc(sizeof(t_data));
    int     pid;
    
    ft_memset(data, 0, sizeof(t_data));
    
    pid = fork();
    if (pid == 0)
    {
        data->mlx = mlx_init();
        data->win = mlx_new_window(data->mlx, 1280, 720, "leet3d");
        get_path(data);
        loading(data);
        mlx_loop_hook(data->mlx, loading, data);
        mlx_loop(data->mlx);
        // exit(0);
    }
    else
        waitpid(pid, NULL, 0);

    

    
    exit(EXIT_SUCCESS);
}

