/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:39:57 by mlima-si          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:25 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	unsigned int	size;
	char			*base_low;
	char			*base_upper;

	size = 0;
	base_low = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (n >= 16)
		size += ft_puthexa(n / 16, c);
	if (c == 'x')
		write(1, &base_low[n % 16], 1);
	else
		write(1, &base_upper[n % 16], 1);
	return (++size);
}
