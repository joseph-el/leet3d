/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:45:33 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/19 21:30:02 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "leet3d.h"

void	p_control(t_leet *leet, t_short ret)
{
	if (ret & (CNTRL_A | CONTROL_A))
	{
		leet->cntrl.control_c = 0;
		leet->cntrl.control_b = 0;
		leet->cntrl.control_a = 1;
	}
	else if (ret & (CNTRL_B | CONTROL_B))
	{
		leet->cntrl.control_c = 0;
		leet->cntrl.control_a = 0;
		leet->cntrl.control_b = 1;
	}
	else if (ret & (CNTRL_C | CONTROL_C))
	{
		leet->cntrl.control_a = 0;
		leet->cntrl.control_b = 0;
		leet->cntrl.control_c = 1;
	}
	if (ret & (CNTRL_A | CNTRL_B | CNTRL_C))
		leet->flag = G_PAUSE;
	leet->sound.click = 1;
}

static void	set_music(t_sound *sound, t_short ret)
{
	sound->sound1 = (ret == SOUND1);
	sound->sound2 = (ret == SOUND2);
	sound->sound3 = (ret == SOUND3);
	sound->sound4 = (ret == SOUND4);
	sound->is_run = 0;
}

void	set_setting(t_leet *leet, t_short ret)
{
	if (ret & CONTROLS)
		return (p_control(leet, ret));
	else if (ret & (UVOLUME | DVOLUME))
	{
		leet->sound.up = (ret == UVOLUME);
		leet->sound.down = (ret == DVOLUME);
	}
	else if (ret & (MVOLUME | EVOLUME))
	{
		leet->sound.general = (ret == EVOLUME);
		if (!leet->sound.general)
			(system(MUTE));
		if (leet->sound.general)
			(system(UNMUTE));
	}
	else if (ret & (MSOUND | ESOUND))
		leet->sound.sound = (ret == ESOUND);
	else if (ret & (MSFX | ESFX))
		leet->sound.sfx = (ret == ESFX);
	else if (ret & (SOUND1 | SOUND2 | SOUND3 | SOUND4))
		set_music(&leet->sound, ret);
	else if (ret & BACK)
		leet->flag = HOME;
	leet->sound.click = 1;
}

void	g_graphics(t_leet *leet, t_short ret)
{
	if (ret & BACK)
		return (leet->sound.click = 1, (void)(leet->flag = HOME));
	if (leet->flag & MAPS && ret & SET_MAP)
	{
		leet->parser->position = NORTH;
		leet->parser->p_indices[0] = (ret == MAP1) * Y_MAP1 + \
			(ret == MAP2) * Y_MAP2 + (ret == MAP3) * Y_MAP3 + \
			(ret == MAP4) * Y_MAP4;
		leet->parser->p_indices[1] = (ret == MAP1) * X_MAP1 + \
			(ret == MAP2) * X_MAP2 + (ret == MAP3) * X_MAP3 + \
			(ret == MAP4) * X_MAP4;
		array_destroyer(&leet->parser->map);
		leet->parser->map = switch_map(leet, ret);
	}
	if (leet->flag & TEXTURE && ret & SET_TEXTURE)
	{
		leet->textures = 1;
		array_destroyer(&leet->parser->texture);
		leet->parser->texture = NULL;
		leet->parser->texture = switch_texture(leet, ret);
	}
	leet->sound.click = 1;
	leet->is_run = 0;
}

void	g_pause(t_leet *leet, t_short ret)
{
	if (ret & QUIT_G)
	{
		leet->flag = LOADING;
		leet->flag_img = P_GAME;
	}
	else if (ret & P_CONTRL)
		leet->flag = P_CONTRL;
	else if (ret & RESUME)
		leet->flag = GAME;
	leet->sound.click = 1;
}
