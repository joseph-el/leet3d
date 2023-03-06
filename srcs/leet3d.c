/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:09:12 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/06 19:12:04 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
        error_(ERR_ARGS, 0, ERROR);
    ft_memset(&data, 0, sizeof(t_data));
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1280, 720, "leet3d");
    
    void *usa;
    int test, seg;
    usa = mlx_xpm_file_to_image(data.mlx, "./assets/joseph.xpm", &test, &seg);

    mlx_put_image_to_window(data.mlx, data.win, usa, 0, 0);
    
    // data.flag = LOADING;
    // mlx_loop_hook(data.mlx, (void *)starting, &data);
    mlx_loop(data.mlx);
    exit(EXIT_SUCCESS);
}