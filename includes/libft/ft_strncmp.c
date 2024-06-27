/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:54:21 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:50 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"

/* ********************************FUNCTIONS********************************* */

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (s1 == s2)
		return (0);
	while (len-- > 0)
	{
		if ((unsigned char)*s1 > (unsigned char)*s2)
			return (1);
		if ((unsigned char)*s2 > (unsigned char)*s1)
			return (-1);
		if ((unsigned char)*s2 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
