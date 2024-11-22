/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:42:13 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/22 16:22:46 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_hex(ptr, 0);
	}
	return (count);
}

int	ft_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned long));
	else if (specifier == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (specifier == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(specifier);
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
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	format++;
	return (count);
}
