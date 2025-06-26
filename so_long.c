/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:54:46 by mlima-si          #+#    #+#             */
/*   Updated: 2025/06/26 12:18:27 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_args(char *arg)
{
	int	size;

	size = ft_strlen(arg);
	if (size > 4)
	{
		if (arg[size - 1] == 'r' && arg[size - 2] == 'e' 
			&& arg[size - 3] == 'b' && arg[size - 4] == '.')
			return(1);
		else
			return(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	data;

	if (argc == 2)
	{
		data.tmap.map = read_map(argv[1]);
		if (handle_args(argv[1]) && check_map(&data))
		{
			printf("valid map\n");
			gather_elements(&data);
			render_map(&data);
			//mlx_loop_hook(data.mlx, );
			mlx_loop(data.mlx);
/* 			free_map(data.tmap.map);
			exit(1); */
		}
		else
		{
			if (data.tmap.map)
			{
				free_map(data.tmap.map);
				printf("invalid map freeing!");
				exit(1);
			}
			printf("invalid map not freeing.");
		}
	}
	else
	{
		printf("ERROR\n");
		exit(1);
	}
	return(0);
}
