/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:41:22 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:41:25 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *line, char *stash)
{
	int		i;
	int		j;
	char	*str;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	str = malloc((ft_strlen(line) + ft_strlen(stash) + 1) * sizeof(char));
	if (str)
	{
		i = -1;
		j = -1;
		while (line[++i])
			str[i] = line[i];
		while (stash[++j])
			str[i + j] = stash[j];
		str[i + j] = '\0';
	}
	free(line);
	return (str);
}
