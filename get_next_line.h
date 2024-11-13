/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:26:08 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/13 21:17:30 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

char	*get_next_line(int fd);
char	*ft_next_line(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_line_in_buffer(char *str);
size_t	ft_strlen(const	char *str);
char	*ft_buffer_line(char *str, int fd);
char	*remove_line(char *buffer);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s1);

#endif