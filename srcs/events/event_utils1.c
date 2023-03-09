/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:10:59 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/09 21:11:25 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/leet3d.h"

char    **switch_map(t_leet **leet, t_short ret)
{
    char    **map;
    char    *line;
    int     fd_map;
    int     i;
    
    i = 0;
    fd_map = open("NULL", O_RDONLY);
    map = malloc(sizeof(char *) * 50);
    if (fd_map == -1 || !map)
        error_(NULL, ENOMEM, FATAL);
    line = get_next_line(line);
    while (line)
    {
        map[i++] = ft_strdup(line);
        free(line);
        line = get_next_line(line);
    }
    return (map);
}

char    **switch_texture(t_short ret)
{
    char    **texture;
    char    *packet;
    int     i;

    i = (ret == TEXT1) * 0 + (ret == TEXT2) * 1 + (ret == TEXT3) * 2 + (ret == TEXT4) * 3;
    texture = malloc(sizeof(char *) * 5);
    packet = "./package/const_textures/1.xpm ./package/const_textures/1.xpm \
                ./package/const_textures/1.xpm ./package/const_textures/1.xpm";
    
    return (texture);
}