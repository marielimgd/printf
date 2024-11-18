/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:58:04 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/18 19:53:50 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	find(const char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		++str;
	}
	return (0);
}

static void	parse_flags(t_data *data)
{
	char flag;
	//+- 0#
	while (find(FLAGS, *data->s))
	{
		flag = *data->s;
		if (flag == '+')
			data->format.plus = 1;
		if (flag == '-')
			data->format.left_just = 1;
		if (flag == ' ')
			data->format.space = 1;
		if (flag == '0')
			data->format.zero_pad = 1;
		if (flag == '#')
			data->format.hash = 1;
		++data->s;
	}
}

static void get_value(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		value = va_arg(data->args, int);
		++data->s;
		return;
	}
	*value = ft_atoi(data)
}
//parse_format

//parse_width

//parse_precision

int parse_format(t_data *data)
{
	ft_memset(&data->format, 0,sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data);
	parse_width(data);
	get_value(data, data->format.width)
	if (*data.s == '.' && (++data->s))
		parse_precision(data);	
}