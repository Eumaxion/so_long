#ifndef SO_LONG_H
#define SO_LONG_H

#define MALLOC_ERROR	1
#define WIDTH 			600
#define HEIGHT 			600

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "Libft/libft.h"
#include <stdio.h>


typedef struct	st_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		len;
	int		wid;
	int		endian;
}				tt_img;

typedef struct s_mlx_data 
{
	void	*con;
	void	*win;
	int		pos_x;
	int		pos_y;
	tt_img	img;
}			t_mlx_data;


/* typedef struct s_map
{
}			t_map; */

int		main(int argc, char *argv[]);
int		handle_args(char *arg);
void	my_mlx_pixel_put(tt_img *data, int x, int y, int color);
int		handle_esc(int key,t_mlx_data *data);
int 	handle_w(t_mlx_data *data);
int 	handle_a(t_mlx_data *data);
int 	handle_s(t_mlx_data *data);
int 	handle_d(t_mlx_data *data);
int		handle_key(int keysim, t_mlx_data *data);
int		render(t_mlx_data *data);

#endif