/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:53:07 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/04 17:46:24 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gather_elements(t_game *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->t_map.map_width * PIXS,
			data->t_map.map_height * PIXS, "so_long");
	data->moves = -1;
	data->t_map.img_backg = mlx_xpm_file_to_image(data->mlx,
			"./textures/background.xpm",
			&data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm",
			&data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_colect = mlx_xpm_file_to_image(data->mlx,
			"./textures/colectable.xpm",
			&data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm",
			&data->t_map.img_x, &data->t_map.img_y);
	data->player_pose = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_right.xpm",
			&data->t_map.img_x, &data->t_map.img_y);
}

void	update_door_img(t_game *data)
{
	if (data->t_map.map[data->player_y][data->player_x] == 'E')
	{
		mlx_destroy_image(data->mlx, data->t_map.img_exit);
		data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx,
				"./textures/closed_exit.xpm",
				&data->t_map.img_x, &data->t_map.img_y);
	}
	else if ((data->t_map.map[data->player_y][data->player_x] == 'C'
		&& data->colect == 1) || data->colect == 0)
	{
		mlx_destroy_image(data->mlx, data->t_map.img_exit);
		data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx,
				"./textures/o_exit.xpm",
				&data->t_map.img_x, &data->t_map.img_y);
	}
	else
	{
		mlx_destroy_image(data->mlx, data->t_map.img_exit);
		data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx,
				"./textures/exit.xpm", &data->t_map.img_x, &data->t_map.img_y);
	}
}

void	player_position(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->t_map.map[y])
	{
		while (data->t_map.map[y][x])
		{
			if (data->t_map.map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
