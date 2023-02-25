/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:49:13 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/25 16:04:29 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

int ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	if (!str)
		return (-1);
	ret = 0;
	while (*str && ft_isspace(*str))
		str ++;
	sign = (*str == '-') * -1 + (*str == '+') * 1;
	if (!sign)
		sign = 1;
	str += (*str == '+' || *str == '-');
	while (*str && ft_isdigit(*str))
	{
		ret = (ret * 10) + (*str - '0');
		str ++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
			return (-1);
		str ++;
	}
	return (ret * sign);
}