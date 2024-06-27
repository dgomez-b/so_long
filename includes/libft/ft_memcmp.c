/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:40:51 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:49:39 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* LIBRARIES ******************************** */

#include "./libft.h"

/* ******************************* FUNCTIONS ******************************** */

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)b1;
	s2 = (unsigned char *)b2;
	i = 0;
	while (i < len && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
