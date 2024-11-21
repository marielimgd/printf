/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marielidias <marielidias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:42:04 by marielidias       #+#    #+#             */
/*   Updated: 2024/11/07 09:02:36 by marielidias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	substr_count(const char *str, char c)
{
	int	count;
	int	substr;

	count = 0;
	substr = 0;
	while (*str)
	{
		if (*str != c && !substr)
		{
			substr = 1;
			count++;
		}
		else if (*str == c)
			substr = 0;
		str++;
	}
	return (count);
}

static char	*chop_substr(const char *str, int len)
{
	char	*substr;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str, len + 1);
	return (substr);
}

static void	free_str(char **str, int index)
{
	while (index--)
		free(str[index]);
	free(str);
}

static char	**write_substr(char **res_list, const char *str, char c)
{
	int	index;
	int	start;

	index = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		start = 0;
		while (str[start] && str[start] != c)
			start++;
		if (start > 0)
		{
			res_list[index] = chop_substr(str, start);
			if (!res_list[index])
			{
				free_str(res_list, index);
				return (NULL);
			}
			index++;
			str += start;
		}
	}
	res_list[index] = NULL;
	return (res_list);
}

char	**ft_split(char const *str, char c)
{
	char	**res_list;

	if (!str)
		return (NULL);
	res_list = ft_calloc((substr_count(str, c) + 1), sizeof(char *));
	if (!res_list)
		return (NULL);
	if (!write_substr (res_list, str, c))
		return (NULL);
	return (res_list);
}
