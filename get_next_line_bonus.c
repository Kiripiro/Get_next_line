/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:43:27 by atourret          #+#    #+#             */
/*   Updated: 2020/12/01 18:39:02 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_clean_line(char *new_line, char **line, int r)
{
	size_t	i;
	size_t	length;
	char	*tmp;
	
	length = ft_strlen(new_line);
	i = 0;
	while (new_line[i] && new_line[i] != '\n')
		i++;
	ft_putstr("a\n");
	if (i < length)
	{
		ft_putstr("b\n");
		*line = ft_substr(new_line, 0, i);
		tmp = ft_substr(&new_line[i + 1], 0, length);
		if (new_line)
			free(new_line);
		new_line = tmp;
	}
	else if (r == 0)
	{
		ft_putstr("c\n");
		*line = new_line;
		new_line = 0;
	}
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
		new_line[fd] = ft_strjoin(new_line[fd], buff);
		if (ft_strchr(buff, 10))
			break ;
	}
	new_line[fd] = ft_clean_line(new_line[fd], line, r);
	if (!new_line[fd])
		return (0);
	return (1);
}
/*
int		main()
{
	int		fd;
	char	*line;

	fd = open("gnlTester/files/41_with_nl", O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
}*/
