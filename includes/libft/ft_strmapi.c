/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:22:48 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/07/12 16:26:25 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"
#include <stdlib.h>

/* ********************************FUNCTIONS********************************* */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*scopy;
	int		i;

	scopy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!scopy)
		return (0);
	i = 0;
	while (s[i])
	{
		scopy[i] = f((unsigned int)i, s[i]);
		i++;
	}
	scopy[i] = 0;
	return (scopy);
}
