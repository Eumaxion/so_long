#include "so_long.h"

void update_player_img(char c,t_game *data)
{
	mlx_destroy_image(data->mlx, data->t_player.player_pose);
	if (c == 'w')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./assets/player_up.xpm", &data->tmap.img_x, &data->tmap.img_y);
	if (c == 'a')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./assets/player_left.xpm", &data->tmap.img_x, &data->tmap.img_y);
	if (c == 's')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./assets/player_down.xpm", &data->tmap.img_x, &data->tmap.img_y);
	if (c == 'd')
		data->t_player.player_pose = mlx_xpm_file_to_image(data->mlx,"./assets/player_right.xpm", &data->tmap.img_x, &data->tmap.img_y);	
}

int	handle_w(t_game *data)
{
	update_player_img('w', data);
	if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == '1')
	{
		data->t_player.player_y += 1;
		render_map(data);
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->tmap.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->tmap.map[data->t_player.player_y++][data->t_player.player_x] = '0';
		render_map(data);
	}
	return(0);
}
int	handle_a(t_game *data)
{
	update_player_img('a', data);
	if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == '1')
	{
		data->t_player.player_x += 1;
		render_map(data);
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->tmap.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->tmap.map[data->t_player.player_y][data->t_player.player_x++] = '0';
		render_map(data);
	}
	return(0);
}
int	handle_s(t_game *data)
{
	update_player_img('s', data);
	if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == '1')
	{
		data->t_player.player_y -= 1;
		render_map(data);
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->tmap.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->tmap.map[data->t_player.player_y--][data->t_player.player_x] = '0';
		render_map(data);
	}
	return(0);
}
int	handle_d(t_game *data)
{
	update_player_img('d', data);
	if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'E' && data->colect == 0)
		exit_game(data);
	else if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == '1')
	{
		data->t_player.player_x -= 1;
		render_map(data);
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->tmap.map[data->t_player.player_y][data->t_player.player_x] == 'C')
			data->colect -= 1;
		data->tmap.map[data->t_player.player_y][data->t_player.player_x] = 'P';
		data->tmap.map[data->t_player.player_y][data->t_player.player_x--] = '0';
		render_map(data);
	}
	return(0);
}
