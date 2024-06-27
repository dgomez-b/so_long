/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:38:43 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:42 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"

/* ********************************FUNCTIONS********************************* */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (len > dstsize)
		len = dstsize;
	i = 0;
	while (src[i] && (i + len < dstsize - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	if (i != 0)
		dst[len + i] = 0;
	return (len + ft_strlen(src));
}
