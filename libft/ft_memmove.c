/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:40:35 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/02 12:41:01 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memmove(char *stash)
{
	size_t	i;
	size_t	nline;

	i = 0;
	nline = ft_strchr_n(stash) + 1;
	while (stash[i + nline] && nline)
	{
		stash[i] = stash[i + nline];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		stash[i] = '\0';
		i++;
	}
}
