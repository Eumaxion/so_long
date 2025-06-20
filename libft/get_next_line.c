/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:36 by mlima-si          #+#    #+#             */
/*   Updated: 2025/05/13 16:24:33 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(char *line, char *stash, int fd);
char	*set_line(char *line, char *stash);

char	*get_next_line(int fd)
{
	char		*line;
	static char	stash[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (stash[0])
		line = ft_strjoin(line, stash);
	if (ft_strchr_n(stash) >= 0)
		return (set_line(line, stash));
	line = read_line(line, stash, fd);
	if (!line)
		return (NULL);
	line = set_line(line, stash);
	return (line);
}

char	*read_line(char *line, char *stash, int fd)
{
	ssize_t	count;

	ft_memmove(stash);
	count = 1;
	while (1)
	{
		count = read(fd, stash, BUFFER_SIZE);
		if (count < 0)
			return (release(line, stash));
		if (count == 0)
			break ;
		line = ft_strjoin(line, stash);
		if (!line)
			return (NULL);
		if (ft_strchr_n(stash) >= 0)
			break ;
		ft_memmove(stash);
	}
	return (line);
}

char	*set_line(char *line, char *stash)
{
	int	nline;

	nline = ft_strchr_n(line);
	if (nline >= 0)
		line[nline + 1] = '\0';
	ft_memmove(stash);
	return (line);
}
