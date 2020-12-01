/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 10:58:29 by atourret          #+#    #+#             */
/*   Updated: 2020/12/01 16:44:26 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_line(char *new_line, char **line, int r)
{
	size_t	i;
	size_t	length;
	char	*tmp;

	length = ft_strlen(new_line);
	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	if (i < length)
	{
		*line = ft_substr(new_line, 0, i);
		tmp = ft_substr(new_line, i + 1, length);
		if (new_line)
			free(new_line);
		new_line = tmp;
	}
	else if (r == 0)
	{
		*line = new_line;
		new_line = 0;
	}
	return (new_line);
}

char	*ft_make_line(char *buff, char *new_line)
{
	char	*tmp;

	if (new_line)
	{
		tmp = ft_strjoin(new_line, buff);
		free(new_line);
		new_line = tmp;
	}
	else
		new_line = ft_strdup(buff);
	return (new_line);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*new_line[4096];
	int				r;

	while ((r = read(fd, &buff, BUFFER_SIZE)))
	{
		if (r == -1)
			return (-1);
		buff[r] = '\0';
		new_line[fd] = ft_make_line(buff, new_line[fd]);
		if (ft_strchr(buff, 10))
			break ;
	}
	if (r <= 0 && !new_line[fd])
	{
		*line = ft_strdup("");
		new_line[fd] = NULL;
		return (r);
	}
	new_line[fd] = ft_clean_line(new_line[fd], line, r);
	if (!new_line[fd])
		return (0);
	return (1);
}
