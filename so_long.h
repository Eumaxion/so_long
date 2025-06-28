#ifndef SO_LONG_H
#define SO_LONG_H

#define MALLOC_ERROR	1
#define WIDTH 			600
#define HEIGHT 			600
#define PIXS	50

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

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

typedef struct s_player
{
	void	*player_up;
	void	*player_down;
	void	*player_right;
	void	*player_left;
	void	*player_walk_l;
	void	*player_walk_r;
	int		player_x;
	int		player_y;
}			t_player;

typedef struct s_game 
{
	void		*mlx;
	void		*win;
	int			moves;
	int			endgame;
	int			colect;
	int			player;
	int			exit;
	t_map		tmap;
	t_player	t_player;
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
int			handle_key(int keysim, t_game *data);
int			handle_esc(t_game *data);
int			handle_w(t_game *data);
int			handle_a(t_game *data);
int			handle_s(t_game *data);
int			handle_d(t_game *data);
int			render_map(t_game *data);
int			exit_game(t_game *data);


/* void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	free_map(char **map); */

#endif