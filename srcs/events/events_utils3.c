/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:46:37 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/21 21:32:16 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	g_loading(t_leet *leet, int flag)
{
	float		elapsed_time;
	t_flag		destination;
	static int	i = 0;

	destination = (flag == G_HOME) * HOME + \
		(flag == P_GAME) * HOME + \
		(flag == INGANE) * GAME;
	if (flag & G_HOME && !leet->crr_img)
		leet->crr_img = 10;
	else if (flag & (P_GAME | INGANE) && !leet->crr_img)
	{
		leet->l_time = clock();
		leet->crr_img = choose_number();
	}
	elapsed_time = (float)(clock() - leet->l_time) / CLOCKS_PER_SEC;
	if (elapsed_time >= 0.2)
	{
		if (i == 7)
			return (leet->crr_img = 0, leet->flag = destination, (void)(i = 0));
		mlx_clear_window(leet->mlx, leet->window);
		mlx_put_image_to_window(leet->mlx, leet->window, \
				leet->img[leet->crr_img++], 0, 0);
		leet->l_time = clock();
		i++;
	}
}

char	**switch_map(t_leet *leet, t_short ret)
{
	char	**map;
	char	*line;
	int		fd_map;
	int		i;

	fd_map = open_maps(ret);
	map = malloc(sizeof(char *) * 39);
	if (fd_map == -1 || !map)
		error_(NULL, ENOMEM, FATAL);
	line = get_next_line(fd_map);
	i = 0;
	while (line)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd_map);
	}
	map[i] = NULL;
	leet->parser->height = 38;
	leet->parser->width = get_height(map) - 1;
	return (close(fd_map), map);
}

char	**switch_texture(t_leet *leet, t_short ret)
{
	char	**texture;
	char	**package;
	int		i;
	int		j;

	package = ft_split(TEXTURES_PACKAGE, '\t');
	texture = malloc(sizeof(char *) * 5);
	texture[4] = NULL;
	if (!package || !texture)
		error_(NULL, ENOMEM, FATAL);
	i = (ret == TEXT1) * 0 + (ret == TEXT2) * 4 + \
		(ret == TEXT3) * 8 + (ret == TEXT4) * 12;
	j = 0;
	leet->parser->n_texture = ret;
	while (package[i] && j < 4)
	{
		texture[j] = ft_strdup(package[i]);
		(i++, j++);
	}
	array_destroyer(&package);
	return (texture);
}
