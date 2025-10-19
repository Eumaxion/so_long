/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:02:59 by mlima-si          #+#    #+#             */
/*   Updated: 2025/10/19 23:52:04 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_open_fd(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 19);
	write(2, "invalid FD.\n\033[0m", 17);
	exit(EXIT_FAILURE);
}

int	map_error(int n)
{
	if (n == 1)
	{
		write(2, "\033[1;31m🛑 ERROR: ", 20);
		write(2, "irregular map proportions or walls.\n\033[0m", 41);
	}
	if (n == 2)
	{
		write(2, "\033[1;31m🛑 ERROR: ", 20);
		write(2, "number or type of itens invalid.\n\033[0m", 38);
	}
	if (n == 3)
	{
		write(2, "\033[1;31m🛑 ERROR: ", 20);
		write(2, "map path invalid.\n\033[0m", 23);
	}
	if (n == 4)
	{
		write(2, "\033[1;31m🛑 USAGE: ./so_long maps/map_name.bar\n", 48);
		exit(EXIT_FAILURE);
	}
	return (0);
}
