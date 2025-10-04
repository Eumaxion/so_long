/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignmb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:35:09 by mlima-si          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:34 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignmb(unsigned int n)
{
	int				total;
	unsigned int	number;

	total = 0;
	number = 0;
	if (n > 9)
		total += ft_putnmb(n / 10);
	number = ((n % 10) + '0');
	write(1, &number, 1);
	return (++total);
}
