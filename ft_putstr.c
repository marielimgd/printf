/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:19:45 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/21 20:29:01 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	index;

	if (!str)
		return (ft_putstr("(null)"));
	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}
