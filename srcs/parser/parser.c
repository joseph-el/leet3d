/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:17:49 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/02 23:38:58 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

t_parser	*parser(char *path)
{
	t_parser	*container;
	int			fd_map;

	container = malloc(sizeof(t_parser));
	if (!container)
		return (error_(NULL, ENOMEM, FATAL), NULL);
	if (!extensions(path))
		return (error_(ERR_EXCT, 0, ERROR), NULL);
	fd_map = open(path, O_RDONLY);
	if (fd_map == -1)
		return (error_(path, ENOENT, FATAL | ERROR), NULL);
	container_tools(&container, INIT);
	set_data(&container, fd_map);
	container_tools(&container, CHECK | EXIT);
	container->map = map_size(&container);
	analysis_map(container);
	return (close(fd_map), container);
}