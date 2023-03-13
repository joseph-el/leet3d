/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:18:57 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/13 18:49:39 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

int     g_loading(t_leet *leet, int flag)
{
    static clock_t  l_time;
    static int      crr_img = 10;
    clock_t         r_time;

    r_time = clock();
    (void)flag;
    if (r_time - l_time / CLOCKS_PER_SEC > 4)
    {
        if (crr_img == 17)
            return (crr_img = 10, leet->flag = HOME);
        mlx_clear_window(leet->mlx, leet->window);
        mlx_put_image_to_window(leet->mlx, leet->window, leet->img[crr_img++], 0, 0);
    }
    usleep(400);
    l_time = clock();
    return (EXIT_SUCCESS);
}

char    **switch_map(t_short ret)
{
    char    **map;
    char    *line;
    int     fd_map;
    int     i;

    if (ret & MAP1)
        fd_map = open(C_MAP1, O_RDONLY);
    else if  (ret & MAP2)
        fd_map = open(C_MAP2, O_RDONLY);
    else if (ret & MAP3)
        fd_map = open(C_MAP3, O_RDONLY);
    else
        fd_map = open(C_MAP4, O_RDONLY);
    map = malloc(sizeof(char *) * 50);
    if (fd_map == -1 || !map)
        error_(NULL, ENOMEM, FATAL);
    line = get_next_line(fd_map);
    i = 0;
    while (line)
    {
        map[i++] = ft_strdup(line);
        free(line);
        line = get_next_line(fd_map);
    }
    map[i] = NULL;
    return (close(fd_map), map);
}

char    **switch_texture(t_short ret)
{
    char    **texture;
    char    **package;
    int     i;

    package = ft_split(TEXTURES_PACKAGE, 32);
    texture = malloc(sizeof(char *) * 5);
    texture[4] = NULL;
    if (!package || !texture)
        error_("SSS", ENOMEM, FATAL);
    i = (ret == TEXT1) * 0 + (ret == TEXT2) * 4 + \
        (ret == TEXT3) * 8 + (ret == TEXT4) * 12;
    while (package[i] && i < 5)
    {
        texture[i] = ft_strdup(package[i]);
        i ++;
    }
    array_destroyer(&package);
    return (texture);
}