#include "so_long.h"

void	put_image(t_game *data, int x, int y)
{
	char	character;
	character = data->tmap.map[y][x];
	if (character == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_backg, x, y);
 	else if (character == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->t_player.player_right, x , y);
	else if (character == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_colect, x , y);
	else if (character == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_exit, x, y);
	else if (character == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_wall, x, y);
}

void render_map(t_game *data)
{
	int x;
	int y;

	y = 0;
	while(data->tmap.map[y])
	{
		x = 0;
		while(data->tmap.map[y][x])
		{
			put_image(data, x, y);
			x++;
		}
		y++;
	}
}
