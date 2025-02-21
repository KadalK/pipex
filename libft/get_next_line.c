/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kapinarc <kapinarc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:00 by kapinarc          #+#    #+#             */
/*   Updated: 2025/01/08 14:25:51 by kapinarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

void	ft_buffclean(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		str[j] = '\0';
		j++;
	}
	str[j] = 0;
}

int	is_line(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	clear_static(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		read_byte;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_byte = 1;
	line = ft_strdup_gnl(buffer);
	if (!line)
		return (NULL);
	while (read_byte && is_line(line) == 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (clear_static(buffer), free(line), NULL);
		buffer[read_byte] = '\0';
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (NULL);
	}
	ft_buffclean(buffer);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}
