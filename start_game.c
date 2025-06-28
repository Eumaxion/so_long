
#include "so_long.h"

int	handle_key(int keysim, t_game *data)
{
	if (keysim == 65307)
		handle_esc(data);
	if (keysim == 119 || keysim == 65362)
		handle_w(data);
	if (keysim == 97 || keysim == 65361)
		handle_a(data);
	if (keysim == 115 || keysim == 65364)
		handle_s(data);
	if (keysim == 100 || keysim == 65363)
		handle_d(data);
	printf("KEY: %d\n", keysim);
	return(0);
}

int	start_game(t_game *data)
{
	gather_elements(data);
	render_map(data);
	mlx_key_hook(data->win, handle_key, &data);
	mlx_hook(data->win, 17, 0, exit_game, &data);
	return(0);
}
