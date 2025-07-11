/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:41:59 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:42:00 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	if (new_str)
	{
		while (i < ft_strlen(str))
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = 0;
		return (new_str);
	}
	return (0);
}
