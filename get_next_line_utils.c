/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:02:16 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/24 22:57:55 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_memzero(unsigned int len)
{
	char	*dst;

	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len)
		dst[--len] = '\0';
	return (dst);
}

unsigned int	ft_len(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char			*dst;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(dst = ft_memzero(ft_len(s1) + ft_len(s2))))
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}

char			*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	i = -1;
	if (!src)
		return (NULL);
	if (!(dst = malloc(sizeof(char) * (ft_len(src) + 1))))
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
