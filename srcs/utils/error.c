/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:05:50 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/10 17:22:12 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "leet3d.h"

void	error_(char *error, int errno_s, int flag)
{
	ft_putstr_fd(RED"Error : ", 2);
	if (flag & ERROR)
	{
		ft_putstr_fd(error, 2);
		ft_putstr_fd(" ", 2);
	}
	if (flag & FATAL)
	{
		fprintf(stderr, "Check errno |%d|\n", errno);
		ft_putstr_fd(strerror(errno_s), 2);
	}
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(WHITE, 2);
	exit(EXIT_FAILURE);
}