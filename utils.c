#include "so_long.h"

void	my_mlx_pixel_put(tt_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int handle_esc(int key,t_mlx_data *data)
{
	mlx_destroy_window(data->con, data->win);
	mlx_destroy_display(data->con);
	free(data->con);
	exit(1);
}

/* int handle_w(t_mlx_data *data)
{
	
}
int handle_a(t_mlx_data *data)
{

}
int handle_s(t_mlx_data *data)
{

}
int handle_d(t_mlx_data *data)
{

} */
