/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:39:16 by mlima-si          #+#    #+#             */
/*   Updated: 2025/04/20 16:52:48 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_malloc(char **str, int pos, size_t size)
{
	int	i;

	i = 0;
	str[pos] = malloc(size);
	if (str[pos] == NULL)
	{
		while (i < pos)
		{
			free(str[i]);
			i++;
		}
		free(str);
		return (1);
	}
	return (0);
}

static int	allocate(char **str, char const *s, char c)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		if (len)
		{
			if (check_malloc(str, j, len + 1))
				return (1);
			ft_strlcpy (str[j], &s[i - len], len + 1);
		}
		j++;
	}
	return (0);
}

static int	arrays_count(const char *s, char c)
{
	int		i;
	size_t	total;
	int		boolean;

	i = 0;
	total = 0;
	while (s[i])
	{
		boolean = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (!boolean)
			{
				total++;
				boolean = 1;
			}
			i++;
		}
	}
	return (total);
}

char	**ft_split(char const *s, char c)
{
	size_t		num_str;
	char		**temp;

	if (!s)
		return (NULL);
	num_str = arrays_count(s, c);
	temp = malloc((num_str + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	temp[num_str] = NULL;
	if (allocate(temp, s, c))
		return (NULL);
	return (temp);
}
