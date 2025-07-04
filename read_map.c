/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:53:03 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/04 16:23:53 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *data, char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_open_fd();
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
	}
	data->t_map.map = ft_split(holder_map, '\n');
	data->t_map.map_clone = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
}

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
