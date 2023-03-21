/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:22:57 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/20 07:20:43 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

char	**realloc_arrays(char ***arrays, char *line, bool *space)
{
	char	**ret;
	char	*new;
	int		i;

	i = -1;
	*space = false;
	new = line;
	if (line[ft_strlen(line) - 1] == NL)
	{
		new = ft_strndup(line, ft_strlen(line) - 1);
		free(line);
	}
	if (!*arrays)
	{
		ret = malloc(sizeof(char *) * 2);
		return (ret[0] = new, ret[1] = NULL, ret);
	}
	while ((*arrays)[++i])
		;
	ret = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while ((*arrays)[++i])
		ret[i] = ft_strdup((*arrays)[i]);
	ret[i++] = new;
	return (array_destroyer(arrays), ret[i] = NULL, ret);
}

void	container_tools(t_parser **container, int flag)
{
	int	ret;
	int	i;

	i = 0;
	if (flag & INIT)
	{
		(*container)->map = NULL;
		(*container)->texture = malloc(sizeof(char *) * 5);
		while (i < 5)
			(*container)->texture[i++] = NULL;
		init_tab(container);
	}
	ret = ((((*container)->c_ceiling[0] != -1) && \
			((*container)->c_ceiling[1] != -1) && \
			((*container)->c_ceiling[2] != -1) && \
			((*container)->c_floor[0] != -1) && \
			((*container)->c_floor[1] != -1) && \
			((*container)->c_floor[2] != -1) && \
			((*container)->texture[0]) && \
			((*container)->texture[1]) && \
			((*container)->texture[2]) && \
			((*container)->texture[3])) && ((*container)->map));
	if ((flag & EXIT) && !ret)
		error_(ERR_MISSING, 0, ERROR);
}

void	analysis_rgb(t_parser **container, char **colors, t_setting flag)
{
	int	index;

	index = 0;
	while (colors[index])
	{
		if (ft_atoi(colors[index]) > 255 || ft_atoi(colors[index]) < 0)
			return (error_(ERR_COLORS, 0, ERROR));
		if (flag & C_C)
			(*container)->c_ceiling[index] = ft_atoi(colors[index]);
		if (flag & C_F)
			(*container)->c_floor[index] = ft_atoi(colors[index]);
		index++;
	}
	array_destroyer(&colors);
}

void	position_(t_parser *data, int i, int j, int m_size[2])
{
	if (i - 1 >= 0 && i + 1 < m_size[0])
		if (!ft_strchr(VALID_, data->map[i - 1][j]) && data->map[i + 1][j])
			error_(ERR_MAP, 0, ERROR);
	if (i + 1 >= 0 && i + 1 < m_size[0])
		if (!ft_strchr(VALID_, data->map[i + 1][j]) && data->map[i + 1][j])
			error_(ERR_MAP, 0, ERROR);
	if (j - 1 >= 0 && j - 1 < m_size[1])
		if (!ft_strchr(VALID_, data->map[i][j - 1]) && data->map[i + 1][j])
			error_(ERR_MAP, 0, ERROR);
	if (j + 1 >= 0 && j + 1 < m_size[0])
		if (!ft_strchr(VALID_, data->map[i][j + 1]) && data->map[i + 1][j])
			error_(ERR_MAP, 0, ERROR);
}

void	checkup_line(t_parser *data, char *line, int index, int flag)
{
	int	map_size[2];
	int	i;

	i = 0;
	map_size[0] = 0;
	while (data->map[map_size[0]])
		map_size[0]++;
	map_size[1] = ft_strlen(line);
	while (line[i])
	{
		if (line[space(line, FIRST)] != '1' || line[space(line, LAST)] != '1')
			error_(ERR_MAP, 0, ERROR);
		if (!ft_strchr(MAP_KEY, line[i]))
			error_(ERR_MAP, 0, ERROR);
		if (flag & (FIRST | LAST))
			if (!ft_strchr("1 ", line[i]))
				error_(ERR_MAP, 0, ERROR);
		if (line[i] == 'D')
			door(data->map, index, i, map_size);
		if (flag & SPACE && ft_isspace(line[i]))
			position_(data, index, i, map_size);
		i++;
	}
}
