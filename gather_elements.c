#include "so_long.h"

void	gather_elements(t_game *data)
{
	int	size;

	size = PIXS;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->tmap.map_x * size, data->tmap.map_y * size, "so_long");
	data->tmap.img_backg = mlx_xpm_file_to_image(data->mlx, "./assets/background.xpm", size, size);
	data->tmap.img_wall = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", size, size);
	data->tmap.img_colect = mlx_xpm_file_to_image(data->mlx, "./assets/colectable.xpm", size, size);
	data->tmap.img_exit = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm", size, size);
	create_player(data);
}

void create_player(t_game *data)
{
	int size;

	size = PIXS;
	data->player_up = mlx_xpm_file_to_image(data->mlx, "./assets/player_up.xpm", size, size);
	data->player_left = mlx_xpm_file_to_image(data->mlx,"./assets/player_left.xpm", size, size);
	data->player_right = mlx_xpm_file_to_image(data->mlx,"./assets/player_right.xpm", size, size);
	data->player_down = mlx_xpm_file_to_image(data->mlx,"./assets/player_down.xpm", size, size);
	data->player_walk_l = mlx_xpm_file_to_image(data->mlx, "./assets/player_walk_l.xpm", size, size);
	data->player_walk_r = mlx_xpm_file_to_image(data->mlx, "./assets/player_walk_r.xpm", size, size);
}