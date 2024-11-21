/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:26:01 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/21 20:28:12 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num > 9)
		count += ft_putnbr(num / 10);
	count += ft_putchar('0' + (num % 10));
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	count += ft_putchar('0' + (n % 10));
	return (count);
}

int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	digit = (n % 16);
	if (digit < 10)
		count += ft_putchar(digit + '0');
	else
	{
		if (uppercase)
			count += ft_putchar(digit - 10 + 'A');
		else
			count += ft_putchar(digit - 10 + 'a');
	}
	return (count);
}
