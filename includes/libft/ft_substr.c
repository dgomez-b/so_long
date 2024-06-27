/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:43:31 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/07/04 16:21:03 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"
#include <stdlib.h>

/* ********************************FUNCTIONS********************************* */

char	*ft_substr(const char *s, unsigned int i, size_t len)
{
	size_t	len2;
	char	*res;
	size_t	j;

	if (!s)
		return (0);
	if (i > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	len2 = ft_strlen(s + i);
	if (len2 > len)
		len2 = len;
	res = ft_calloc(len2 + 1, sizeof(char));
	if (!res)
		return (0);
	j = 0;
	while (j < len2)
		res[j++] = s[i++];
	return (res);
}
