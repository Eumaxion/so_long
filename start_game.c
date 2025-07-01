
#include "so_long.h"

int	handle_esc(t_game *data)
{
	exit_game(data);
	return (0);
}
int	handle_key(int keysim, t_game *data)
{
	data->moves += 1;
	printf("moves: %d\n", data->moves);
	if (keysim == key_esc)
		handle_esc(data);
	if (keysim == key_w || keysim == key_up)
	{
		data->t_player.player_y -= 1;
		handle_w(data);
	}
	if (keysim == key_a || keysim == key_left)
	{
		data->t_player.player_x -= 1;
		handle_a(data);
	}
	if (keysim == key_s || keysim == key_down)
	{
		data->t_player.player_y += 1;
		handle_s(data);
	}
	if (keysim == key_d || keysim == key_right)
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
	mlx_key_hook(data->win, handle_key, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
	return(0);
}
