/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:23:59 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/13 14:23:30 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

int     get_random(int min, int max)
{
    int random_num;
    
    srand(time(NULL));
    while(1) 
    { 
        random_num = rand() % (max - min + 1) + min; 
        if(random_num % 2 == 0) 
            break;
    }
    return (random_num);
}

void    set_(t_minimap *leet, char ***map, int *ret, int flag)
{
    int i;

    i = 0;

    if (flag & SET_ENEMY)
    {
        while (i < 10)
        {
            (*map)[ret[i]][ret[i + 1]] = 'Z';
            if (ret[i] == leet->p_y && ret[i + 1] == leet->p_x)
                (*map)[ret[i]][ret[i + 1]] = '0';
            i += 2;
        }
        return ;
    }
    (*map)[ret[0]][ret[1]] = '0';
    (*map)[ret[2]][ret[3]] = '0';
    (*map)[ret[4]][ret[5]] = '0';
    (*map)[ret[6]][ret[7]] = '0';
    (*map)[ret[8]][ret[9]] = '0';
}

int     free_spaces(char **map)
{
    int i;
    int j;
    int free_sp;

    i = -1;
    free_sp = 0;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
            free_sp += (map[i][j] == '0');
    }
    return (free_sp);
}

bool    valid_enemy(t_parser *parser)
{
    int     i;
    int     j;
    bool    ret;
    int     free_sp;

    i = -1;
    free_sp = 0;
    while (parser->map[++i])
    {
        j = -1;
        while (parser->map[i][++j])
            free_sp += (parser->map[i][j]);
    }
    ret = (parser->height >= 10 && \
            parser->width >= 10 && free_sp >= 10);
    return (ret);
}