/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:14:07 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/24 22:57:51 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_read(char **remaining, int fd)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	tmp = *remaining;
	if (!(*remaining = ft_strjoin(*remaining, buf)))
		return (-1);
	free(tmp);
	return (ret);
}

int		ft_one(char **remaining, char **line, char *s)
{
	char *tmp;

	*s = '\0';
	if (!(*line = ft_strdup(*remaining)))
		return (-1);
	tmp = *remaining;
	if (!(*remaining = ft_strdup(s + 1)))
		return (-1);
	free(tmp);
	return (1);
}

int		ft_zero(char **line, char **remaining, int fd)
{
	if (!(*line = ft_strdup(remaining[fd])))
		return (-1);
	free(remaining[fd]);
	remaining[fd] = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*remaining[OPEN_MAX];
	int			ret;
	char		*s;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (!remaining[fd])
		if (!(remaining[fd] = ft_strdup("")))
			return (-1);
	ret = BUFFER_SIZE;
	while (1)
	{
		s = remaining[fd];
		while (*s || ret < BUFFER_SIZE)
		{
			if (*s == '\n')
				return ((ft_one(&remaining[fd], line, s) == 1) ? 1 : -1);
			if (ret == 0 || *s == 0)
				return ((ft_zero(line, remaining, fd) == 0) ? 0 : -1);
			s++;
		}
		if ((ret = ft_read(&remaining[fd], fd)) == -1)
			return (-1);
	}
	return (0);
}
