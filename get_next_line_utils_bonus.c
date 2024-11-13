/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:22:12 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/13 15:43:05 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (unsigned char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ss1;

	if (!s1)
		return (NULL);
	ss1 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (ss1 == NULL)
		return (ss1 = NULL);
	i = 0;
	while (s1[i])
	{
		ss1[i] = s1[i];
		i++;
	}
	ss1[i] = '\0';
	return (ss1);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*dest;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!dest)
		return (NULL);
	start = dest;
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	return (start);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	size_src;
	size_t	i;

	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size_src);
}
