/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:08:54 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/07/10 15:12:49 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"
#include <stdlib.h>

/* ********************************FUNCTIONS********************************* */

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1l;
	size_t	s2l;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	ft_memcpy(str, s1, s1l);
	ft_memcpy(str + s1l, s2, s2l);
	str[s1l + s2l] = 0;
	return (str);
}
