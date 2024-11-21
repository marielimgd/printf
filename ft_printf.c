/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:42:13 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/21 20:26:16 by marielidias      ###   ########.fr       */
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

int	ft_format(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (type == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (type == 'u')
		count += ft_putnbr_u(va_arg(args, unsigned int));
	else if (type == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(type);
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
		{
			count += ft_format(*(++format), args);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
