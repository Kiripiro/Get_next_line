/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:43:58 by atourret          #+#    #+#             */
/*   Updated: 2020/12/01 18:10:16 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*res;

	if (!s1 && !s2)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1 != 0 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 != 0 && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free((void *)s1);
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (c == '\0')
	{
		while (str[i])
			i++;
		return ((char *)&str[i]);
	}
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[start] && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
