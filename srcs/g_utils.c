/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:10:25 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/28 19:44:03 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/leet3d.h"

void	array_destroyer(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	array_p(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		printf(RED"%s\n", argv[i++]);
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
