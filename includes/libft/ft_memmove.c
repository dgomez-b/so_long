/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:58:35 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:35 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"

/* ********************************FUNCTIONS********************************* */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*sdst;
	char	*ssrc;

	if (src > dst)
	{
		i = 0;
		ssrc = (char *)src;
		sdst = (char *)dst;
		while (i < n)
		{
			sdst[i] = ssrc[i];
			i++;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, n));
}
