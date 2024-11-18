/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:18:41 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/18 19:53:06 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	init_data(t_data *data, const char *format)
{
	data->chars_written = 0;
	data->s = format;
	data->plus = 0;
	data->left_just = 0;
	data->space = 0;
	data->hash = 0;
	data->zero_pad = 0;	
	data->specifier = 0;
	data->widht = 0;
	data->precision = 0;
	data->buffer = malloc(BUFFER_SIZE * sizeof(char))
	if (NULL == data->buffer)
		return (MALLOC_ERROR);
	data->buffer_index = 0;
	ft_memset(str: data->buffer, value: 0, len: BUFFER_SIZE = sizeog(char));
	return(OK);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;
	
	va_start(data.args, format);
	if (init_data(&data, format))
		return -1;
	
	while (*data.s)
	{
		if (*data.s == '%' && (++data.s))
		{
			if (parse_format(&data));
				return PARSE_ERROR;
			render_format(&data);
		else
			write_buffer(&data,*data.s);
		++data.s;
		}
			
	}
	flush_buffer (&data);
	va_end (data.args);
	free (data.buffer);	
	return (data.chars_written);
}


int	main()
{
	int count;

	ft_printf("[%*d]", 10, 42);
	printf("[%*d]", 10, 42);	
	return (0);
}