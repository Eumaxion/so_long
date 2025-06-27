#include "so_long.h"

void	gather_elements(t_game *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->tmap.map_x, data->tmap.map_y, "so_long");
	data->tmap.img_backg = mlx_xpm_file_to_image(data->mlx, "./assets/background.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->tmap.img_wall = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->tmap.img_colect = mlx_xpm_file_to_image(data->mlx, "./assets/colectable.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->tmap.img_exit = mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm", &data->tmap.img_x, &data->tmap.img_y);
	create_player(data);
	}

void	create_player(t_game *data)
{
	data->t_player.player_up = mlx_xpm_file_to_image(data->mlx, "./assets/player_up.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->t_player.player_left = mlx_xpm_file_to_image(data->mlx,"./assets/player_left.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->t_player.player_right = mlx_xpm_file_to_image(data->mlx,"./assets/player_right.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->t_player.player_down = mlx_xpm_file_to_image(data->mlx,"./assets/player_down.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->t_player.player_walk_l = mlx_xpm_file_to_image(data->mlx, "./assets/player_walk_l.xpm", &data->tmap.img_x, &data->tmap.img_y);
	data->t_player.player_walk_r = mlx_xpm_file_to_image(data->mlx, "./assets/player_walk_r.xpm", &data->tmap.img_x, &data->tmap.img_y);
}
