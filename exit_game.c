/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:53:09 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:19:55 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *data)
{
	free_map(data->t_map.map);
	mlx_destroy_image(data->mlx, data->t_map.img_backg);
	mlx_destroy_image(data->mlx, data->t_map.img_colect);
	mlx_destroy_image(data->mlx, data->t_map.img_exit);
	mlx_destroy_image(data->mlx, data->t_map.img_wall);
	mlx_destroy_image(data->mlx, data->player_pose);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}
