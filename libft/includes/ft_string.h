/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:03:40 by rnoriko           #+#    #+#             */
/*   Updated: 2022/01/30 23:06:22 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

int     ft_atoi(const char *str);
char	*ft_itoa(int nbr);
char	**ft_split(char const *s, char c);
char	*ft_strappendc(char *str, char c);
char	*ft_strchr(const char *s, int c);
int	    ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_free(char const *s1, char const *s2, int check);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *destination, const char *source, size_t dstsize);
size_t	ft_strlcpy(char *destination, const char *source, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strndup_move(const char *s, size_t n, char **target);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
void	ft_strskip(char **str, char *charset);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif