#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <stdio.h>

typedef struct	st_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				tt_img;

typedef struct s_mlx_data 
{
	void	*con;
	void	*win;
	void	*textures[5];
	//t_map	*map;
}			t_mlx_data;

typedef struct s_map
{
	/* data */
}			t_map;

int		main();
void	my_mlx_pixel_put(tt_img *data, int x, int y, int color);
int		handle_esc(int key,t_mlx_data *data);

#endif