#include "so_long.h"

void	my_mlx_pixel_put(tt_img *img, int x, int y, int color)
{
	char	*dst;
 	if (x < 0 || x >= img->len || y < 0 || y >= img->wid)
		return; 
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	handle_key(int keysim, t_mlx_data *data)
{

	if (keysim == XK_Escape)
		{
			mlx_destroy_window(data->con, data->win);
			mlx_destroy_display(data->con);
			free(data->con);
			exit(1);
		}
 	if (keysim == XK_w || keysim == XK_Up)
		handle_w(data);
	if (keysim == XK_a || keysim == XK_Left)
		handle_a(data);
	if (keysim == XK_s || keysim == XK_Down)
		handle_s(data);
	if (keysim == XK_d || keysim == XK_Right)
		handle_d(data);
	printf("Key: %d | Pos X: %d, Pos Y: %d\n", keysim, data->pos_x, data->pos_y);
	return (1);
}

int	render(t_mlx_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	memset(data->img.addr, 0, HEIGHT * data->img.line_length);
	mlx_clear_window(data->con, data->win);
	while(x < 20)
	{
		while(y < 20)
		{
			my_mlx_pixel_put(&data->img, x + data->pos_x, y + data->pos_y, 0x000010FF);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(data->con, data->win, data->img.mlx_img, 0, 0);
	mlx_do_sync(data->con);
	return(1);
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
