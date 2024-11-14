/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:42:13 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/14 18:04:47 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int	ft_putnbr_hex(unsigned int num, int fd)
{
	char *hex;
	int count;
	
	hex = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_putnbr_hex(num / 16, fd);
	count += ft_putchar_fd(hex[num % 16], fd);
	return count;
}


int	ft_format(char type, va_list args)
{
	int count;

	count = 0;
	if (type == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (type == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (type == 'd')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (type == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else
		count += ft_putchar_fd(type, 1);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;
	
	va_start (args, format);
	count = 0;	
	
	while (*format)
	{
		if (*format == '%')
			count += ft_format(*(++format), args);
		else 
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end (args);
	return (count);
}

int	main()
{
	int count;

	count = ft_printf("Meu nome é %s\n", "Marieli");
	ft_printf("count has %d chars \n", count);
	
	count = printf("Meu nome é %s\n", "Marieli");
	printf("count has %d chars \n", count);
	
	return (0);
}
