/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leet3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:59:25 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/25 23:27:24 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEET3D_H
# define LEET3D_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>

# include "../libtools/libtools.h"
# include "parcer.h"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"

void    error_(char *error, int errno_s, int flag);
void    array_destroyer(char **array);


#endif
