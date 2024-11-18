/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:26:11 by zlee              #+#    #+#             */
/*   Updated: 2024/11/18 17:06:13 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*create_buffer(char *buffer, size_t size)
{
	buffer = ft_calloc(size, sizeof(char));
	return (buffer);
}

static char	*trim_buf(char *buffer, int pos)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (buffer[pos] != '\0')
		temp[i++] = buffer[pos++];
	free(buffer);
	return (temp);
}

static char	*trim_str(char *buffer, char *result)
{
	int		size;
	int		i;
	char	*temp_malloc;

	size = 0;
	i = -1;
	while (buffer[size] != '\n')
		size++;
	if (size == 0 & buffer[size] != '\n')
		return (NULL);
	temp_malloc = ft_calloc(size + 2, sizeof(char));
	while (++i <= size)
		temp_malloc[i] = buffer[i];
	temp_malloc[i] = '\0';
	result = ft_strjoin(result, temp_malloc);
	buffer = trim_buf(buffer, size);
	free(temp_malloc);
	return (result);
}

static char	*read_buffer(int fd, char *buffer)
{
	int		size;
	char	*result;

	result = ft_calloc(1, 1);
	if (*buffer == '\0')
		size = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(buffer, '\n'))
	{
		if (size == 0)
			break ;
		result = ft_strjoin(result, buffer);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strchr(buffer, '\n'))
		result = trim_str(buffer, result);
	if (size == 0)
		free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;

	result = NULL;
	if (read(fd, 0, 0) < 1)
		return (NULL);
	if (!buffer)
		buffer = create_buffer(buffer, BUFFER_SIZE + 1);
	result = read_buffer(fd, buffer);
	return (result);
}
