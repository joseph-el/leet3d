/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:41:10 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/15 14:41:53 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

int choose_number(void)
{
    int numbers[3];
    int index;
    
    numbers[0] = 17;
    numbers[1] = 24;
    numbers[2] = 31;
    index = rand() % 3;
    return (numbers[index]);
}

void   g_loading(t_leet *leet, int flag)
{
    float       elapsed_time;
    t_flag      destination;
    static int  i = 0;
    
    destination = (flag == G_HOME) * HOME + \
                  (flag == P_GAME) * HOME + \
                  (flag == INGANE) * GAME;
    if (flag & G_HOME && !leet->crr_img)
        leet->crr_img = 10;
    else if (flag & (P_GAME | INGANE) && !leet->crr_img)
        (leet->l_time = clock(), leet->crr_img = choose_number());
    elapsed_time = (float)(clock() - leet->l_time) / CLOCKS_PER_SEC;
    if (elapsed_time >= 0.1)
    {
        if (i == 7)
            return (leet->crr_img = 0, leet->flag = destination, \
                (void)(i = 0));
        mlx_clear_window(leet->mlx, leet->window);
        mlx_put_image_to_window(leet->mlx, leet->window, \
            leet->img[leet->crr_img++], 0, 0);
        (leet->l_time = clock(), i++);
    }
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





