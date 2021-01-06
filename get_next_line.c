/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:13:26 by aloubar           #+#    #+#             */
/*   Updated: 2021/01/03 13:12:30 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strcat_line(char *str, char *buf)
{
	int i;
	int j;
	int len;
	char *new_line;

	j = -1;
	i = ft_strlen(str);
	len = ft_strlen(str) + ft_strlen(buf);
	if ((new_line = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (str)
		new_line = ft_strcpy(new_line, str);
	while (buf[++j])
		new_line[i + j] = buf[j];
	new_line [i + j] = '\0';
	free(str);
	return (new_line);
}

static char		*ft_next_line(char *str, int *end)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	i = 0;
	len = ft_check_char(str, '\n') - 1;
	if (len == 0)
		len = ft_check_char(str, '\0') - 1;
	if (len == 0)
		*end = (-1);
	if ((line = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char		*ft_line_after(char *str)
{
	int		total_len;
	int		f_line_len;
	int		i;
	char	*new_str;

	i = 0;
	f_line_len = ft_check_char(str, '\n');
	total_len = ft_strlen(str) - f_line_len;
	if ((new_str = malloc(sizeof(char) * (total_len + 1))) == NULL)
		return (NULL);
	new_str[total_len] = '\0';
	while (i < total_len)
	{
		new_str[i] = str[f_line_len + i];
		i++;
	}
	free(str);
	return (new_str);
}

static int		ft_end(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int				end;
	int				res;
	char			buf[BUFFER_SIZE + 1];
	char			*next_line;
	static char		*str;

	str = NULL;
	end = 0;
	if (fd < 0 || *line == NULL || read(fd, buf, BUFFER_SIZE) < 0)
		return (-1);
	while ((res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		if(str = ft_strcat_line(str, buf) == NULL)
			return (ft_free_exit(&str, NULL));
		if ((ft_check_char(buf, '\n')) != 0)
			break ;
	}
	if ((next_line = ft_next_line(str, &end)) == NULL)
		return (ft_free_exit(&str, NULL));
	else if ((str = ft_line_after(str)) == NULL)
		return (ft_free_exit(&str, &next_line));
	*line = next_line;
	if (end == -1)
		ft_end(&str);
	return (1);
}
