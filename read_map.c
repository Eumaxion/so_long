#include "so_long.h"

char **read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;
	int		i;
	
	fd = open(path, O_RDONLY);
	if(fd == -1)
		return(NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
	}
	map = ft_split(holder_map, '\n');
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	free(holder_map);
	close(fd);
	return (map);
}
