/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___leet3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:50:42 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/06 12:18:04 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"
# include <time.h>
# include <mlx.h>

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *imgs[10];
    char **map;
    t_flag  flag;
}               t_data;

void    map_print(char **arr)
{
    int i; i = 0;
    while (arr[i])
        puts(arr[i++]);
}

# define WALL 2
# define ENEMY 4
# define PLAYER 32
# define PINK 0x0FF04DE
# define RED_ 0x0FFFFFF
# define YELLOW_ 0x000FF3C
# define SP 16
# define LL 0x0500000


typedef union set_data
{
    short key;
    uint16_t    *left;
    uint16_t    *right;

}               t_set;

void    ft_glVertex2i(t_data *data, int *x, int y, int ret)
{
    unsigned int color;
    int          i;
    int          j;

    color = (ret == WALL) * PINK + (ret == ENEMY) * RED_ + (ret == PLAYER) * YELLOW_ + (ret == SP) * LL;
    
    i = (ret == WALL) * 10 + (ret == ENEMY) * 10 + (ret == PLAYER) * 10 + (ret == SP) * 10;
    // *x += (ret == PLAYER) * 10;
    while (i)
    {
        mlx_pixel_put(data->mlx, data->win, *x + j, y + i, 0x0FFFFFF);
        j = (ret == WALL) * 30 + (ret == ENEMY) * 8 + (ret == PLAYER) * 5 + (ret == SP) * 30;
        while (j)
        {
            mlx_pixel_put(data->mlx, data->win, *x + j, y + i, color);
            j --;
        }
        i --;
    }
}


int pos_x = 4;
int pos_y = 4;

void    minimap(t_data *data)
{
    int x;
    int y;
    int i;
    int j;
    int cx;
    int cy;
    int ret;

    i = -1;
    y = 66;
    puts("position of x :");
    scanf("%d", &pos_x);
    puts("position of y :");
    scanf("%d", &pos_y);
        void *minimaps, *usa;
    int test, seg;
    mlx_clear_window(data->mlx, data->win);
    usa = mlx_xpm_file_to_image(data->mlx, "./assets/start1.xpm", &test, &seg);
       minimaps = mlx_xpm_file_to_image(data->mlx, "./assets/circle-map.xpm", &test, &seg);

    mlx_put_image_to_window(data->mlx, data->win, usa, 0, 0);
    mlx_put_image_to_window(data->mlx,data->win, minimaps, 0, 0);
    while (++i < 5)
    {
        j = -1;
        x = 75;
        while (++j < 5)
        {
            cx = i - 2 + pos_x;
            cy = j - 2 + pos_y;
            if (cx >= 0 && cx < 8 && cy >= 0 && cy < 10)
            {
                ret = (cx == pos_x && cy == pos_y) * PLAYER + (data->map[cx][cy] == '1') * WALL + (data->map[cx][cy] == 'Z') * ENEMY + (data->map[cx][cy] == '0') * SP;
                if (cx == pos_x && cy == pos_y)
                    ret = PLAYER;
                ft_glVertex2i(data, &x, y, ret);
            }
            x += 30;
        }
        y += 30;
    }
}




int main(int argc, char **argv)
{
    t_data  data;
    char    *line;
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
    void *minimaps, *usa;
    int test, seg;
    usa = mlx_xpm_file_to_image(data.mlx, "./assets/start1.xpm", &test, &seg);
    minimaps = mlx_xpm_file_to_image(data.mlx, "./assets/circle-map.xpm", &test, &seg);
    mlx_put_image_to_window(data.mlx, data.win, usa, 0, 0);

    mlx_put_image_to_window(data.mlx, data.win, minimaps, 0, 0);

    // minimap(&data);
    mlx_loop_hook(data.mlx, (void *)minimap, &data);
    mlx_loop(data.mlx);
    // mlx_loop_hook(data.mlx, (void *)starting, &data);
    // get_path(&data);
    exit(EXIT_SUCCESS);
}




t_short get_mode(int x, int y, t_short flag)
{
    t_short ret;
    
    ret = (x > 1123 && x < 1200 && y >= 0 && y <= 360) * GAME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAPS + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * ABOUT + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * G_EXIT + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SETTING + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXTURE +\
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * BACK + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MSOUND + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * USOUND + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND1 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND2 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND3 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * SOUND4 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * DVOLUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * UVOLUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MVOLUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * UEFFCTS + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MEFFCTS + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_A + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_B + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT1 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT2 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT3 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * TEXT4 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP1 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP2 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP3 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MAP4 + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * G_PAUSE + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MOVE_RIGHT + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * MOVE_LEFT + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * RESUME + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * QUIT_G + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_A + \
          (x > 1123 && x < 1200 && y >= 0 && y <= 360) * CONTROL_B;
    return (ret);
}