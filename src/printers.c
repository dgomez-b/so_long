/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 01:16:26 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/06/24 01:53:07 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	putstr_fd(char *s, int fd)
{
	write(fd, s, string_length(s));
}

void	putnbr_fd(int n, int fd)
{
	char	c;

	c = '0';
	if (n < 0)
	{
		c = '0' + ((n % 10) * -1);
		n /= 10;
		if (write(fd, "-", 1) == -1)
			return ;
		if (n != 0)
			putnbr_fd(n * -1, fd);
	}
	else if (n > 0)
	{
		c = '0' + (n % 10);
		n /= 10;
		if (n != 0)
			putnbr_fd(n, fd);
	}
	if (write(fd, &c, 1) == -1)
		return ;
}
