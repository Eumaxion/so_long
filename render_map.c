#include "so_long.h"

void	put_image(t_game *data, int x, int y)
{
	char	character;
	character = data->t_map.map[y][x];
	if (character == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->t_map.img_backg, x * PIXS, y * PIXS);
 	else if (character == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->t_player.player_pose, x * PIXS, y * PIXS);
	else if (character == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->t_map.img_colect, x * PIXS, y * PIXS);
	else if (character == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->t_map.img_exit, x * PIXS, y * PIXS);
	else if (character == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->t_map.img_wall, x * PIXS, y * PIXS);
}

int render_map(t_game *data)
{
	int x;
	int y;

	y = 0;
	while(data->t_map.map[y])
	{
		x = 0;
		while(data->t_map.map[y][x])
		{
			put_image(data, x, y);
			x++;
		}
		y++;
	}
	return(0);
}
