/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:32:18 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/07/10 16:35:17 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"
#include <stdlib.h>

/* ********************************FUNCTIONS********************************* */

static size_t	ft_strcmpchrs(char const *s1, char const *set, size_t mov)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(set);
	i = 0;
	j = 0;
	if ((int)mov < 0)
		j = ft_strlen(s1) - 1;
	while ((i < len) && (j >= 0))
	{
		if (s1[j] == set[i++])
		{
			i = 0;
			j += mov;
		}
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = ft_strcmpchrs(s1, set, 1);
	if (i == ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	j = ft_strcmpchrs(s1, set, -1);
	j -= i - 2;
	res = ft_calloc(j, sizeof(char));
	if (!res)
		return (0);
	k = 0;
	while (k < j - 1)
	{
		res[k] = (char)s1[i + k];
		k++;
	}
	return (res);
}
