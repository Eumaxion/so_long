#include "so_long.h"

int is_rectangle(char *map[])
{
	int	i;

	i = 1;
	if (!map[0])
	{
		printf("Invalid void map.\n");
		return(0);
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			printf("Is not retangular...\n");
			return (0);
		}
		i++;
	}
	printf("Is retangular...\n");
	return (1);
}
int is_surrounded_wall(char *map[])
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
		{
			printf("First or last not surrounded by walls...\n");
			return (0);
		}
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
		{
			printf("Is NOT surrounded by walls...\n");
			return (0);
		}
		i++;
	}
	printf("Is surrounded by walls...\n");
	return (1);
}
int check_itens(t_game *data)
{
	int i;
	int j;

	data->colect = 0;
	data->exit = 0;
	data->player = 0;
	i = 0;
	while (data->tmap.map[i])
	{
		j = 0;
		while(data->tmap.map[i][j] != '\0')
		{
			if (data->tmap.map[i][j] == 'P')
				data->player++;
			if (data->tmap.map[i][j] == 'E')
				data->exit++;
			if (data->tmap.map[i][j] == 'C')
				data->colect++;
			j++;
		}
		i++;
	}
	if(data->player != 1 || data->exit != 1 || data->colect == 0)
	{
		printf("colecct: %d \n", data->colect);
		printf("exit: %d \n", data->exit);
		printf("player: %d \n", data->player);
		printf("theres a extra or faulting iten error.\n");
		return(0);
	}
	printf("No extra itens...\n");
	return(1);
}
int is_valid(char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' 
				&& map[i][j] != '0' && map[i][j] != '1')
			{
				printf("There's an irregular iten...\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	printf("No irregular itens...\n");
	return (1);
}
int check_map(t_game *data)
{
	int	i;
	int	j;

	if(is_rectangle(data->tmap.map) && is_surrounded_wall(data->tmap.map) && check_itens(data) && is_valid(data->tmap.map))
	{
		i = ft_strlen(data->tmap.map[0]);
		data->tmap.map_x = i - 1;
		while (data->tmap.map[0][j])
			j++;
		data->tmap.map_y = j - 1;
		return(1);
	}
	return(0);
}
