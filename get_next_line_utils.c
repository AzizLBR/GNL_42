/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:17:42 by aloubar           #+#    #+#             */
/*   Updated: 2020/12/30 17:54:57 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int		ft_check_char(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

int		ft_free_exit(char **str, char **new_line)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (new_line && *new_line)
	{
		free(*new_line);
		*new_line = NULL;
	}
	return (-1);
}
