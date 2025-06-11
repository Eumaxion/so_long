/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:54:46 by mlima-si          #+#    #+#             */
/*   Updated: 2025/06/11 17:04:17 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MALLOC_ERROR 1
#define WIDTH 500
#define HEIGHT 500

int	handle_key(int keysim,t_mlx_data *data)
{

	if (keysim == XK_Escape)
		handle_esc(keysim, data);
/*  	if (keysim == 119 | 65362 ) //w
		handle_w(data);
	if (keysim == 97 || 65361) //a
		handle_a(data);
	if (keysim == 115 || 65364) //s
		handle_s(data);
	if (keysim == 100 || 65363) //d
		handle_d(data); */
	printf ("%d\n", keysim);
	return (0);
}


int	main(void)
{
	t_mlx_data	data;
	void *img;
	char *path = "avatar.xpm";
	int wi;
	int he;
	
	data.con = mlx_init();
	if (!data.con)
		return (MALLOC_ERROR);
	data.win = mlx_new_window(data.con, WIDTH, HEIGHT, "Hello world!");
	if (!data.win)
	{
		free(data.con);
		return (MALLOC_ERROR);
	}

	img = mlx_xpm_file_to_image(data.con, path, &wi, &he);
 	/* data.img.mlx_img = mlx_new_image(data.con, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bits_per_pixel, &data.img.line_length,
								&data.img.endian);
	for (int x = 30; x < 250; x++)
	{
		for (int y = 30; y < 250; y++)
			if (y % 2 == 0)
				my_mlx_pixel_put(&data.img, x, y, 0x000010FF);
	}*/
	mlx_put_image_to_window(data.con, data.win, &img, 0, 0);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop(data.con);
	mlx_destroy_display(data.con);
	free(data.con);
}
