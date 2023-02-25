/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:36:13 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/25 09:36:26 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libtools.h"

static int	found(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		length;
	char	*dest;
	size_t	i;

	if (s1 == 0)
		return (NULL);
	length = ft_strlen(s1);
	i = 0;
	while (found(s1[i], (char *)set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (found(s1[length - 1], (char *)set))
		length--;
	dest = (char *)malloc(sizeof(char) * ((length - i) + 1));
	if (!dest)
		return (NULL);
	ft_memmove(dest, &s1[i], length - i);
	dest[length - i] = '\0';
	return (dest);
}