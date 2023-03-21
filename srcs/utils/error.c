/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:25:18 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/21 21:27:38 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	last_line(char **line, int m_size)
{
	int	i;

	i = 0;
	if (!line[m_size + 1])
		return ;
	while (line[m_size][i])
	{
		if (ft_strchr("KDNSWZE0", line[m_size][i]))
		{
			if (line[m_size + 1] && line[m_size + 1][i] && \
				line[m_size + 1][i] != '1')
				error_(ERR_MAP, 0, ERROR);
		}
		i ++;
	}
}

void	error_color(char *line, int *index)
{
	*index = 0;
	if (!*line || !ft_isdigit(*line) || !ft_strchr(line, ','))
		error_(ERR_COLORS, 0, ERROR);
}

void	error_(char *error, int errno_s, int flag)
{
	ft_putstr_fd(RED"Error : ", 2);
	if (flag & ERROR)
	{
		ft_putstr_fd(error, 2);
		ft_putstr_fd(" ", 2);
	}
	if (flag & FATAL)
		ft_putstr_fd(strerror(errno_s), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(WHITE, 2);
	exit(EXIT_FAILURE);
}
