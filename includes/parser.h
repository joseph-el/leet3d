/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:06:04 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/12 13:02:13 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "leet3d.h"

# define INIT 16
# define CHECK 8
# define EXIT 32
# define NL 10
# define LAST 16
# define FIRST 4
# define SPACE 32
# define VERTICAL 14
# define HORIZONTAL 32
# define MAP_KEY "01 NSEWDZ"
# define ERR_MISSING "Missing something! "
# define ERR_KEY "Invalid Key! "
# define ERR_ARGS "Bad Argument! "
# define ERR_EXCT "The input file is missing the .cub extension! "
# define ERR_COLORS "Invalid Colors format! "
# define ERR_MAP "Invalid Map! "
# define ERR_POSITION "Invalid player position! "
# define ERR_DOOR "Invalid place for the door! "
# define ERR_PATH "Missing path of texture! "

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
	SOUTH = 123,
	EAST = 105,
	WEST = 127,
	NORTH = 116,
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
	t_position	position;
}				t_parser;

t_parser		*parser(char *path);
t_setting		key(char *line);
t_position		get_size(t_parser *container);
bool			extensions(char *path);
int				space(char *line, int flag);
char			**map_size(t_parser **container);
char			**realloc_arrays(char ***arrays, char *new_, bool *space);
void			analysis_map(t_parser *data);
void			set_data(t_parser **container, int fd_map);
void	        door(char **map, int i, int j, int m_size[2]);
void			container_tools(t_parser **container, int flag);
void			position_(t_parser *data, int i, int j, int m_size[2]);
void			set_texture(t_parser **container, char *line, t_setting ret);
void			set_colors(t_parser **container, char *line, t_setting flag);
void			checkup_line(t_parser *data, char *line, int index, int flag);
void			analysis_rgb(t_parser **container, char **colors,
					t_setting flag);

# endif