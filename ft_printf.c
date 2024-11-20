/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:42:13 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/20 17:21:35 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	char	digit;

	int (count) = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	digit = (n % 16);
	if (digit < 10)
		count += ft_putchar_fd(digit + '0', 1);
	else
	{
		if (uppercase)
			count += ft_putchar_fd(digit - 10 + 'A', 1);
		else
			count += ft_putchar_fd(digit - 10 + 'a', 1);
	}
	return (count);
}

int	ft_format(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (type == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (type == 'p')
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putnbr_hex(va_arg(args, unsigned long), 1);
	}
	else if (type == 'u')
		count += ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (type == '%')
		count += write(1, "%", 1);
	else
		count += ft_putchar_fd(type, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_format(*(++format), args);
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
