/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:32:22 by mlima-si          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:31 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		i;
	char	*null;

	null = "(null)";
	i = 0;
	if (!str)
		str = null;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
