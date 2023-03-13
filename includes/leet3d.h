/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:58:06 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/13 23:42:43 by yoel-idr         ###   ########.fr       */
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

# include "parser.h"
# include "raycasting.h"

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
# define STARTING 1
# define INGANE 2
# define ERROR 1
# define FATAL 2
# define FREE_ZONE 4
# define SET_ENEMY 2
# define X_MAP1 15
# define Y_MAP1 7
# define X_MAP2 70
# define Y_MAP2 4
# define X_MAP3 40
# define Y_MAP3 17
# define X_MAP4 17
# define Y_MAP4 11
# define C_MAP1 "./packages/const_map/const_map1.cub"
# define C_MAP2 "./packages/const_map/const_map2.cub"
# define C_MAP3 "./packages/const_map/const_map3.cub"
# define C_MAP4 "./packages/const_map/const_map4.cub"

#define TEXTURES_PACKAGE    "./package/const_testures/t1.xpm " \
                            "./package/const_testures/t2.xpm " \
                            "./package/const_testures/t3.xpm " \
                            "./package/const_testures/t4.xpm " \
                            "./package/const_testures/t5.xpm " \
                            "./package/const_testures/t6.xpm " \
                            "./package/const_testures/t7.xpm " \
                            "./package/const_testures/t8.xpm " \
                            "./package/const_testures/t9.xpm " \
                            "./package/const_testures/t10.xpm " \
                            "./package/const_testures/t11.xpm " \
                            "./package/const_testures/t12.xpm " \
                            "./package/const_testures/t13.xpm " \
                            "./package/const_testures/t14.xpm " \
                            "./package/const_testures/t15.xpm " \
                            "./package/const_testures/t16.xpm " \

# define UP "osascript -e \"set volume output volume (output volume of (get volume settings) + 10)\""
# define DOWN "osascript -e \"set volume output volume (output volume of (get volume settings) - 10)\""
# define MUTE "osascript -e \"set volume with output muted\""
# define UNMUTE "osascript -e \"set volume without output muted\""

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
    void            *img[17];
    t_flag          flag;
    t_sound         sound;
    t_parser        *parser;
    t_control       cntrl;
    t_raycasting    ray;
    t_minimap       minimap;
    t_enemy         enemy;
}               t_leet;


void    *sound(void *ptr);
void    get_assets(t_leet *leet);
void    default_setting(t_leet *leet);

void    enemy(t_leet *leet);
int     free_spaces(char **map);
int     get_random(int min, int max);
bool    valid_enemy(t_parser *parser);
void    set_indexs(char **map, int **indexs);
void    get_indexs(int *indexs, int *ret, int max_range);
void    set_(t_minimap *leet, char ***map, int *ret, int flag);


void        minimap_(t_leet *leet);
void        draw_squares(t_leet *leet);
void        draw_minimap(t_minimap *minimap);
int	        get_colors(t_img *src, int x, int y);
void        draw_player(t_img *src, int p_x, int p_y);
void        draw_grid(t_img *src, int map_y, int map_x);
void	    put_pixel(t_img *src, int width, int height, int color);
void        draw_square(t_img *img, int s_x, int s_y, unsigned int color);

t_short     get_button(t_flag flag, int x, int y);
void        g_render(t_leet *leet);
int         g_loading(t_leet *leet, int flag);
char        **switch_map(t_short ret);
char        **switch_texture(t_short ret);
void	    g_moving(t_leet *leet, int flag);
void        key_events(int key, t_leet *leet);
void        g_pause(t_leet *leet, t_short ret);
void        p_control(t_leet *leet, t_short ret);
void        g_graphics(t_leet *leet, t_short ret);
void        game_events(t_leet *leet, t_flag flag);
void        set_setting(t_leet *leet, t_short ret);
void        mouse_events(int x, int y, t_leet *leet);
void        mouse_move(int button, int x, int y, t_leet *leet);
void        mouse_button(int button, int x, int y, t_leet *leet);

void        array_destroyer(char ***array);
void	    error_(char *error, int errno_s, int flag);

void	    game(t_leet *leet);
double		_angle(double angle);
double		_distance(t_vector start, t_vector end);
int			_rgb_color(t_rgb rgb);
int			_pixel_color(t_img *img, int x, int y);
int			_direction(double angle, enum e_direction look);
int			map_has_wall_at(char **map, double x, double y);
t_vector	get_horizontal_steps(double rayAngle);
void		map_initialize(t_leet *leet, t_parser *parser);
void		initialize(t_leet *leet, t_parser *parser);
void		_rotate(t_leet *leet, int sign);
void		_move(t_leet *leet, double angle, int sign);
t_ray		cast_ray(t_leet *leet, double ray_angle);
void		raycasting(t_leet *leet);
void		render_ceil(t_leet *leet, int top_pixel, int i);
void		render_floor(t_leet *leet, int bottom_pixel, int i);
void		render(t_leet *leet);
t_vector	get_vertical_steps(double rayAngle);
int			wall_top_pixel(t_leet *leet, int i);
int			wall_bottom_pixel(t_leet *leet, int i);
int			_offset(t_leet *leet, int i, int top, char v);
t_vector	vertical_raycast(t_leet *leet, double rayAngle);
t_vector	horizontal_raycast(t_leet *leet, double rayAngle);
void		textures_initialize(t_leet *leet, t_parser *parser);
void		render_wall(t_leet *leet, int top, int bottom, int i);
t_vector	get_vertical_intercept(t_leet *leet, double rayAngle);
void		ft_mlx_pixel_put(t_img *data, int x, int y, int color);
double		vertical_distance(t_leet *leet, t_vector vertical_hit);
t_vector	get_horizontal_intercept(t_leet *leet, double rayAngle);
double		horizontal_distance(t_leet *leet, t_vector horizontal_hit);
void		vertical_render(t_leet *leet, int i, int top, t_vector offset);
void		horizontal_render(t_leet *leet, int i, int top, t_vector offset);
void		set_vert_check(t_vector *to_check, t_vector next_touch, double rayAngle);
void		set_horz_check(t_vector *to_check, t_vector next_touch, double rayAngle);
void		setup_ray(t_leet *leet, t_ray *ray, t_vector horizontal_hit, t_vector vertical_hit);

# endif
