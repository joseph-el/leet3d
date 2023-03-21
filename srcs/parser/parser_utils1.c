/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:21:48 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/20 07:19:37 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

t_position	get_position(t_parser *container)
{
	t_position	position;
	int			found;
	int			j;
	int			i;

	found = 1;
	i = -1;
	while (container->map[++i])
	{
		j = -1;
		while (container->map[i][++j])
		{
			if (ft_strchr("NWSE", container->map[i][j]))
			{
				found += 1;
				position = container->map[i][j];
				container->map[i][j] = '0';
				*container->p_indices = i;
				container->p_indices[1] = j;
			}
		}
	}
	if (found != 2)
		error_(ERR_POSITION, 0, ERROR);
	return (position);
}

void	set_texture(t_parser **container, char *line, t_setting ret)
{
	int	fd_texture;
	int	i;

	(void)fd_texture;
	i = (int)log2(ret);
	if ((*container)->texture[i])
		return (error_(ERR_MISSING, 0, ERROR));
	while (*line)
	{
		while (*line != '\n' && ft_isspace(*line))
			line++;
		if (!*line || *line == '\n')
			return (error_(ERR_PATH, 0, ERROR));
		(*container)->texture[i] = ft_strndup(line, ft_strlen(line) - 1);
		fd_texture = open((*container)->texture[i], O_RDONLY);
		if (fd_texture == -1)
			return (error_((*container)->texture[i], ENOENT, ERROR | FATAL));
		return ;
	}
}

void	set_colors(t_parser **container, char *line, t_setting flag)
{
	char	**colors;
	char	*tmp;
	int		index;
	int		i;

	while (*line && ft_isspace(*line))
		line++;
	i = 0;
	while (line[i])
		if (!ft_strchr("1234567890 ,\n", line[i++]))
			return (error_(ERR_COLORS, 0, ERROR));
	error_color(line, &index);
	colors = ft_split(line, ',');
	while (colors[index])
		index++;
	if (index > 3 || index < 3)
		return (error_(ERR_COLORS, 0, ERROR));
	while (index)
	{
		tmp = ft_strtrim(colors[index], " \n");
		free(colors[index]);
		colors[index] = tmp;
		index--;
	}
	analysis_rgb(container, colors, flag);
}

void	set_data(t_parser **container, int fd_map)
{
	t_setting	ret;
	bool		sp;
	int			i;
	char		*line;

	line = get_next_line(fd_map);
	sp = true;
	while (line)
	{
		i = 0;
		while (line[i] != NL && ft_isspace(line[i]) && sp)
			i++;
		ret = key(line + i);
		if ((!ret && line[i] != NL) || (!i && *line == '\n' && !sp))
			error_(ERR_KEY, 0, ERROR);
		if (ret & (NO | SO | WE | EA) && sp)
			set_texture(container, line + (i + 3), ret);
		else if (ret & (C_F | C_C) && sp)
			set_colors(container, line + (i + 2), ret);
		else if (ret & M_KEY)
			(**container).map = realloc_arrays(&(**container).map, \
			ft_strdup(line), &sp);
		free(line);
		line = get_next_line(fd_map);
	}
}

void	analysis_map(t_parser *data)
{
	int	i;

	i = 0;
	data->position = get_position(data);
	while (data->map[i])
	{
		if ((!i && data->map[i]) || (!data->map[i + 1] && data->map[i]))
			checkup_line(data, data->map[i], 0, FIRST | LAST);
		checkup_line(data, data->map[i], i, SPACE);
		i++;
	}
	data->width = ft_strlen(*data->map);
	data->height = i;
	last_line(data->map, data->height - 2);
}
