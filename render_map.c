/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:53:01 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:19:05 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *data, int x, int y)
{
	char	character;

	character = data->t_map.map[y][x];
	if (character == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->t_map.img_backg, x * PIXS, y * PIXS);
	else if (character == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_pose, x * PIXS, y * PIXS);
	else if (character == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->t_map.img_colect, x * PIXS, y * PIXS);
	else if (character == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->t_map.img_exit, x * PIXS, y * PIXS);
	else if (character == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->t_map.img_wall, x * PIXS, y * PIXS);
}

int	render_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->t_map.map[y])
	{
		x = 0;
		while (data->t_map.map[y][x])
		{
			put_image(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
