/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:31:02 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/14 22:43:28 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEET3D_H
# define LEET3D_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <mlx.h>
# include <stdbool.h>
# include <limits.h>
# include <float.h>

# include "../libtools/libtools.h"

# include "defines.h"
# include "parser.h"
# include "raycasting.h"

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
    CNTRL_A = 1ULL << 31,
    CNTRL_B = 1ULL << 32,
    CNTRL_C = 1ULL << 33,
    CONTROLS = (CONTROL_A | CONTROL_B | CONTROL_C),
    SET_MAP = (MAP1 | MAP2 | MAP3 | MAP4),
    SOUNDS = (SOUND1 | SOUND2 | SOUND3 | SOUND4),
    SET_TEXTURE = (TEXT1 | TEXT2 | TEXT3 | TEXT4),
    SET_VOLUME = (UVOLUME | DVOLUME | MVOLUME | EVOLUME | MSOUND | ESOUND | MSFX | ESFX)
}           t_select;

typedef enum s_flag
{
    HOME = 1ULL << 34,
    MAPS = 1ULL << 35,
    SETTING = 1ULL << 36,
    TEXTURE = 1ULL << 37,
    G_PAUSE = 1ULL << 38,
    P_CONTRL = 1ULL << 39,
    LOADING = 1ULL << 40,
    GAME = 1ULL << 41,
    G_EXIT = 1ULL << 42,
    HOME_PAGE = (SETTING | MAPS | GAME | TEXTURE)
}               t_flag;

typedef struct s_sound
{
    bool    cdoor;
    bool    odoor;
    bool    run;
    bool    shot;
    bool    sound;
    bool    sfx;
    bool    general;
    bool    up;
    bool    down;
    bool    sound1;
    bool    sound2;
    bool    sound3;
    bool    sound4;
    bool    damage;
    bool    click;
    bool    is_run;
    bool    enemy_shot;
}               t_sound;

typedef struct s_control
{
    bool    control_a;
    bool    control_b;
    bool    control_c;
    bool    loading;
}               t_control;

typedef struct s_minimap
{
    t_img   img;
    t_img   build;
    int     img_width;
    int     img_height;
    int     p_x;
    int     p_y;
}           t_minimap;

typedef struct s_enemy
{
    int *indexs;
    int *ret;
    clock_t last_time;
}              t_enemy;

typedef struct  s_leet
{
    void            *mlx;
    void            *window;
    void            *img[39];
    int             crr_img;
    clock_t         l_time;
    t_flag          flag;
    t_sound         sound;
    t_parser        *parser;
    t_enemy         enemy;
    t_control       cntrl;
    t_minimap       minimap;
    t_raycasting    ray;
}               t_leet;


/**
 * @brief Utils Functions
 * 
 * @param t_leet *
 * @return void* 
 */
void    *sound_(void *ptr);
void    enemy(t_leet *leet);
int     free_spaces(char **map);
void    get_assets(t_leet *leet);
int     get_random(int min, int max);
bool    valid_enemy(t_parser *parser);
void    default_setting(t_leet *leet);
void	array_destroyer(char ***array);
void    set_indexs(char **map, int **indexs);
void	error_(char *error, int errno_s, int flag);
void	initialize(t_leet *leet, t_parser *parser);
void	map_initialize(t_leet *leet, t_parser *parser);
void    get_indexs(int *indexs, int *ret, int max_range);
void	textures_initialize(t_leet *leet, t_parser *parser);
void    set_(t_minimap *leet, char ***map, int *ret, int flag);

/**
 * @brief Raycasting Functions
 * 
 * @param t_leet *
 */

int         _rgb_color(t_rgb rgb);
int         wall_height(t_leet *leet, int i);
int         wall_top_pixel(t_leet *leet, int i);
int         get_colors(t_img *src, int x, int y);
int         _pixel_color(t_img *img, int x, int y);
int         wall_bottom_pixel(t_leet *leet, int i);
int         _out_range(char **map, double x, double y);
int         _offset(t_leet *leet, int i, int top, char v);
int         _direction(double angle, enum e_direction look);
int         map_has_wall_at(char **map, double x, double y);
double	    _angle(double angle);
double	    _distance(t_vector start, t_vector end);
t_ray       cast_ray(t_leet *leet, double ray_angle);
t_vector	get_vertical_steps(double rayAngle);
t_vector	get_horizontal_steps(double rayAngle);
t_vector	vertical_ray_cast(t_leet *leet, double rayAngle);
t_vector	horizontal_ray_cast(t_leet *leet, double rayAngle);
t_vector	get_vertical_intercept(t_leet *leet, double rayAngle);
t_vector	get_horizontal_intercept(t_leet *leet, double rayAngle);
void        render(t_leet *leet);
void        minimap_(t_leet *leet);
void        raycasting(t_leet *leet);
void        draw_squares(t_leet *leet);
void        animated_sprite(t_leet *leet);
void        _rotate(t_leet *leet, int sign);
void        draw_minimap(t_minimap *minimap);
void        draw_player(t_img *src, int p_x, int p_y);
void        _move(t_leet *leet, double angle, int sign);
void        draw_grid(t_img *src, int map_y, int map_x);
void        render_ceil(t_leet *leet, int top_pixel, int i);
void        render_floor(t_leet *leet, int bottom_pixel, int i);
void        render_wall(t_leet *leet, int top, int bottom, int i);
void        ft_mlx_pixel_put(t_img *data, int x, int y, int color);
void        put_pixel(t_img *src, int width, int height, int color);
void        draw_square(t_img *img, int s_x, int s_y, unsigned int color);
void        vertical_render(t_leet *leet, int i, int top, t_vector offset);
void        horizontal_render(t_leet *leet, int i, int top, t_vector offset);
void        set_vertical_hit(t_leet *leet, t_ray *ray, t_vector hit, double distance);
void        set_horizontal_hit(t_leet *leet, t_ray *ray, t_vector hit, double distance);
void        setup_ray(t_leet *leet, t_ray *ray, t_vector horizontal_hit, t_vector vertical_hit);

/**
 * @brief Events Functions
 * 
 * @param t_leet *
 */
char    **switch_map(t_short ret);
char    **switch_texture(t_short ret);
void    ft_exit(void);
void    game(t_leet *leet);
void    g_render(t_leet *leet);
void	g_moving(t_leet *leet, int flag);
void    key_events(int key, t_leet *leet);
void    g_pause(t_leet *leet, t_short ret);
void    p_control(t_leet *leet, t_short ret);
void    g_graphics(t_leet *leet, t_short ret);
void    set_setting(t_leet *leet, t_short ret);
void    game_events(t_leet *leet, t_flag flag);
void    mouse_events(int x, int y, t_leet *leet);
void    g_loading(t_leet *leet, int flag, int destination);
void    mouse_move(int button, int x, int y, t_leet *leet);
void    mouse_button(int button, int x, int y, t_leet *leet);
t_short get_button(t_flag flag, int x, int y);

#endif