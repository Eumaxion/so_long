#include "so_long.h"

void	my_mlx_pixel_put(tt_img *img, int x, int y, int color)
{
	char	*dst;
 	if (x < 0 || x >= img->len || y < 0 || y >= img->wid)
		return; 
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int handle_esc(int key,t_mlx_data *data)
{
	mlx_destroy_window(data->con, data->win);
	mlx_destroy_display(data->con);
	free(data->con);
	exit(1);
}

int handle_w(t_mlx_data *data)
{
	if (data->pos_y >= 10)
		data->pos_y -= 10;
}
int handle_a(t_mlx_data *data)
{
	if (data->pos_x >= 10)
		data->pos_x -= 10;
}
int handle_s(t_mlx_data *data)
{
	if (data->pos_y < data->img.len - 10)
		data->pos_y += 10;
}
int handle_d(t_mlx_data *data)
{
	if (data->pos_x < data->img.wid - 10)
		data->pos_x += 10;
}
