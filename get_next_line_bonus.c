/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:20:11 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/13 21:18:03 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer_line(char *str, int fd)
{
	ssize_t	l_buffer;
	char	*dest;
	char	*tmp;

	dest = malloc(BUFFER_SIZE + 1);
	if (!dest)
		return (free(str), NULL);
	l_buffer = 1;
	while (l_buffer != 0)
	{
		l_buffer = read(fd, dest, BUFFER_SIZE);
		if (l_buffer == -1)
			return (free(dest), free(str), NULL);
		dest[l_buffer] = '\0';
		tmp = ft_strjoin(str, dest);
		if (!tmp)
			return (free(dest), free(str), NULL);
		free(str);
		str = tmp;
		if (ft_strchr(dest, '\n'))
			break ;
	}
	free(dest);
	return (str);
}

char	*ft_line_in_buffer(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*remove_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(buffer) - i);
	if (!new_buffer)
		return (free(buffer), NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*buff;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (free(str[fd]), str[fd] = NULL);
	str[fd] = ft_buffer_line(str[fd], fd);
	if (!str[fd] || *str[fd] == '\0')
		return (free(str[fd]), str[fd] = NULL);
	buff = ft_line_in_buffer(str[fd]);
	if (!buff)
		return (free(str[fd]), str[fd] = NULL);
	str[fd] = remove_line(str[fd]);
	return (buff);
}
