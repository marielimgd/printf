/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:35:48 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/18 19:47:03 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>

//Buffer of 4k
#define BUFFER_SIZE		(1<<12)

//Useful strings
#define FLAGS "+ 0-#"

typedef	enum
{
	OK = 0,
	MALLOC_ERROR = -1337,
	PARSE_ERROR = -42,
}		e_error;

typedef struct s_format
{
	int		plus;
	int		left_just;
	int		space;
	int		hash;
	int		zero_pad;	
	char	specifier;
	int		width;
	int		precision;
}				t_format;

typedef struct s_data
{
	//pointer to copy to format
	const char *s;
	//va_list ->
	va_list		args;
	int			chars_written;
	char		*buffer;
	int			*buffer_index;
	
	t_format	format;	
}				t_data;

int parse_format(t_data *data);
int ft_printf(const char *format, ...);

#endif