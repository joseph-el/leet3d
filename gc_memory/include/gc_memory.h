/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:50:11 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/06 08:48:22 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_MEMORY_H
# define GC_MEMORY_H

# include <stdlib.h>
# include <unistd.h>

# define CLEAN_ALL 4
# define ADD 8

typedef struct s_dustbin
{
	void				*address;
	struct s_dustbin	*next;
}						t_dustbin;

typedef struct s_gc
{
	t_dustbin			*textures;
	t_dustbin			*maps;
	t_dustbin			*;
	t_dustbin			*textures;
	t_dustbin			*textures;
}						t_gc;

/*
** @gc_memory function and tools
*/

t_gc					*gc_init(void);
t_gc					*gc_adding_adress(t_gc *gc, void *address, int flag);
void					*gc(t_gc *gc, void *newaddress, int flag);
void					gc_clean_dustbin(t_dustbin **dustbin);
int						gc_purifying(t_gc **gc, int flag);

#endif