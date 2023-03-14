/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:23:51 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/14 08:30:29 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/leet3d.h"

char	**map_size(t_parser **container)
{
	char	**ret;
	int		width;
	int		size;
	int		i;

	size = -1;
	width = 0;
	while ((*container)->map[++size])
		if ((int)ft_strlen((*container)->map[size]) > width)
			width = ft_strlen((*container)->map[size]);
	ret = malloc(sizeof(char *) * (size + 1));
	ret[size] = NULL;
	i = 0;
	size = -1;
	while ((*container)->map[++size])
	{
		ret[size] = malloc(sizeof(char) * (width + 1));
		i = -1;
		while ((*container)->map[size][++i])
			ret[size][i] = (*container)->map[size][i];
		while (i < width)
			ret[size][i++] = ' ';
		ret[size][i] = 0;
	}
	return (array_destroyer(&(*container)->map), ret);
}

void	door(char **map, int i, int j, int m_size[2])
{
	int ret;

	ret = 0;
	if (i - 1 >= 0 && i - 1 < m_size[0] && i + 1 >= 0 && i + 1 < m_size[0] && \
		j - 1 >= 0 && j - 1 < m_size[1] && j + 1 >= 0 && j + 1 < m_size[1])
		ret = (map[i - 1][j] == '1' && map[i + 1][j] == '1') * HORIZONTAL + \
			(map[i][j - 1] == '1' && map[i][j + 1] == '1') * VERTICAL;
	if (ret & HORIZONTAL)
		ret = (map[i][j - 1] == '0' && map[i][j - 1] == '0');
	else if (ret & VERTICAL)
		ret = (map[i + 1][j] == '0' && map[i - 1][j] == '0');
	if (!ret)
		error_(ERR_DOOR, 0, ERROR);
}

bool	extensions(char *path)
{
	if (!path)
		return (false);
	path += ft_strlen(path);
	while (path)
	{
		if (*path == '.')
			return (!ft_memcmp(path, ".cub", sizeof(".cub")));
		path -= 1;
	}
	return (false);
}

int	space(char *line, int flag)
{
	int	first;
	int	last;

	first = 0;
	last = ft_strlen(line) - 1;
	while (flag & FIRST && line && ft_isspace(line[first]))
		first++;
	while (flag & LAST && line && ft_isspace(line[last]))
		last--;
	if (flag & FIRST)
		return (first);
	return (last);
}

t_setting	key(char *line)
{
	t_setting	ret;

	ret = (!ft_memcmp(line, "NO ", 3)) * NO + \
		(!ft_memcmp(line, "SO ", 3)) * SO + \
		(!ft_memcmp(line, "WE ", 3)) * WE + \
		(!ft_memcmp(line, "EA ", 3)) * EA + \
		(!ft_memcmp(line, "F ", 2)) * C_F + \
		(!ft_memcmp(line, "C ", 2)) * C_C + \
		(*line == '1' || *line == '0' || *line == 32) * M_KEY;
	return (ret);
}