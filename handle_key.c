#include "so_long.h"

int	handle_esc(t_game *data)
{
	exit_game(data);
	return (0);
}
int	handle_w(t_game *data)
{
	data->t_player.player_y -= 1;
	printf("POS_Y: %d\n", data->t_player.player_y);
	return(0);
}
int	handle_a(t_game *data)
{
	data->t_player.player_x -= 1;
	printf("POS_X: %d\n", data->t_player.player_x);
	return(0);
}
int	handle_s(t_game *data)
{
	data->t_player.player_y += 1;
	printf("POS_Y: %d\n", data->t_player.player_y);
	return(0);
}
int	handle_d(t_game *data)
{
	data->t_player.player_x += 1;
	printf("POS_X: %d\n", data->t_player.player_x);
	return(0);
}
