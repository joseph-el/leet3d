/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:49:49 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/25 16:27:17 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARCER_H
# define PARCER_H

# include "leet3d.h"

# define N 1

# define ERROR 1
# define FATAL 4
# define INIT 16
# define CHECK 8

# define EXEC "test"

typedef enum s_setting
{
    NO = 1 << 0,
    SO = 1 << 1,
    WE = 1 << 2,
    EA = 1 << 3,
    C_F = 1 << 4,
    C_C = 1 << 5
}           t_setting;

typedef enum s_position
{
    SOUTH = 123,
    EAST = 105,
    WEST = 127,
    NORTH = 116,
}           t_position;

typedef struct s_parcer
{
    char        *texture[4];
    char        **map;
    int         *c_floor[3];
    int         *c_ceiling[3];
    t_position  position;
}               t_parcer;



# endif
