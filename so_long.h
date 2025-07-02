/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:55:52 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:20:34 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MALLOC_ERROR	1
# define WIDTH 			600
# define HEIGHT 			600
# define PIXS			50

# define KEY_ESC			65307
# define KEY_W			65362
# define KEY_A			65361
# define KEY_S			65364
# define KEY_D			65363

# define KEY_UP			119
# define KEY_LEFT		97
# define KEY_DOWN		115
# define KEY_RIGHT		100

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_colect;
	void	*img_exit;
	int		map_x;
	int		map_y;
	int		img_x;
	int		img_y;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			moves;
	int			endgame;
	int			colect;
	int			player;
	int			exit;
	void		*player_pose;
	int			player_x;
	int			player_y;
	t_map		t_map;
}			t_game;

int			main(int argc, char *argv[]);
int			handle_args(char *arg);
char		**read_map(char *path);
int			check_map(t_game *data);
int			is_rectangle(char **map);
int			is_surrounded_wall(char **map);
int			check_itens(t_game *data);
int			is_valid(char **map);
void		gather_elements(t_game *data);
void		free_map(char **map);
void		put_image(t_game *data, int x, int y);
void		create_player(t_game *data);
int			start_game(t_game *data);
void		update_player_img(char c, t_game *data);
int			handle_key(int keysim, t_game *data);
int			handle_esc(t_game *data);
int			handle_w(t_game *data);
int			handle_a(t_game *data);
int			handle_s(t_game *data);
int			handle_d(t_game *data);
int			render_map(t_game *data);
int			exit_game(t_game *data);

#endif