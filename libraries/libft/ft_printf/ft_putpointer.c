/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:01:27 by mlima-si          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:29 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbmr_size(unsigned long n);
static void	ft_print_p(unsigned long n);

int	ft_putpointer(unsigned long n)
{
	int				size;

	size = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	size = nbmr_size(n) + 2;
	write(1, "0x", 2);
	ft_print_p(n);
	return (size);
}

static int	nbmr_size(unsigned long n)
{
	int	size;

	size = 1;
	while (n / 16)
	{
		size++;
		n /= 16;
	}
	return (size);
}

static void	ft_print_p(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_print_p(n / 16);
	write(1, &base[n % 16], 1);
}
