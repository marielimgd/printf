/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:05 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/06 11:38:11 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		index;

	str = (const char *)s;
	index = 0;
	while (index < n)
	{
		if (str[index] == (char)c)
			return ((void *)(str + index));
		index++;
	}
	return (NULL);
}
