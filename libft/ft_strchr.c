/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:59:52 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/06 11:06:42 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index++;
	}
	if (str[index] == (char)c)
		return ((char *)&str[index]);
	return (NULL);
}
