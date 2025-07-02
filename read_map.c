/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:53:03 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 14:33:00 by mlima-si         ###   ########.fr       */
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
