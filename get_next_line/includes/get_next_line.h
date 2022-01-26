/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:34:21 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/26 13:29:38 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	int			fd;
	char		*line;
	void		*next;
}				t_gnl;

int		get_next_line(int fd, char **line);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
size_t 	ft_strlen(const char *str);
char	*ft_strjoin_free(char const *s1, char const *s2, int check);
char	*ft_strjoin(char const *s1, char const *s2);

#endif