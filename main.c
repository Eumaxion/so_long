/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:54:46 by mlima-si          #+#    #+#             */
/*   Updated: 2025/06/07 18:04:27 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

int main(){
	void	*mlx_conection;
	void	*mlx_window;

	mlx_conection = mlx_init();
	mlx_window = mlx_new_window(mlx_conection, 500, 500, "Hello World");

	mlx_loop(mlx_conection);
}
