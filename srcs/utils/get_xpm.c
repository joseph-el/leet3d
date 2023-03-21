/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:33:31 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/19 21:31:06 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	*get_img(t_leet *leet, char *path)
{
	void	*ptr;
	int		size;

	ptr = mlx_xpm_file_to_image(leet->mlx, path, &size, &size);
	return (ptr);
}

void	get_loading_assets(t_leet *leet)
{
	leet->img[17] = get_img(leet, "./assets/2L1.xpm");
	leet->img[18] = get_img(leet, "./assets/2L2.xpm");
	leet->img[19] = get_img(leet, "./assets/2L3.xpm");
	leet->img[20] = get_img(leet, "./assets/2L4.xpm");
	leet->img[21] = get_img(leet, "./assets/2L5.xpm");
	leet->img[22] = get_img(leet, "./assets/2L6.xpm");
	leet->img[23] = get_img(leet, "./assets/2L7.xpm");
	leet->img[24] = get_img(leet, "./assets/3L1.xpm");
	leet->img[25] = get_img(leet, "./assets/3L2.xpm");
	leet->img[26] = get_img(leet, "./assets/3L3.xpm");
	leet->img[27] = get_img(leet, "./assets/3L4.xpm");
	leet->img[28] = get_img(leet, "./assets/3L5.xpm");
	leet->img[29] = get_img(leet, "./assets/3L6.xpm");
	leet->img[30] = get_img(leet, "./assets/3L7.xpm");
	leet->img[31] = get_img(leet, "./assets/r1.xpm");
	leet->img[32] = get_img(leet, "./assets/r2.xpm");
	leet->img[33] = get_img(leet, "./assets/r3.xpm");
	leet->img[34] = get_img(leet, "./assets/r4.xpm");
	leet->img[35] = get_img(leet, "./assets/r5.xpm");
	leet->img[36] = get_img(leet, "./assets/r6.xpm");
	leet->img[37] = get_img(leet, "./assets/r7.xpm");
}

void	get_action(t_leet *leet, int flag)
{
	if (flag & HEALT1)
	{
		leet->img[46] = get_img(leet, "./assets/hlt1.xpm");
		leet->img[47] = get_img(leet, "./assets/hlt2.xpm");
		leet->img[48] = get_img(leet, "./assets/hlt3.xpm");
		leet->img[49] = get_img(leet, "./assets/hlt4.xpm");
		leet->img[50] = get_img(leet, "./assets/hlt5.xpm");
		leet->img[51] = get_img(leet, "./assets/hlt6.xpm");
		leet->img[52] = get_img(leet, "./assets/start.xpm");
		return ;
	}
	leet->img[38] = get_img(leet, "./assets/gun1.xpm");
	leet->img[39] = get_img(leet, "./assets/gun2.xpm");
	leet->img[40] = get_img(leet, "./assets/gun3.xpm");
	leet->img[41] = get_img(leet, "./assets/gun4.xpm");
	leet->img[42] = get_img(leet, "./assets/gun5.xpm");
	leet->img[43] = get_img(leet, "./assets/gun6.xpm");
	leet->img[44] = get_img(leet, "./assets/gun7.xpm");
	leet->img[45] = get_img(leet, "./assets/gun8.xpm");
	return ;
}

void	get_assets(t_leet *leet)
{
	leet->img[0] = get_img(leet, "./assets/home.xpm");
	leet->img[1] = get_img(leet, "./assets/map_page.xpm");
	leet->img[2] = get_img(leet, "./assets/page_textures.xpm");
	leet->img[3] = get_img(leet, "./assets/settings.xpm");
	leet->img[4] = get_img(leet, "./assets/pause.xpm");
	leet->img[5] = get_img(leet, "./assets/cntrl_pause.xpm");
	leet->img[6] = get_img(leet, "./assets/effmap.xpm");
	leet->img[7] = get_img(leet, "./assets/efftextu.xpm");
	leet->img[8] = get_img(leet, "./assets/effsetting.xpm");
	leet->img[9] = get_img(leet, "./assets/effexit.xpm");
	leet->img[10] = get_img(leet, "./assets/1L1.xpm");
	leet->img[11] = get_img(leet, "./assets/1L2.xpm");
	leet->img[12] = get_img(leet, "./assets/1L3.xpm");
	leet->img[13] = get_img(leet, "./assets/1L4.xpm");
	leet->img[14] = get_img(leet, "./assets/1L5.xpm");
	leet->img[15] = get_img(leet, "./assets/1L6.xpm");
	leet->img[16] = get_img(leet, "./assets/1L7.xpm");
	leet->img[53] = get_img(leet, "./assets/game-over.xpm");
	get_loading_assets(leet);
}
