#include "so_long.h"

int check_map(t_game *data)
{
	if(is_rectangle(data->tmap.map) && is_surrounded_wall(data->tmap.map) && check_itens(data) && is_valid(data->tmap.map))
		return(1);
	return(0);
}
int is_rectangle(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (*map[i] != '\0')
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}
int is_surrounded_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (*map[i] != '\0')
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (*map[i] != '\0')
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
int check_itens(t_game *data)
{
	int i;
	int j;

	data->tmap.colect = 0;
	data->tmap.exit = 0;
	data->tmap.player = 0;
	i = 0;
	while (*data->tmap.map[i] != '\0')
	{
		j = 0;
		while(data->tmap.map[i][j] != '\0')
		{
			if (data->tmap.map[i][j] == 'P')
				data->tmap.player++;
			if (data->tmap.map[i][j] == 'E')
				data->tmap.exit++;
			if (data->tmap.map[i][j] == 'C')
				data->tmap.colect++;
			j++;
		}
		i++;
	}
	if(data->tmap.player != 1 || data->tmap.exit != 1 || data->tmap.colect == 0)
		return(0);
	return(1);
}
int is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (*map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
