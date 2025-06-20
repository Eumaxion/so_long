#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (*map[i] != '\0')
	{
		free(map[i]);
		i++;
	}
	free(map);
}
