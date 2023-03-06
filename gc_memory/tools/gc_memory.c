/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:52:12 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/06 08:47:23 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_memory.h"

t_gc	*gc_init(void)
{
	t_gc	*gc;

	gc = malloc(sizeof(t_gc));
	if (!gc)
		return (NULL);
	gc->overall = NULL;
	return (gc);
}

void	gc_clean_dustbin(t_dustbin **dustbin)
{
	t_dustbin	*tmp_free;

	if (!*dustbin || !dustbin)
		return ;
	while ((*dustbin))
	{
		tmp_free = (*dustbin);
		(*dustbin) = (*dustbin)->next;
		free(tmp_free->address);
		free(tmp_free);
	}
	(*dustbin) = NULL;
}

int	gc_purifying(t_gc **gc, int flag)
{
	gc_clean_dustbin(&(*gc)->overall);
	free(*gc);
	*gc = NULL;
	return (EXIT_SUCCESS);
}

t_gc	*gc_adding_adress(t_gc *gc, void *address, int flag)
{
	t_dustbin	*dustbin;

	dustbin = malloc(sizeof(t_dustbin));
	if (!dustbin)
		return (NULL);
	dustbin->address = address;
	dustbin->next = NULL;
	if (flag & TMP)
	{
		dustbin->next = gc->temporary;
		gc->temporary = dustbin;
		return (gc);
	}
	dustbin->next = gc->overall;
	gc->overall = dustbin;
	return (gc);
}

void	*gc(t_gc *gc, void *newaddress, int flag)
{
	if (flag & CLEAN_ALL)
		gc_clean_dustbin(&gc->overall)
	if (!gc_adding_adress(gc, newaddress, flag))
		return (NULL);
	return (newaddress);
}
