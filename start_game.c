/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:52:50 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/06 10:31:39 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moviments(int keysim, t_game *data)
{
	if (keysim == KEY_W || keysim == KEY_UP
		|| keysim == KEY_A || keysim == KEY_LEFT
		|| keysim == KEY_S || keysim == KEY_DOWN
		|| keysim == KEY_D || keysim == KEY_RIGHT)
	{
		data->moves += 1;
		ft_printf("moves ---------------- %d\n", data->moves);
	}
}

int	handle_esc(t_game *data)
{
	write(1, "\033[1;32m I hope you enjoyed the game...\n", 40);
	write(1, "...closing!\n\033[0m ", 18);
	exit_game(data);
	return (0);
}

int	handle_key(int keysim, t_game *data)
{
	if (keysim == KEY_ESC)
		handle_esc(data);
	if (keysim == KEY_W || keysim == KEY_UP)
	{
		data->player_y -= 1;
		handle_w(data);
	}
	if (keysim == KEY_A || keysim == KEY_LEFT)
	{
		data->player_x -= 1;
		handle_a(data);
	}
	if (keysim == KEY_S || keysim == KEY_DOWN)
	{
		data->player_y += 1;
		handle_s(data);
	}
	if (keysim == KEY_D || keysim == KEY_RIGHT)
	{
		data->player_x += 1;
		handle_d(data);
	}
	print_moviments(keysim, data);
	return (0);
}

int	start_game(t_game *data)
{
	gather_elements(data);
	render_map(data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
	return (0);
}
