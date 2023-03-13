/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:44 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/13 16:59:45 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void	g_moving(t_leet *leet, int flag)
{
	if (flag & _MOVE_UP)
		_move(leet, leet->ray.player.angle, 1);
	else if (flag & _MOVE_DOWN)
		_move(leet, leet->ray.player.angle, -1);
	else if (flag & _MOVE_RIGHT)
		_move(leet, leet->ray.player.angle + 0.5 * M_PI, 1);
	else if (flag & _MOVE_LEFT)
		_move(leet, leet->ray.player.angle + 0.5 * M_PI, -1);
	else if (flag & ROTATE_LEFT)
		_rotate(leet, -1);
	else if (flag & ROTATE_RIGHT)
		_rotate(leet, 1);
    else
        return ;
    leet->sound.run = 1;
}

void    ft_exit(void)
{
    exit(42);
}

void    print_u_(char **arr)
{
    int i = 0;
    int j = 0;
    
    while (arr[i])
    {
        j = -1;
        while (arr[i][++j])
        {
            if (arr[i][j] == 'Z')
                fprintf(stderr, GREEN"%c"WHITE, arr[i][j]);
            else
                fprintf(stderr, RED"%c"WHITE, arr[i][j]);
        }
        puts("");
        i ++;
    }
    puts("");
    puts("");
}

void    game(t_leet *leet)
{
    enemy(leet);
    raycasting(leet);
    render(leet);
    // minimap_(leet);
}

void    game_events(t_leet *leet, t_flag flag)
{
    int img;

    img = (flag == HOME) * 0 + (flag == MAPS) * 1 + \
            (flag == TEXTURE) * 2 + (flag == SETTING) * 3 + \
            (flag == G_PAUSE) * 4 + (flag == P_CONTRL) * 5;
    
    if (flag != GAME)
        mlx_put_image_to_window(leet->mlx, leet->window, leet->img[img], 0, 0);

    if (flag & GAME)
    {
        game(leet);
        mlx_hook(leet->window, 2, 0, (void *)key_events, leet);
    }
    mlx_hook(leet->window, 17, 0, (void *)ft_exit, leet);    
    mlx_hook(leet->window, 6, 1L << 2, (void *)mouse_events, leet);
    mlx_mouse_hook(leet->window, (void *)mouse_button, leet);
}

void    g_render(t_leet *leet)
{
    static int  ret;
    
    if (leet->flag & HOME)
        initialize(leet, leet->parser);
    
    if (leet->flag & LOADING)
        g_loading(leet, ret);
    else if (leet->flag & (HOME_PAGE | HOME | G_PAUSE | P_CONTRL))
        game_events(leet, leet->flag);
    else if (leet->flag & G_EXIT)
        exit(85);
    ret = 1;
}