/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:19:49 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/20 07:20:03 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "leet3d.h"

typedef enum s_setting
{
	NO = 1 << 0,
	SO = 1 << 1,
	WE = 1 << 2,
	EA = 1 << 3,
	C_F = 1 << 4,
	C_C = 1 << 5,
	M_KEY = 1 << 6
}				t_setting;

typedef enum s_position
{
	SOUTH = 83,
	EAST = 78,
	WEST = 87,
	NORTH = 69,
}				t_position;

typedef struct s_parcer
{
	char		**texture;
	char		**map;
	int			c_floor[3];
	int			c_ceiling[3];
	int			p_indices[2];
	int			height;
	int			width;
	short		n_texture;
	t_position	position;
}				t_parser;

t_parser		*parser(char *path);
t_setting		key(char *line);
t_position		get_size(t_parser *container);
bool			extensions(char *path);
int				space(char *line, int flag);
char			**map_size(t_parser **container);
void			last_line(char **line, int m_size);
char			**realloc_arrays(char ***arrays, char *new_, bool *space);
void			analysis_map(t_parser *data);
void			error_color(char *line, int *index);
void			set_data(t_parser **container, int fd_map);
void			door(char **map, int i, int j, int m_size[2]);
void			container_tools(t_parser **container, int flag);
void			position_(t_parser *data, int i, int j, int m_size[2]);
void			set_texture(t_parser **container, char *line, t_setting ret);
void			set_colors(t_parser **container, char *line, t_setting flag);
void			checkup_line(t_parser *data, char *line, int index, int flag);
void			analysis_rgb(t_parser **container, char **colors,
					t_setting flag);

#endif