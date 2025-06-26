#include "so_long.h"

void	put_image(t_game *data, int x, int y)
{
	char	character;
	printf(" \n");
	printf(" PUT IMG x = %d, y = %d\n", x / PIXS , y / PIXS);
	character = data->tmap.map[x / PIXS][y / PIXS];
	if (character == 'P' || character == 'E' || character == 'C' || character == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_backg, x, y);
 	if (character == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->t_player.player_right, x , y );
	else if (character == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_colect, x, y);
	else if (character == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_exit, x, y);
	else if (character == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tmap.img_wall, x, y);
}

void render_map(t_game *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_clear_window(data->mlx, data->win);
	printf(" MAP SIZE x = %d, y = %d\n", data->tmap.map_x , data->tmap.map_y);
	while(y < data->tmap.map_y)
	{
		while(x < data->tmap.map_x)
		{
			put_image(data, x * PIXS, y * PIXS);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_do_sync(data->mlx);
}
