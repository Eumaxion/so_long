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

int	handle_args(char *arg)
{
	char	*str;
	int		cmp;

	str = ft_strchr(arg, '.');
	if (!str)
		return (1);
	cmp = ft_strcmp(str, "ber");
	return(cmp);
}

int	main(int argc, char *argv[])
{
	int i;
	t_game	data;

	if (argc == 2)
	{
		data.tmap.map = read_map(argv[1]);
		if (handle_args(argv[1]) && check_map(&data))
		{
			i = 0;
			while (data.tmap.map[i])
			{
				printf("%s", data.tmap.map[i]);
				i++;
			}
			free_map(&data.tmap.map);
			exit(1);
		}
		else
		{
			if (data.tmap.map)
			{
				free_map(&data.tmap.map);
				printf("invalid map.");
				exit(1);
			}
		}
	}
	else
	{
		printf("ERROR\n");
		exit(1);
	}
	return(0);
	/* data.pos_x = 0;
	data.pos_y = 0;

	data.con = mlx_init();
	if (!data.con)
		return (MALLOC_ERROR);
	data.win = mlx_new_window(data.con, WIDTH, HEIGHT, "Hello world!");
	if (!data.win)
	{
		free(data.con);
		return (MALLOC_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.con, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, 
									&data.img.bits_per_pixel, &data.img.line_length, 
									&data.img.endian);
	data.img.len = HEIGHT;
	data.img.wid = WIDTH;
	mlx_loop_hook(data.con, render, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop(data.con);
	mlx_destroy_image(data.con, data.img.mlx_img);
	return (0); */
}
