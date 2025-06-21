#include "so_long.h"

void	put_map(t_game *data, int x, int y)
{

}

void render_map(t_game *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < data->tmap.map_y)
	{
		while(x < data->tmap.map_x)
		{
			put_map(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
