/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:33:49 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:53:30 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	chk_file_path(char *file_path)
{
	unsigned int	i;

	i = string_length(file_path);
	if (i < 4)
		file_extension_error();
	if (file_path[i - 1] != 'r' || file_path[i - 2] != 'e'
		|| file_path[i - 3] != 'b' || file_path[i - 4] != '.')
		file_extension_error();
	i--;
	while (i > 0 && file_path[i] != '/')
		i--;
	if ((i == 0 && file_path[i] == '.') || (file_path[i + 1] == '.'))
		private_file_error();
}
