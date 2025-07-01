#include "so_long.h"

void update_player_img(char c,t_game *data)
{
	mlx_destroy_image(data->mlx, data->t_player.player_pose);
	if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'C' && data->colect == 1)
	{
		mlx_destroy_image(data->mlx, data->t_map.img_exit);
		data->t_map.img_exit = mlx_xpm_file_to_image(data->mlx, "./textures/o_exit.xpm", &data->t_map.img_x, &data->t_map.img_y);
	}
	if (c == 'w')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./textures/player_up.xpm", &data->t_map.img_x, &data->t_map.img_y);
	if (c == 'a')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./textures/player_left.xpm", &data->t_map.img_x, &data->t_map.img_y);
	if (c == 's')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./textures/player_down.xpm", &data->t_map.img_x, &data->t_map.img_y);
	if (c == 'd')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./textures/player_right.xpm", &data->t_map.img_x, &data->t_map.img_y);	
}

int	handle_w(t_game *data)
{
	update_player_img('w', data);
	if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == '1' 
		|| data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E')
		data->t_player.player_y += 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->t_map.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->t_map.map[data->t_player.player_y + 1][data->t_player.player_x] = '0';
		render_map(data);
	}
	return(0);
}
int	handle_a(t_game *data)
{
	update_player_img('a', data);
	if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == '1' 
		|| data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E')
		data->t_player.player_x += 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->t_map.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->t_map.map[data->t_player.player_y][data->t_player.player_x + 1] = '0';
		render_map(data);
	}
	return(0);
}
int	handle_s(t_game *data)
{
	update_player_img('s', data);
	if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == '1' 
		|| data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E')
		data->t_player.player_y -= 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->t_map.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->t_map.map[data->t_player.player_y - 1][data->t_player.player_x] = '0';
		render_map(data);
	}
	return(0);
}
int	handle_d(t_game *data)
{
	update_player_img('d', data);
	if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == '1' 
		|| data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'E')
		data->t_player.player_x -= 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->t_map.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->t_map.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->t_map.map[data->t_player.player_y][data->t_player.player_x - 1] = '0';
		render_map(data);
	}
	return(0);
}
