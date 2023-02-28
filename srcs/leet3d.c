/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:45:04 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/28 19:06:42 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/leet3d.h"

void    print_container(t_parser *container)
{
    int i = 0, u = 0, t = 0, e = 0;
    
    puts(RED"\nPrinting Texture"WHITE);
    while (i < 4)
    {
        printf("texture [%d] ==> [%s]\n", i, container->texture[i]);
        i ++;
    }
    
    puts(RED"\nPrinting c_ceiling"WHITE);
    while (u < 3)
    {
        printf("Colors c_ceiling [%d] ==> [%d]\n", u, container->c_ceiling[u]);
        u ++;
    }
    
    puts(RED"\nPrinting c_floor"WHITE);
    while (t < 3)
    {
        printf("Colors c_floor [%d] ==> [%d]\n", t, container->c_floor[t]);
        t ++;
    }
    puts(RED"\nPrinting map"WHITE);
    while (container->map && container->map[e])
        puts(container->map[e++]);
    puts(YELLOW"END PRINT"WHITE);
}


int main(int argc, char **argv)
{
    t_parser    *container;

    if (argc != 2)
        error_(ERR_ARGS, 0, ERROR);
    argv ++;
    (void)container;
    container = parser(*argv);
    print_container(container);
    exit(EXIT_SUCCESS);
}