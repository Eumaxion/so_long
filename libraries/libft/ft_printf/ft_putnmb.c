/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnmb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:57:21 by mlima-si          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:27 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnmb(int n)
{
	int	total;
	int	number;

	total = 0;
	number = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		total ++;
	}
	if (n > 9)
		total += ft_putnmb(n / 10);
	number = ((n % 10) + '0');
	write(1, &number, 1);
	return (++total);
}
