/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:07 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:38:28 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* LIBRARIES ******************************** */

#include "./libft.h"

/* ******************************* FUNCTIONS ******************************** */

void	*ft_memchr(void *b, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	chr;
	size_t			i;

	s = (unsigned char *)b;
	i = 0;
	chr = (unsigned char)c;
	while (i < len && s[i] != chr)
		i++;
	if (i == len)
		return (0);
	return (s + i);
}
