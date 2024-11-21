/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:07:26 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/01 13:46:59 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				len;
	char			*alpha;

	if (n < 0)
		num = -n;
	else
		num = n;
	len = ft_size(n);
	alpha = malloc(sizeof(char) * (len + 1));
	if (!alpha)
		return (NULL);
	alpha[len] = '\0';
	while (len--)
	{
		alpha[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		alpha[0] = '-';
	return (alpha);
}
