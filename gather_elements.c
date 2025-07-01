#include "so_long.h"

void	gather_elements(t_game *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->t_map.map_x, data->t_map.map_y, "so_long");
	data->moves = -1;
	data->t_map.img_backg = mlx_xpm_file_to_image(data->mlx, "./textures/background.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_colect = mlx_xpm_file_to_image(data->mlx, "./textures/colectable.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm", &data->t_map.img_x, &data->t_map.img_y);
	create_player(data);
	}

void	create_player(t_game *data)
{
	int x;
	int y;
	data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./textures/player_right.xpm", &data->t_map.img_x, &data->t_map.img_y);
	y = 0;
	x = 0;
	while(data->t_map.map[y])
	{
		while(data->t_map.map[y][x])
		{
			if (data->t_map.map[y][x] == 'P')
			{
				data->t_player.player_x = x;
				data->t_player.player_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
/* 	data->t_player.player_up = mlx_xpm_file_to_image(data->mlx, "./textures/player_up.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_player.player_right = mlx_xpm_file_to_image(data->mlx,"./textures/player_right.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_player.player_down = mlx_xpm_file_to_image(data->mlx,"./textures/player_down.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_player.player_walk_l = mlx_xpm_file_to_image(data->mlx, "./textures/player_walk_l.xpm", &data->t_map.img_x, &data->t_map.img_y);
	data->t_player.player_walk_r = mlx_xpm_file_to_image(data->mlx, "./textures/player_walk_r.xpm", &data->t_map.img_x, &data->t_map.img_y); */
}
