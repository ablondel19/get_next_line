/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:04:11 by ablondel          #+#    #+#             */
/*   Updated: 2020/11/24 22:57:52 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int				get_next_line(int fd, char **line);
char			*ft_memzero(unsigned int size);
unsigned int	ft_len(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);

#endif
