#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
int	exit_game(t_game *data)
{
	free_map(data->tmap.map);
	mlx_destroy_image(data->mlx, data->tmap.img_backg);
	mlx_destroy_image(data->mlx, data->tmap.img_colect);
	mlx_destroy_image(data->mlx, data->tmap.img_exit);
	mlx_destroy_image(data->mlx, data->tmap.img_wall);
	mlx_destroy_image(data->mlx, data->t_player.player_pose);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}
