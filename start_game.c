
#include "so_long.h"

int	handle_esc(t_game *data)
{
	exit_game(data);
	return (0);
}
int	handle_key(int keysim, t_game *data)
{
	printf("y = %d, x = %d \n", data->t_player.player_y, data->t_player.player_x);
	if (keysim == 65307)
		handle_esc(data);
	if (keysim == 119 || keysim == 65362)
	{
		data->t_player.player_y -= 1;
		handle_w(data);
	}
	if (keysim == 97 || keysim == 65361)
	{
		data->t_player.player_x -= 1;
		handle_a(data);
	}
	if (keysim == 115 || keysim == 65364)
	{
		data->t_player.player_y += 1;
		handle_s(data);
	}
	if (keysim == 100 || keysim == 65363)
	{
		data->t_player.player_x += 1;
		handle_d(data);
	}
	return(0);
}

int	start_game(t_game *data)
{
	gather_elements(data);
	render_map(data);
	printf("y = %d, x = %d \n", data->t_player.player_y, data->t_player.player_x);
	mlx_key_hook(data->win, handle_key, &data);
	mlx_hook(data->win, 17, 0, exit_game, &data);
	return(0);
}
