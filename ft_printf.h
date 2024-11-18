/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:35:48 by mmariano          #+#    #+#             */
/*   Updated: 2024/11/18 16:59:43 by mmariano         ###   ########.fr       */
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

typedef struct s_format
{
	//flags: +-''0#
	bool	plus;
	bool	left_just;
	bool	space;
	bool	hash;
	bool	zero_pad;	
	//specifier: cspdiuxX%
	char	specifier;
	//width: (number)*
	int		widht_value;
	//precision: .number.*
	int		precision_value;
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

int ft_printf(const char *format, ...);

#endif