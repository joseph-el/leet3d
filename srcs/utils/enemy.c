/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:15:12 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/13 14:35:36 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void    set_indexs(char **map, int **indexs)
{
    int i;
    int j;
    int index;

    i = -1;
    index = 0;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == '0')
            {
                (*indexs)[index] = i;
                (*indexs)[index + 1] = j;
                index += 2;
            }
        }
    }
}

void    get_indexs(int *indexs, int *ret, int max_range)
{
    static int num;
    int i;
    
    i = 0;
    num = 0;
    while (i < 20)
    {
        num += get_random(0, max_range - 1);
        if (num >= max_range - 1)
            num = get_random(0, max_range -1);
        (ret)[i] = indexs[num];
        (ret)[i + 1] = indexs[num + 1];
        i += 2;
    }
}

void    enemy(t_leet *leet)
{
    int         max_size;

    if (!valid_enemy(leet->parser))
        return ;
    if ((clock() - leet->enemy.last_time) / CLOCKS_PER_SEC <= 2)
        return ;
    if (leet->enemy.ret)
    {
        set_(0, &leet->parser->map, leet->enemy.ret, FREE_ZONE);
        free(leet->enemy.ret);
    }
    max_size = free_spaces(leet->parser->map) * 2;
    leet->enemy.indexs = malloc(sizeof(int) * max_size);
    leet->enemy.ret = malloc(sizeof(int) * 20);
    if (!leet->enemy.indexs || !leet->enemy.ret)
        error_(NULL, ENOMEM, FATAL);
    set_indexs(leet->parser->map, &leet->enemy.indexs);
    get_indexs(leet->enemy.indexs, leet->enemy.ret, max_size);
    set_(&leet->minimap, &leet->parser->map, leet->enemy.ret, SET_ENEMY);
    free(leet->enemy.indexs);
    leet->enemy.last_time = clock();
}
