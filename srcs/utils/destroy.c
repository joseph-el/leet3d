/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:24:40 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/19 10:29:01 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	array_destroyer(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
		free((*array)[i++]);
	free(*array);
	*array = NULL;
}

void	destroy_(t_leet *leet, int flag)
{
	if (flag & HEALT5)
	{
		mlx_destroy_image(leet->mlx, leet->img[46]);
		mlx_destroy_image(leet->mlx, leet->img[47]);
		mlx_destroy_image(leet->mlx, leet->img[48]);
		mlx_destroy_image(leet->mlx, leet->img[49]);
		mlx_destroy_image(leet->mlx, leet->img[50]);
		mlx_destroy_image(leet->mlx, leet->img[51]);
		mlx_destroy_image(leet->mlx, leet->img[52]);
		return ;
	}
	mlx_destroy_image(leet->mlx, leet->img[38]);
	mlx_destroy_image(leet->mlx, leet->img[39]);
	mlx_destroy_image(leet->mlx, leet->img[40]);
	mlx_destroy_image(leet->mlx, leet->img[41]);
	mlx_destroy_image(leet->mlx, leet->img[42]);
	mlx_destroy_image(leet->mlx, leet->img[43]);
	mlx_destroy_image(leet->mlx, leet->img[44]);
	mlx_destroy_image(leet->mlx, leet->img[45]);
}

void	ft_exit(void)
{
	system(S_KILL);
	exit(EXIT_SUCCESS);
}
