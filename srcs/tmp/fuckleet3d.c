/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuckleet3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:27:11 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/05 20:13:06 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"
# include <time.h>
# include <mlx.h>

# define SELECT_TEXTURE 1
# define START_GAME 2
# define TEXTURE1 4
# define TEXTURE2 16
# define TEXTURE3 32
# define TEXTURE4 64

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *imgs[10];
    char **map;
    // t_flag  flag;
}               t_data;


//  * @brief The Starting of Leet3D
//  *  
//  * @param data
//  *  
    typedef enum s_flag
    {
        MAPS     = 1 << 7;
        GAME     = 1 << 3,
        HOME     = 1 << 4,
        G_EXIT    = 1 << 5,
        ABOUT    = 1 << 2,
        START    = 1 << 6,
        LOADING  = 1 << 1,
        TEXTURE  = 1 << 0
    }           t_flag;

    
void    get_path(t_data *data)
{
    int seg;
    int test;
    
    data->imgs[0] = mlx_xpm_file_to_image(data->mlx, "./assets/start1.xpm", &test, &seg);
    data->imgs[1] = mlx_xpm_file_to_image(data->mlx, "./assets/start2.xpm", &test, &seg);
    data->imgs[2] = mlx_xpm_file_to_image(data->mlx, "./assets/start3.xpm", &test, &seg);
    data->imgs[3] = mlx_xpm_file_to_image(data->mlx, "./assets/start4.xpm", &test, &seg);
    data->imgs[4] = mlx_xpm_file_to_image(data->mlx, "./assets/start5.xpm", &test, &seg);
    data->imgs[5] = mlx_xpm_file_to_image(data->mlx, "./assets/start6.xpm", &test, &seg);
    data->imgs[6] = mlx_xpm_file_to_image(data->mlx, "./assets/start7.xpm", &test, &seg);
    data->imgs[7] = mlx_xpm_file_to_image(data->mlx, "./assets/game_start.xpm", &test, &seg);
    data->imgs[8] = mlx_xpm_file_to_image(data->mlx, "./assets/pause.xpm", &test, &seg);
}

int     loading(t_data *data)
{
    static clock_t  l_time;
    static int      crr_img;
    clock_t         r_time;

    r_time = clock();
    l_time = 0;
    if (r_time - l_time / CLOCKS_PER_SEC > 4)
    {
        if (crr_img == 8)
            return (crr_img = 0, data->flag = HOME);
        mlx_clear_window(data->mlx, data->win);
        mlx_put_image_to_window(data->mlx, data->win, data->imgs[crr_img++], 0, 0);
    }
    sleep(1);
    l_time = clock();
    return (EXIT_SUCCESS);
}

void    mouse(int button, int x, int y, t_data *data)
{
    short   ret;

    if (button != 1)
        return ;
    ret = (x > 1123 && y < 360) * START_GAME + (x > 1123 && y > 360) * SELECT_TEXTURE + \
                                                    (x >= 0 && x <= 20 && y >= 0 && y <= 20) * HOME;
    if (ret & START_GAME)
        data->flag = GAME;
    else if (ret & SELECT_TEXTURE)
        data->flag = TEXTURE;
    else if (ret & HOME)
        data->flag = LOADING;
}

void    home(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[7], 0, 0);
    mlx_mouse_hook(data->win, (void *)mouse, data);
}

void    game(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[8], 0, 0);
    mlx_mouse_hook(data->win, (void *)mouse, data);
}

void    pause_game(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[1], 0, 0);
    mlx_mouse_hook(data->win, (void *)mouse, data);
}

void    texture(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[2], 0, 0);
    mlx_mouse_hook(data->win, (void *)mouse, data);
}

void    about(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[2], 0, 0);
    mlx_mouse_hook(data->win, (void *)mouse, data);
}

void quit_game(t_data *data)
{
    exit(25);
}

void    starting(t_data *data)
{
    arr[data->flag];
    if (data->flag & LOADING)
        ;
    else if (data->flag & HOME)
        home(data);
    else if (data->flag & GAME)
        game(data);
    else if (data->flag & START)
        pause_game(data);
    else if (data->flag & ABOUT)
        about(data);
    else if (data->flag & EXIT)
        exit(177);
    else if (data->flag & TEXTURE)
        texture(data);
}



void    map_print(char **arr)
{
    int i; i = 0;
    while (arr[i])
        puts(arr[i++]);
}

# define MINI_MAP_HEIGHT 300
# define MINI_MAP_WIDTH 444

# define MAP_WIDTH  22
# define MAP_HEIGHT 9

# define ENEMY 4
# define PLAYER 1
# define WALL 2



void    circle(t_data *data, int x, int y)
{
    int i;
    int j;
    int distance;
    int radius;
    int center_x;
    int center_y;
    
    fprintf(stderr, "IAM HERE\n");
    i = -1;
    radius = 10;
    center_y = 20;
    center_x = 20;
    while (++i < 20)
    {
        j = -1;
        while (++j < 20)
        {
            distance = sqrt(pow(x - center_x, 2) + pow(y - center_y, 2));
            if (distance <= radius)
            {
                fprintf(stderr, "IMAH RERGn");
                mlx_pixel_put(data->mlx, data->win, y + j, i + x, 0x0FFFFFF);
            }
        }
    }
}


void    triangle(t_data *data, int x, int y)
{
    int i;
    int j;

    i = -1;
    while (++i < 20)
    {
        j = -1;
        while (++j < 20)
        {
            if ((i > j) && (i > 20 - x))
            mlx_pixel_put(data->mlx, data->win, y + j, i + x, 0x0FFFF00);
        }
    }
}

void    ft_glVertex2i(t_data *data, int x, int y, int flag)
{
    int             i;
    int             j;

    if (flag & PLAYER)
    {
        void *tyy;
        
        int u , r;
        tyy = mlx_xpm_file_to_image(data->mlx, "./assets/mm.xpm", &r, &u);
        mlx_put_image_to_window(data->mlx, data->win, tyy, y, x);
        return ;
    }
    if (flag & ENEMY)
        return (circle(data, x, y));
    i = -1;
    while (++i < 15)
    {
        j = -1;
        while (++j < 15)
            mlx_pixel_put(data->mlx, data->win, y + j, i + x, 0x0FF04DE);
    }
}


int pos_x = 2;
int pos_y = 2;

void    minimap(t_data *data)
{
    int i;
    int j;
    int x;
    int y;
    int cx;
    int cy;
    int ret;
    
    i = -1;
    x = 66;
    while (++i < 5)
    {
        j = -1;
        y = 75;
        while (++j < 5)
        {
            cx = i - 3 + pos_x;
            cy = j - 3 + pos_y;
            if (cx >= 0 && cx < 10 && cy >= 0 && cy < 10)
            {
                ret = (data->map[cx][cy] == '1') * WALL + (data->map[cx][cy] == 'Z') * \
                         ENEMY + (cx == pos_x && cy == pos_y) * PLAYER;
                ft_glVertex2i(data, x, y, ret);
            }
            else
                continue;
            y += 30;
        }
        x += 30;
    }
}













int main(int argc, char **argv)
{
    t_data  data;
    char *line;
    int fd = open("./srcs/map.dd", O_RDONLY);
    char *tmp;
    line = get_next_line(fd);
    line = ft_strndup(line, ft_strlen(line) - 1);
    tmp = ft_strjoin(line , "");
    while (line)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        line = ft_strndup(line, ft_strlen(line) - 1);
        tmp = ft_strjoin(tmp, line);
    }
    data.map = ft_split(tmp, ';');
    map_print(data.map);

    (void)argv;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1280, 720, "leet3d");
    // data.flag = LOADING;
    void *minimaps, *usa;
    int test, seg;
    

    usa = mlx_xpm_file_to_image(data.mlx, "./assets/pause.xpm", &test, &seg);
    minimaps = mlx_xpm_file_to_image(data.mlx, "./assets/help.xpm", &test, &seg);
    mlx_put_image_to_window(data.mlx, data.win, usa, 0, 0);

    mlx_put_image_to_window(data.mlx, data.win, minimaps, 0, 0);

    minimap(&data);
    // mlx_loop_hook(data.mlx, (void *)minimap, &data);
    mlx_loop(data.mlx);
    // mlx_loop_hook(data.mlx, (void *)starting, &data);
    // get_path(&data);
    exit(EXIT_SUCCESS);
}






























