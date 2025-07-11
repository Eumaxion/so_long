/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:42:18 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:42:19 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strchr_n(const char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*release(char *line, char *stash)
{
	size_t	i;

	if (line)
		free(line);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		stash[i] = '\0';
		i++;
	}
	return (NULL);
}
