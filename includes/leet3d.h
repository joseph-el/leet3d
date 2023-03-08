/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:18:20 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/08 23:47:57 by yoel-idr         ###   ########.fr       */
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


# include "../libtools/libtools.h"
# include "parser.h"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"

# define CNTRL 1
# define PAUSE 2
# define P_CNTRL 4
# define P_GAME 8
# define G_HOME 16

typedef unsigned long long t_short;

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
    MOVE_RIGHT = 1 << 9,
    MOVE_UP = 1 << 10,
    MOVE_DOWN = 1 << 11,
    
    UVOLUME = 1 << 12,
    DVOLUME = 1 << 13,
    MVOLUME = 1 << 14,
    EVOLUME = 1 << 15,
    MSOUND = 1 << 16,
    ESOUND = 1 << 17,
    MSFX = 1 << 18,
    ESFX = 1 << 19,
    SOUND1 = 1 << 20,
    SOUND2 = 1 << 21,
    SOUND3 = 1 << 22,
    SOUND4 = 1 << 23,
    CONTROL_A = 1 << 24,
    CONTROL_B = 1 << 25,
    CONTROL_C = 1 << 26,
    
    BACK = 1 << 27,
    RESUME = 1 << 28,
    QUIT_G = 1 << 29,
    CNTRL_A = 1 << 31,
    CNTRL_B = 1 << 32,
    CNTRL_C = 1 << 33,
    
    CONTROLS = (CONTROL_A | CONTROL_B | CONTROL_C),
    SET_MAP = (MAP1 | MAP2 | MAP3 | MAP4),
    SOUNDS = (SOUND1 | SOUND2 | SOUND3 | SOUND4),
    SET_TEXTURE = (TEXT1 | TEXT2 | TEXT3 | TEXT4),
    SET_VOLUME = (UVOLUME | DVOLUME | MVOLUME | EVOLUME | \
                MSOUND | ESOUND | MSFX | ESFX)
}   t_select;


typedef enum s_flag
{
    HOME = 1 << 0,
    
    MAPS = 1 << 1,
    
    SETTING = 1 << 2,
    
    TEXTURE = 1 << 3,
    
    G_PAUSE = 1 << 4,

    P_CONTRL = 1 << 5,

    LOADING = 1 << 6,
    
    GAME = 1 << 7,
    
    G_EXIT = 1 << 8,
    
    HOME_PAGE = (SETTING | MAPS | GAME | TEXTURE)
}               t_flag;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *imgs[20];
    char    **map;
    void    (*array[7])();
    t_flag  flag;
}               t_data;




void    error_(char *error, int errno_s, int flag);
void    array_destroyer(char **array);


#endif