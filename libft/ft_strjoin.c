/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:04:21 by mmariano          #+#    #+#             */
/*   Updated: 2024/10/31 19:20:06 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	index;
	size_t	index_str;
	char	*new_str;

	index = 0;
	index_str = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(total_len);
	if (!new_str)
		return (NULL);
	while (s1[index])
		new_str[index_str++] = s1[index++];
	index = 0;
	while (s2[index])
		new_str[index_str++] = s2[index++];
	new_str[index_str] = '\0';
	return (new_str);
}
