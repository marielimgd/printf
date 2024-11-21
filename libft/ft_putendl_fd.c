/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:23:25 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/07 16:14:08 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	index;

	if (fd < 0)
		return ;
	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
	write((int)fd, "\n", 1);
}
