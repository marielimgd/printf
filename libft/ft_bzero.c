/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:02:40 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/06 09:20:20 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	while (len > 0)
	{
		*tmp = 0;
		tmp++;
		len--;
	}
	return (str);
}
