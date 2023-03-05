/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:18:20 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/05 23:17:18 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEET3D_H
# define LEET3D_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <mlx.h>

# include "parser.h"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"

typedef enum s_select
{
    MAP1 = 1 << 0,
    MAP2 = 1 << 1,
    MAP3 = 1 << 2,
    MAP4 = 1 << 3,
    TEXT1 = 1 << 4,
    TEXT2 = 1 << 5,
    TEXT3 = 1 << 6,
    TEXT4 = 1 << 7,
    MOVE_LEFT = 1 << 8,
    QUIT_G = 1 << 13,
    MOVE_RIGHT = 1 << 12,
    RESUME = 1 << 9,
    EXIT_G = 1 << 10,
    BACK = 1 << 11,
    DVOLUME = 1 << 16,
    UVOLUME = 1 << 17,
    MVOLUME = 1 << 18,
    CONTROL_A = 1 << 14,
    CONTROL_B = 1 << 19,
    CONTROL_C = 1 << 20,
    SOUND1 = 1 << 21,
    SOUND2 = 1 << 22,
    SOUND3 = 1 << 15,
    SOUND4 = 1 << 23,
    SOUND5 = 1 << 24,
    
    SOUNDS = (SOUND1 | SOUND2 | SOUND3 | SOUND4 | SOUND5),
    CONTROLS = (CONTROL_A | CONTROL_B | CONTROL_C),
    SET_VOLUME = (DVOLUME | UVOLUME | MVOLUME),
    SET_TEXTURE = (TEXT1 | TEXT2 | TEXT3 | TEXT4),
    SET_MAP = (MAP1 | MAP2 | MAP3 | MAP4)
}              t_select;

typedef enum s_flag
{
    MAPS = 1 << 0,
    GAME = 1 << 1,
    HOME = 1 << 2,
    ABOUT = 1 << 3,
    START = 1 << 4,
    G_EXIT = 1 << 5,
    LOADING = 1 << 6,
    TEXTURE = 1 << 7,
    SETTING = 1 << 8,
    HOME_PAGE = (SETTING | MAPS | GAME | ABOUT | TEXTURE)
}           t_flag;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *imgs[10];
    char    **map;
    t_flag  flag;
}               t_data;




void    error_(char *error, int errno_s, int flag);
void    array_destroyer(char **array);


#endif